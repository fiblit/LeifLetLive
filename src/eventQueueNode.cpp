#include "eventQueueNode.hpp"

EventQueueNode *buildEventQueueNode()
{
	return new EventQueueNode();
}

EventQueueNode *buildEventQueueNode(Event e, Priority p, EventQueueNode *next)
{
	return new EventQueueNode(e, p, next);
}

//progress until next is greater or NULL
EventQueueNode *EventQueueNode::sink() 
{
	EventQueueNode *newHead = this;

	if ((this->next != nullptr) &&
		(this->priority >= this->next->getPriority()))
	{
		newHead = this->next;
		this->sinkSwap();
		this->sink();//need to keep sinking until smaller than child
	}

	return newHead;
}

EventQueueNode::~EventQueueNode()
{
	delete next;
}

void EventQueueNode::sinkSwap()
{
	#ifdef DOASSERT
	assert(this->next != nullptr);
	#endif

	EventQueueNode *tempNext = this->next;
	this->next = this->next->getNext();
	tempNext->setNext(this);
}

Priority EventQueueNode::getPriority()
{
	return priority;
}

void EventQueueNode::setPriority(Priority p)
{
	priority = p;
}

EventQueueNode *EventQueueNode::getNext()
{
	return next;
}

void EventQueueNode::setNext(EventQueueNode *nxt)
{
	next = nxt;
}

EventQueueNode::EventQueueNode()
{
	next = nullptr;
	priority = EVENT_PRIORITY_DEAD;
	event = nullptr;
}

EventQueueNode::EventQueueNode(Event e, Priority p, EventQueueNode *next)
{
	this->next = next;
	priority = p;
	event = e;
}

