struct Element4
{
    int value;
    int priority;
};

class Heap
{
    private:
        unsigned int maxSize;
        unsigned int size;
        Element4* array;

        void heapifyUp(unsigned int);
        void heapifyDown(unsigned int);

    public:
        Heap(int);
        ~Heap();

        void push(int, int);
        int* getNext();
        void pop();

        bool isEmpty();
        bool isFull();
        unsigned int getSize();
};