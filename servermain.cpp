#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <math.h>
#include"server.h"


#define SA struct sockaddr 
void test(int socket);
ssize_t read(int fs, void *buf, ssize_t N);
ssize_t write(int fs, const void *buf, size_t N);
int close(int socket);
void error (const char* s);
in_addr_t inet_addr(const char *cp);


int controlCalculation(int a, int b, const char* op)
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
double controlCalculationf(double a, double b, const char* op)
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
void send_protocols(char* protocls, int socket)
{
    char buff[64];
    char* protocol = "TEXT TCP";
    float ver = 1.0;
    snprintf(buff, sizeof(buff)-1, "%s %f", protocol, ver);
    write(socket, buff, sizeof(buff));
}

void sendIntegerData(int a, int b, const char* op, int socket)
{
    char buffer[64];
    snprintf(buffer, sizeof(buffer)-1, "%d,%d,%s", a, b, op);
    write(socket, buffer, sizeof(buffer));
}

void sendFloatingData(double a, double b, const char* op, int socket)
{
    char buffer[64];
    
    snprintf(buffer, sizeof(buffer), "%8.8g,%8.8g,%s", a, b, op);
    write(socket, buffer, sizeof(buffer));
}



void test(int socket)

{
    char buff[64]; 
    const char* op = randomType();
    int fori = 0;
    
    double resultf;
    int result;
     
    
    int i = 0;
    for (;;)
    {   
        
        switch(i)
        {
            case 0:
                send_protocols(NULL,socket);
                break;
            case 1:
                
                if (op[0] == 'f')
                {   
                    fori = 1;
                    double randNumf = randomFloat(); double randNum_1f = randomFloat();
                    resultf = controlCalculationf(randNumf, randNum_1f, op);
                    
                    sendFloatingData(randNumf, randNum_1f, op, socket);
                }
                else
                {   fori = 0;
                    int randNum = randomInt(); double randNum_1 = randomInt();
                    result = controlCalculation(randNum, randNum_1, op);
                    
                    sendIntegerData(randNum, randNum_1, op, socket);
                }
                
                break;
                
            case 2:
                
                if (fori == 0)
                {   
                    int t = atoi(buff);
                    if (t == result)
                        printf("OK\n");
                    else
                        printf("ERROR\n");
                }
                else
                {
                    double t = atof(buff);
                    if (fabs(t-resultf) < 0.000001)
                        printf("OK\n");
                    else
                        printf("ERROR\n");
                        
                }
                char* end = "Exit";
                write(socket, end, sizeof(end));
                close(socket);
                break;
            
        }
        
        if (i == 2)
            break;
        
        bzero(buff, sizeof(buff));
        
        if (i != 2)
        {
        
        //wait for confirmation
        for (;;)
        {
            read(socket, buff, sizeof(buff));
            if (strcmp(buff, "OK") == 0)
                break;
        }
        }
        printf("client sends : %s\n", buff);
    
        //wait for result
        if (i > 0)
        {
        
         for (;;)
        {
            read(socket, buff, sizeof(buff));
            if (strcmp(buff, "OK") != 0)
                break;
        }
        }
        
        printf("client sends : %s\n", buff);
        ++i;
    }
}


#include <calcLib.h>



using namespace std;


int main(int argc, char *argv[]){
  
 
  

}
