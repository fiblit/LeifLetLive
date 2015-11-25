#ifndef EVENTQUEUENODE_H
#define EVENTQUEUENODE_H

#include <climits>
#include <cassert>

#include "debug.hpp"

//an Event is just a pointer to a function which returns void and takes void
typedef void (*Event)();

typedef unsigned int Priority;
#define EVENT_PRIORITY_NOW 0
#define EVENT_PRIORITY_SOON 1 //Technically anything >1
#define EVENT_PRIORITY_HIGH 1
#define EVENT_PRIORITY_MEDIUM 10
#define EVENT_PRIORITY_LOW 100
#define EVENT_PRIORITY_DEAD UINT_MAX

//event queue needs to be known to exist in order to be a friend
class EventQueue;

//the nodes in an EventQueue
class EventQueueNode
{
	public:
		friend EventQueue;
		friend EventQueueNode *buildEventQueueNode();
		friend EventQueueNode *buildEventQueueNode(Event e, Priority p, EventQueueNode *next);

		~EventQueueNode();

		EventQueueNode *sink();
		void sinkSwap();

		Priority getPriority();
		void setPriority(Priority p);

		EventQueueNode *getNext();
		void setNext(EventQueueNode *nxt);
	private:
		EventQueueNode();
		EventQueueNode(Event e, Priority p, EventQueueNode *next);

		EventQueueNode *next;
		Priority priority;
		Event event;
};

#endif//EVENTQUEUENODE_H

