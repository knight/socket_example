#include <cstdlib>
#include <iostream>
#include <winsock.h>
#include "connection.h"
using namespace std;

int main() {
    Connection c = Connection();
    try {
    	c.connect("127.0.0.1", "80");
    	c.send("GET /\13\10");
    	cout << c.receive() << endl;

    } catch (MyException& e) {
    	cout << "Wystapil problem: " << endl;
    	cout << e.message << endl;

    }


    system("PAUSE");

    return EXIT_SUCCESS;
}
