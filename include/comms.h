#ifndef COMMS_H
#define COMMS_H

void initComms();
void connectToServer();
void sendToServer(const char* msg, size_t count);
void closeComms();

#endif /* end of include guard:  */
