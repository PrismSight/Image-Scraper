#include  "Network.h"
#define BUFFERSIZE 1024*500

Network::Network()
{
	//init winsock
	if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) return ;
}

Network::~Network()
{
	WSACleanup();
}

string Network::Browse(string URL = "/") // 10384
{
	struct sockaddr_in serveraddr;
	char *ipaddress = "104.20.43.57";
	int port = 443;

	//open socket
	if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)return string();

	//connect
	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(ipaddress);
	serveraddr.sin_port = htons((unsigned short)port);
	if (connect(sock, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)return string();





	string request;
	string response;
	int resp_leng;
	char buffer[BUFFERSIZE];

	request += "GET " + URL + " HTTP/1.1\r\n";
	request += "Host: 8ch.net\r\n\r\n";
	
	//send request
	if (send(sock, request.c_str(), request.length(), 0) != request.length())return string();

	//get response
	response = "";
	resp_leng = BUFFERSIZE;
	while (resp_leng == BUFFERSIZE)
	{
		resp_leng = recv(sock, (char*)&buffer, BUFFERSIZE, 0);
		if (resp_leng > 0)
			response += string(buffer).substr(0, resp_leng);
	}






	closesocket(sock);
	return response;
}