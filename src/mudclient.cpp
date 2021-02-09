#include <iostream>

#include "comms.h"

int main(int argc, char* argv[])
{
  initComms();
  connectToServer();
  closeComms();
}
