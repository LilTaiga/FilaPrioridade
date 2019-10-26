struct Element3
{
    int value;
    int priority;
};

class SortedArray
{
    private:
        unsigned int maxSize;
        unsigned int size;
        Element3* array;
    
    public:
        SortedArray(int);
        ~SortedArray();

        bool push(int, int);
        void pop();
        int* getNext();

        bool isEmpty();
        bool isFull();
        unsigned int getSize();
};