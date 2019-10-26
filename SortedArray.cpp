#include "SortedArray.h"

SortedArray::SortedArray(int _size)
{
    maxSize = _size;
    size = 0;

    array = new Element3[_size];
}

SortedArray::~SortedArray()
{
    delete[] array;
}

bool SortedArray::push(int _value, int _priority)
{
    if(size == maxSize)
        return false;

    if(size == 0)
    {
        array[0].value = _value;
        array[0].priority = _priority;

        size++;
        return true;
    }

    for(int i = 0; i < size; i++)
    {
        if(_priority <= array[i].priority)
            continue;
        else
        {
            for(int j = maxSize - 1; j >= i; j--)
            {
                array[j + 1] = array[j];

                if(j == i)
                {
                    array[j].value = _value;
                    array[j].priority = _priority;

                    size++;
                    return true;
                }
            }
        }
    }
}

void SortedArray::pop()
{
    if(size == 0)
        return;
    else if(size == 1)
    {
        size--;
        return;
    }

    for(int i = 0; i < size; i++)
        array[i] = array[i + 1];

    size--;
}

int* SortedArray::getNext()
{
    if(size == 0)
        return 0;       //NULL

    return &(array[0].value);
}

bool SortedArray::isEmpty()
{
    if(size == 0)
        return true;
    else
        return false;
}

bool SortedArray::isFull()
{
    if(size == maxSize)
        return true;
    else
        return false;
}

unsigned int SortedArray::getSize()
{
    return size;
}