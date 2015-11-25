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

	setlocale(LC_ALL, "");//setup unicode locale

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
		#ifdef DEBUG
		printf("\n\rdebug 1\n\r");
		#endif
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
	mainEventQueue->addEvent(getCharInput, EVENT_PRIORITY_SOON);
}

void processCharInput( unsigned char nxtc )
{
	if (nxtc == EOF || nxtc == 27)//27 is ESCAPE
	{
		gameShouldRun = false;
		#ifdef DEBUG
		printf("\n\rdebug 3\n\r");
		#endif
	}	
	else
	{
		printf("%c",nxtc);
		mainEventQueue->addEvent(getCharInput, EVENT_PRIORITY_SOON);
		const wchar_t* wstr = spuc::black_diamond;
		addwstr(wstr);
		#ifdef DEBUG
		printf("\n\rdebug 4\n\r");
		#endif
	}
}

