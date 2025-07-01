#pragma once
#include <bits/stdc++.h>
using namespace std;

// ANSI escape to reset terminal color
inline void resetColor()
{
          cout << "\033[0m";
}

// ANSI escape to set terminal foreground and background
inline void setColor(int fg, int bg = 0)
{
          cout << "\033[" << fg << ";" << bg << "m";
}

// sleep/pause for given milliseconds (cross-platform handled in .cpp)
void delay(int ms);
