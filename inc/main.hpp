#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstdio>
#include <cstdbool>
#include <clocale>

//#include <ncurses.h>
//#include <curses.h>
#include <ncursesw/curses.h>

#include "eventQueue.hpp"
#include "specialChars.hpp"
#include "debug.hpp"

bool gameShouldRun;

EventQueue *mainEventQueue;

void init();
void start();
void update();
void endGame();

void getCharInput();
void processCharInput( unsigned char nxtc );

#endif//MAIN_H

