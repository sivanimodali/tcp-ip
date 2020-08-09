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
  

}
