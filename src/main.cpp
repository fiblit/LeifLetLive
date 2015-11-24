#include "main.hpp"

using namespace std;

int main()
{
	init();
	start();

	while(gameShouldRun)
	{
		update();
	}

	endGame();
	return 0;
}

void init()
{
	mainEventQueue = buildEventQueue();
	gameShouldRun = true;

	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
}

void start()
{
	mainEventQueue->addEvent(getCharInput, EVENT_PRIORITY_SOON);
}

void update()
{
	if(mainEventQueue->hasEvents())
	{
		mainEventQueue->doNextEvent();
		cout << "\ndebug 1\n";
		refresh();
	}
}

void endGame()
{
	delete mainEventQueue;
	endwin();
}

void getCharInput()
{
	processCharInput( getch() );
}

void processCharInput( unsigned char nxtc )
{
	if (nxtc == EOF || nxtc == 27)//27 is ESCAPE
	{
		gameShouldRun = false;
		printw("\ndebug 3\n");
	}	
	else
	{
		addch(nxtc);
		mainEventQueue->addEvent(getCharInput, EVENT_PRIORITY_SOON);
		printw("\ndebug 4\n");
	}
}

