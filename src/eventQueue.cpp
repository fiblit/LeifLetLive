#include "eventQueue.hpp"

EventQueue *buildEventQueue()
{
	return new EventQueue;
}

EventQueue::~EventQueue()
{
	delete head;
}

bool EventQueue::hasEvents()
{
	return numEvents > 0;
}

void EventQueue::doNextEvent()
{
	assert(numEvents > 0);

	head->event();
	numEvents--;
	EventQueueNode *temp = head;
	head = head->next;
	temp->next = nullptr;//this is to prevent "delete temp" from deleting everything
	delete temp;
}

void EventQueue::addEvent(Event e, Priority p)
{
	EventQueueNode *newEvent = buildEventQueueNode(e, p, head);
	head = newEvent->sink();
	numEvents++;
}

EventQueue::EventQueue()
{
	head = nullptr;
	numEvents = 0;
}
