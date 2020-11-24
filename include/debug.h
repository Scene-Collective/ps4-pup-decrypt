#ifndef __DEBUG_H__
#define __DEBUG_H__

#ifdef DEBUG_SOCKET
  #define printfsocket(format, ...)\
    do {\
      char __printfsocket_buffer[512];\
      int __printfsocket_size = sprintf(__printfsocket_buffer, format, ##__VA_ARGS__);\
      sceNetSend(sock, __printfsocket_buffer, __printfsocket_size, 0);\
    } while(0)
#endif

void notify(char* message);
uint8_t GetElapsed(uint64_t ResetInterval);

extern int sock;
extern time_t prevtime;

#define SSIZET_FMT "%zd"

#endif
