#include "utils.hpp"

#ifdef _WIN32
#include <windows.h> // check if code is compiled on windows
#else
#include <unistd.h>
#endif

void delay(int ms) // custom cross-platform abstraction
{
#ifdef _WIN32
          Sleep(ms);
#else
          usleep(ms * 1000);
#endif
}