#include <cstdlib>
#include <iostream>
#include <winsock.h>
#include "connection.h"
using namespace std;

int main() {
    Connection c = Connection();
//    try {
//    	c.connect("127.0.0.1", "80");
//    	c.send("GET /\13\10");
//    	cout << c.receive() << endl;
//
//    } catch (MyException& e) {
//    	cout << "Wystapil problem: " << endl;
//    	cout << e.message << endl;
//
//    }
	if (argc == 4) {

		if (0 == strcmp("k", argv[1])) {
			cout << "jestem klientem" << endl;
			cout << "lacze z " << argv[2] << argv[3] << endl;
			c.connect(argv[2], argv[3]);

		} else if (0 == strcmp("s", argv[1])) {
			cout << "jestem serwerem" << endl;
		}
	} else {
		cout << "Prawidłowe użycie: program.exe" << " {s|k} {IP} {PORT}" << endl;
	}
	return 0;

    system("PAUSE");

    return EXIT_SUCCESS;
}
