
#ifndef CONNECTION_H
#define CONNECTION_H
#include <winsock.h>
class MyException {
public:
	char * message;
};
class Connection
{
	public:
		Connection();
		
		virtual ~Connection();

		void mySend();
		void connect(char * host, char * port);
		char * receive();
		void send(char * command);


	private:

		int mSocket;
		struct sockaddr_in mSin;
		struct hostent * mPhe;
		struct servent * mPse;

		void initWinSock();
        void initSocket();
        void initHost(char *host);
        void initPort(char *port);
		void initConnection();
};
#endif // CONNECTION_H
