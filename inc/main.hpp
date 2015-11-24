#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <cstdio>
#include <cstdbool>

#include <curses.h>

#include "eventQueue.hpp"

bool gameShouldRun;

EventQueue *mainEventQueue;

void init();
void start();
void update();
void endGame();

void getCharInput();
void processCharInput( unsigned char nxtc );

#endif//MAIN_H

