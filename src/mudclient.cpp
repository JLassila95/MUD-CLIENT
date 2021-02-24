#include <cstdio>
#include <cstring>
#include <iostream>

#include "comms.h"

using namespace std;

int main(int argc, char* argv[])
{
  initComms();
  connectToServer();
  char buff[256];
  bool end = false;
  while(!end)
  {
    memset(buff, 0, sizeof(buff));
    scanf("%s", buff);
    buff[255] = '\0';
    if(strcmp(buff, "quit\0") == 0)
    {
      end = true;
    }
    sendToServer(buff, sizeof(buff));
  }
  closeComms();
}
