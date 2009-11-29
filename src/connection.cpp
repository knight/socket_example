#include "connection.h"
#include <winsock.h>
#include <sys/types.h>
#include <iostream>


Connection::Connection(): mSocket(-1)
{
  initWinSock();
  initSocket();
}

void Connection::initWinSock()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(1,1);
	int network_ready = !WSAStartup(wVersionRequested, &wsaData);
	if (0==network_ready) {
		MyException e;
		e.message = "Nie udalo sie podniesc sieci";
		throw e;
	}

}
void Connection::initSocket()
{
    mSocket = socket(PF_INET,SOCK_STREAM, getprotobyname("tcp")->p_proto);
    mSin.sin_family = AF_INET;
}

void Connection::connect(char *host, char *port)
{
	initHost(host);
	initPort(port);
	initConnection();
}
void Connection::initHost(char *ip) {
    
    mSin.sin_addr.s_addr = inet_addr(ip);
    if (INADDR_NONE == mSin.sin_addr.s_addr) {
       mPhe = gethostbyname(ip);
       if (mPhe) {
    	   copyIp();
       } else {
    	   MyException e;
    	   e.message = "Nie udalo sie odnalezc hosta";
    	   throw e;
       }
    }
}
void Connection::copyIp()
{
    char * p1 = (char*) & mSin.sin_addr.s_addr;
    char * p2 = (char*) & mPhe->h_addr[0];
    for (unsigned int i=0 ; i < sizeof(mSin.sin_addr.s_addr); ++i) {
              p1[i] = p2[i];
          }
}
void Connection::initPort(char *port)
{
    if (NULL == (mPse = getservbyname(port, ""))) {
       mSin.sin_port = htons(atoi(port));
    } else {
       mSin.sin_port =  mPse->s_port;
    }
}
void Connection::initConnection()
{
	int result = ::connect(mSocket, (struct sockaddr *)&mSin, sizeof(mSin));
	if (0!=result) {
		MyException e;
		e.message = "nieprawidlowy adres";
		throw e;
	}
}
void Connection::send(char * command) {
	::send(mSocket, command, strlen(command),0);
}

char *Connection::receive()
{
	return "";
}
Connection::~Connection() {
	closesocket(mSocket);
	WSACleanup();

	std::cout << "Koniec zabawy z winszokiem" << std::endl;
}
