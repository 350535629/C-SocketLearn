#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<winsock.h>

#define SERVPORT 80000
#define BACKLOG 10

void main()
{

    int sockfd,client_fd;

    struct sockaddr_in my_addr;
    struct sockaddr_in remote_addr;
    char * msg = "You are Welcome!\n"
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket error!");
        exit(1);
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SERVPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(my_addr.sin_zero),0,8);

    if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr))== -1)
    {
        printf("bind error");
        exit(1);
    }

    if(listen (sockfd,BACKLOG)== -1)
    {
        printf("listren error");
        exit(1);
    }

    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);

        if((client_fd = accept(sockfd,(struct sockaddr *)&remote_addr,&sin_size))==-1)
        {
            printf("accept error");
            continue;
        }
        if(send(client_fd,msg,strlen(msg),0)==-1)
        {
            printf("send error");
            close(client_fd);
            exit(0);
        }
        close(client_fd);
    }
}
