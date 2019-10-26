struct Element
{
    Element* prev;

    int priority;
    int value;

    Element* next;
};

class PriorityQueue
{
    private:
        unsigned int size;
        Element* start;
        Element* end;

    public:
        PriorityQueue();
        PriorityQueue(int, int);
        ~PriorityQueue();

        void push(int, int);
        void pop();
        int* getNext();
        
        unsigned int getSize();
};