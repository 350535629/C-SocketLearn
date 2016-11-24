#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<winsock.h>

#define SERVPORT 8000
#define MAXDATASIZE 100

void main(int argc,char *argv[])
{
    int sockfd,recvbytes;
    char buf[MAXDATASIZE] = {0};
    struct hostent *host;
    struct sockaddr_in serv_addr;
    if (argc<2)
    {
        printf(stderr,"Please enter the server's hostname!\n");
        exit(1);
    }

    if((host=gethostbyname(argv[1]))==NULL)
    {
        printf("gethostbyname error");
        exit(1);
    }

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))==-1)
    {
        printf("socket error");
        exit(1);
    }

    serv addr.sin family = AF_INET;
    serv addr.sin port = htons(SERVPORT);
    serv addr.sin addr = *((struct in_addr *)host->h_addr);
    memset(&(serv addr.sin zero),0,8);

    if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1)
    {
        printf("connect error");
        exit(1);
    }

    if((recvbytes = recv(sockfd,buf,MAXDATASIZE , 0))==-1)
    {
        printf("recv error");
        exit(1);
    }
    buf[recvbytes] = '\0';
    printf("Received : %s",buf);
    close(sockfd);
}
