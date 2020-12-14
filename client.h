#ifndef CLIENT_H_
#define CLIENT_H_
#include"calcLib.h"

void sendConfirmation(int socket);
int calculateIntegerResult(int a, int b, const char* op);
double calculateFloatingResult(double a, double b, const char* op);


#endif 
