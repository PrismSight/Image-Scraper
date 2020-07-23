#include <winsock.h>
#include <string>
using namespace std;

class Network
{
	int sock;
	WSADATA wsaData;
public:
	Network();
	~Network();
	string Browse(string);
};