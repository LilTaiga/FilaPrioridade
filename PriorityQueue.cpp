#include "PriorityQueue.h"
#define NULL 0

PriorityQueue::PriorityQueue()
{
    size = 0;
    start = NULL;
    end = NULL;
}

PriorityQueue::PriorityQueue(int _value, int _priority)
{
    size = 1;

    start = new Element;
    
    start->next = NULL;
    start->prev = NULL;
    start->value = _value;
    start->priority = _priority;

    end = start;
}

PriorityQueue::~PriorityQueue()
{
    Element* current = end;

    while(current != start)
    {
        current = current->prev;
        delete current->next;
    }

    delete current;
}

void PriorityQueue::push(int _value, int _priority)
{
    if(size == 0)
    {
        size = 1;

        start = new Element;
        
        start->next = NULL;
        start->prev = NULL;
        start->value = _value;
        start->priority = _priority;

        end = start;

        return;
    }
     
    Element* current = start;
    while(current != NULL && current->priority > _priority)
        current = current->next;

    if(current == NULL)
    {
        current = end;

        current->next = new Element;
        current->next->prev = current;

        current = current->next;

        current->next = NULL;
        current->value = _value;
        current->priority = _priority;
        
        end = current;

        size++;
        return;
    }
    else if(current == start)
    {
        current->prev = new Element;
        current->prev->next = current;
        start = current->prev;

        start->priority = _priority;
        start->value = _value;
        start->prev = NULL;

        size++;
        return;
    }
    else
    {
        current->prev->next = new Element;
        current->prev->next->prev = current->prev;
        current->prev->next->next = current;
        current->prev = current->prev->next;

        current = current->prev;

        current->value = _value;
        current->priority = _priority;

        size++;
        return;
    }
    
}

void PriorityQueue::pop()
{
    if(size == 0)
        return;
    else if(size == 1)
    {
        delete start;
        start = NULL;
        end = NULL;
        size--;
        return;
    }
    else
    {
        start = start->next;
        delete start->prev;
        start->prev = NULL;
        return;
    }
}

int* PriorityQueue::getNext()
{
    if(size == 0)
        return NULL;

    return &(start->value);
}

unsigned int PriorityQueue::getSize()
{
    return size;
}