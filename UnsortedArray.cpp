#include "UnsortedArray.h"

UnsortedArray::UnsortedArray(int _size)
{
    maxSize = _size;
    size = 0;

    array = new Element2[_size];
}

UnsortedArray::~UnsortedArray()
{
    delete[] array;
}

bool UnsortedArray::push(int _value, int _priority)
{
    if(size == maxSize)
        return false;

    array[size].value = _value;
    array[size].priority = _priority;

    size++;
    return true;
}

void UnsortedArray::pop()
{
    if(size == 0)
        return;
    else if(size == 1)
    {
        size--;
        return;
    }

    for(int i = 0; i < size - 1; i++)
        array[i] = array[i + 1];

    size--;
}

int* UnsortedArray::getNext()
{
    if(size == 0)
        return 0;       //NULL
    
    return &(array[0].value);
}

bool UnsortedArray::isEmpty()
{
    if(size == 0)
        return true;
    else
        return false;
}

bool UnsortedArray::isFull()
{
    if(size == maxSize)
        return true;
    else
        return false;
}

unsigned int UnsortedArray::getSize()
{
    return size;
}