#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h>
#include"client.h"
#include <calcLib.h>
#define SA struct sockaddr

ssize_t read(int fs, void *buf, ssize_t N);
ssize_t write(int fs, const void *buf, size_t N);
int close(int socket);
in_addr_t inet_addr(const char *cp);
void sendConfirmation(int socket)
{
    char buff[64];
    printf("Sending confirmation\n");
    snprintf(buff, sizeof(buff)-1, "%s", "OK");
    write(socket, buff, sizeof(buff));
}



void sendIntegerResult(int result, int socket)
{
    char buffer[64];
    snprintf(buffer, sizeof(buffer)-1, "%d", result);
    write(socket, buffer, sizeof(buffer));
}

void sendFloatingResult(double result, int socket)
{
    char buffer[64];
    
    snprintf(buffer, sizeof(buffer), "%8.8g", result);
    write(socket, buffer, sizeof(buffer));
}

  
 int calculateIntegerResult(int a, int b, const char* op)
{
    if (strcmp(op, "add") == 0)
    {
        return a+b;
    }
    
    if (strcmp(op, "div") == 0)
    {
        return a/b;
    }
    
    if (strcmp(op, "mul") == 0)
    {
        return a*b;
    }
    
    if (strcmp(op, "sub") == 0)
    {
        return a-b;
    }
    return -1;
} 
  
double calculateFloatingResult(double a, double b, const char* op)
{
    if (strcmp(op, "fadd") == 0)
    {
        return a+b;
    }
    
    if (strcmp(op, "fdiv") == 0)
    {
        return a/b;
    }
    
    if (strcmp(op, "fmul") == 0)
    {
        return a*b;
    }
    
    if (strcmp(op, "fsub") == 0)
    {
        return a-b;
    }
    
    return -1;
}
int main(int argc, char *argv[] ) 
{ 
    
    char* port;
    char* ip;
    const char delim[2] = ":";
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 
    
    
    if( argc == 2 ) {
        ip = strtok(argv[1], delim);
        port = strtok(NULL, delim);
    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied.\n");
        exit(0);
    }
    else {
        printf("One argument expected.\n");
        exit(0);
    }
    
    

    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(ip); 
    servaddr.sin_port = htons(atoi(port)); 
}
