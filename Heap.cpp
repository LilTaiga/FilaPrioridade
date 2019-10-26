#include "Heap.h"

Heap::Heap(int _size)
{
    maxSize = _size;
    size = 0;
    array = new Element4[maxSize];
}

Heap::~Heap()
{
    delete[] array;
}

void Heap::heapifyUp(unsigned int _index)
{
    unsigned int child = _index;
    unsigned int parent = (child - 1) / 2;

    if(child > 0 && array[parent].priority >= array[child].priority)
        return;

    //swap
    {

        Element4 temp = array[parent];
        array[parent] = array[child];
        array[child] = temp;
    }

    heapifyUp(parent);
}

void Heap::heapifyDown(unsigned int _index)
{
    unsigned int parent = _index;
    unsigned int child = parent * 2 + 1;

    if(child >= size)
        return;

    if(child + 1 < size && array[child].priority < array[child + 1].priority)
        child++;

    if(array[parent].priority >= array[child].priority)
        return;

    //swap
    {
        Element4 temp = array[parent];
        array[parent] = array[child];
        array[child] = temp;
    }

    heapifyDown(child);
}

void Heap::push(int _value, int _priority)
{
    if(isFull())
        return;
    
    array[size].value = _value;
    array[size].priority = _priority;

    heapifyUp(size);
    size++;
}

int* Heap::getNext()
{
    if(isEmpty())
        return 0;       //NULL

    return &(array[0].value);
}

void Heap::pop()
{
    if(isEmpty())
        return;

    array[0] = array[size - 1];
    size--;

    heapifyDown(0);
}

bool Heap::isFull()
{
    if(size == maxSize)
        return true;
    else
        return false;
}

bool Heap::isEmpty()
{
    if(size == 0)
        return true;
    else
        return false;
}

unsigned int Heap::getSize()
{
    return size;
}
