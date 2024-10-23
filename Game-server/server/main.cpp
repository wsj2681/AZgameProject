#include <SFML/Network.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    cout << "Start Network server" << endl;

    TcpListener listener;

    if(listener.listen(53000) != Socket::Done)
    {
        cerr << "fail port binding" << endl;
        return -1;
    }

    cout << "Waiting Client..." << endl;

    TcpSocket client;

    if(listener.accept(client) != Socket::Done)
    {
        cerr <<"Fail Client Connetion" << endl;
        return -1;
    }

    cout << "Success Client Connection" << endl;

    // 여러 번 메시지 수신 처리
    while (true) {
        char buffer[128];
        std::size_t received;
        
        sf::Socket::Status status = client.receive(buffer, sizeof(buffer), received);
        if (status == sf::Socket::Done) {
            std::string message(buffer, received);
            std::cout << "클라이언트로부터 받은 메시지: " << message << std::endl;

            // 클라이언트에 응답
            std::string reply = "서버로부터 응답: " + message;
            if (client.send(reply.c_str(), reply.size()) != sf::Socket::Done) {
                std::cerr << "응답 전송에 실패했습니다." << std::endl;
            }
        } else if (status == sf::Socket::Disconnected) {
            std::cout << "클라이언트가 연결을 끊었습니다." << std::endl;
            break;
        }
    }

    return 0;
}