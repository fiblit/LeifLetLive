#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include "eventQueueNode.hpp"
#include <cassert>

//Okay... should be a PQ, but it is just an ordered queue
class EventQueue
{
	public:
		//factory that returns a pointer from the constructor rather than a direct object
		friend EventQueue *buildEventQueue();

		~EventQueue();

		//are there events to do?
		bool hasEvents();

		//will execute next event
		void doNextEvent();

		//add event e with priority p
		void addEvent(Event e, Priority p);
	private:
		EventQueue();
		
		unsigned int numEvents;
		EventQueueNode *head;
};

EventQueue *buildEventQueue();

#endif//EVENTQUEUE_H

