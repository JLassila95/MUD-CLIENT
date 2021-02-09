//C and C++ library includes
#include <cstdlib>
#include <cstdio>

//Linux includes
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//User includes
#include "constants.h"

using namespace std;

static int conn;

void initComms()
{
  //Create socket
  conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if(conn < 0)
  {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }
}

void closeComms()
{
  if(close(conn) < 0)
  {
    perror("Failed to close connection socket");
  }
}

void connectToServer()
{
  sockaddr_in srv_addr;
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons( PORT );
  if(inet_pton(AF_INET, SERVER_ADDRESS, &srv_addr.sin_addr) <= 0)
  {
    perror("Invalid address");
    exit(EXIT_FAILURE);
  }
  if( connect(conn, (sockaddr*) &srv_addr, sizeof(srv_addr)) < 0 )
  {
    perror("Failed to connect to the server");
    exit(EXIT_FAILURE);
  }
}
