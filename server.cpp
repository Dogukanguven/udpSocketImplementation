#include <cstring>
#include <iostream>
#include <arpa/inet.h>

using namespace std;

int main(){
    int socketFD;
    char buffer[512];

    struct sockaddr_in serverAddress, clientAddress;
        
    // Soketin oluşturulması.
    socketFD = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&serverAddress, 0, sizeof(serverAddress));
    memset(&clientAddress, 0, sizeof(clientAddress));
        
    // Server bilgilerinin belirlenmesi.
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(3976);

    // Soketin sunucuya bağlanması.
    bind(socketFD, (struct sockaddr*) &serverAddress, sizeof(serverAddress));

    // Mesaj bekleme işlemi.
    cout << "\nSunucu baslatildi.\n" << endl;
    while(true){
        socklen_t len;
        len = sizeof(clientAddress);

        int msgSize;
        msgSize = recvfrom(socketFD, buffer, 512, MSG_WAITALL, (struct sockaddr*) &clientAddress, &len);

        buffer[msgSize] = '\0';
        cout << "Sunucu Aldi: " << buffer << endl;
    }

    return 0;
}