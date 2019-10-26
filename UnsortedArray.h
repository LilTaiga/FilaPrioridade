struct Element2
{
    int value;
    int priority;
};

class UnsortedArray
{
    private:
        unsigned int maxSize;
        unsigned int size;
        Element2* array;
    
    public:
        UnsortedArray(int);
        ~UnsortedArray();

        bool push(int, int);
        void pop();
        int* getNext();

        bool isEmpty();
        bool isFull();
        unsigned int getSize();
};