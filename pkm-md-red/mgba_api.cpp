#include "mgba_api.hpp"

#include <format>
#include <iostream>
#include <ws2tcpip.h>

bool mgba_api::init_socket()
{
    // WSAStartup aufrufen, um Winsock zu initialisieren
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Fehler beim Initialisieren von Winsock." << std::endl;
        return false;
    }

    // Socket erstellen
    this->m_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->m_server_fd == INVALID_SOCKET) {
        std::cerr << "Fehler beim Erstellen des Sockets." << std::endl;
        WSACleanup();
        return false;
    }

    // Serverinformationen einstellen
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons( this->m_port );  // Port des Servers
    serverAddr.sin_addr.s_addr = INADDR_ANY;  // Jede verfügbare IP-Adresse

    // Socket an Port binden
    if (bind(this->m_server_fd, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Fehler beim Binden des Sockets." << std::endl;
        closesocket(this->m_server_fd);
        WSACleanup();
        return false;
    }

    return true;
}


bool mgba_api::wait_for_connection()
{
    // Socket für eingehende Verbindungen öffnen
    if (listen(this->m_server_fd, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Fehler beim Öffnen des Sockets für eingehende Verbindungen." << std::endl;
        closesocket(this->m_server_fd);
        WSACleanup();
        return false;
    }

    std::cout << "Server wartet auf Verbindungen..." << std::endl;

    // Auf eingehende Verbindung warten
    sockaddr_in clientAddr;
    int clientAddrSize = sizeof(clientAddr);

    this->m_client_fd = accept(this->m_server_fd, reinterpret_cast< sockaddr* >( &clientAddr ), &clientAddrSize);
    if (this->m_client_fd == INVALID_SOCKET) {
        std::cerr << "Fehler beim Akzeptieren der Verbindung." << std::endl;
        closesocket(this->m_server_fd);
        WSACleanup();
        return false;
    }

    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, sizeof(clientIP));
    std::cout << "Verbindung hergestellt mit Client: " << clientIP << std::endl;

    return true;
}

std::string mgba_api::recv_message()
{
    // Nachricht vom Client empfangen
    char buffer[1024];
    int bytesReceived = recv(this->m_client_fd, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        std::cout << "Nachricht vom Client: " << buffer << std::endl;
    }

    return { buffer };
}

void mgba_api::send_message( const std::string& msg )
{
    send(this->m_client_fd, msg.c_str(), msg.size(), 0);
}


bool mgba_api::release_socket()
{
    // Socket schließen und Winsock aufräumen
    closesocket(this->m_client_fd);
    closesocket(this->m_server_fd);
    WSACleanup();

    return true;
}

uint8_t mgba_api::read8( const std::uintptr_t address )
{
    this->send_message(std::vformat("READ8 {:x}", std::make_format_args(address)));

    const auto value = this->recv_message();

    return std::atoi(value.c_str());
}

uint16_t mgba_api::read16( const std::uintptr_t address )
{
    this->send_message(std::vformat("READ16 {:x}", std::make_format_args(address)));

    const auto value = this->recv_message();

    return std::atoi(value.c_str());
}

uint32_t mgba_api::read32( const std::uintptr_t address )
{
    this->send_message(std::vformat("READ32 {:x}", std::make_format_args(address)));

    const auto value = this->recv_message();

    return std::atoi(value.c_str());
}

bool mgba_api::write8( const std::uintptr_t address, const uint8_t value )
{
    this->send_message(std::vformat("WRITE8 {:x} {}", std::make_format_args(address, value)));

    return this->recv_message() == "OK";
}

bool mgba_api::write16( const std::uintptr_t address, const uint16_t value )
{
    this->send_message(std::vformat("WRITE16 {:x} {}", std::make_format_args(address, value)));

    return this->recv_message() == "OK";
}

bool mgba_api::write32( const std::uintptr_t address, const uint32_t value )
{
    this->send_message(std::vformat("WRITE32 {:x} {}", std::make_format_args(address, value)));

    return this->recv_message() == "OK";
}