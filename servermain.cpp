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

#include <calcLib.h>



using namespace std;


int main(int argc, char *argv[]){
  
 
  

}
