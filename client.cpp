#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
    int socketFD;
    char buffer[512];
    srand(time(NULL));

    struct sockaddr_in serverAddress;

    // Soketin oluşturulması.
    socketFD = socket(AF_INET, SOCK_DGRAM, 0);
    memset(&serverAddress, 0, sizeof(serverAddress));

    // Server bilgilerinin belirlenmesi.
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(3976);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Mesaj gönderme işlemi.
    char *charMsg;
    string msg;

    for (int i = 0; i < 100; i++){
        msg = to_string(i) + " - " + to_string(rand() % 1000000);
        charMsg = (char*) msg.c_str();

        socklen_t len;
        len = sizeof(serverAddress);

        sendto(socketFD, charMsg, msg.size(), MSG_CONFIRM, (struct sockaddr*) &serverAddress, len);
        cout << "Istemci Gonderdi: " << msg << endl;

        sleep(1);
    }

    // Soketin kapatılması.
    close(socketFD);
    return 0;
    }