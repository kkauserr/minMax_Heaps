#include <iostream>
#include <stdexcept>
using namespace std;
template <typename T> class MinHeap
{
    private:
    T* arrayHeap;
    int cap;
    int currentSize;
    void MinHeapify(int ind)
    {
        int small=ind;
        int leftChild=2*ind+1;
        int rightChild= 2*ind+2;
        if(leftChild<currentSize && arrayHeap[leftChild]<arrayHeap[small])
        {
            small=leftChild;
        }
        if(rightChild<currentSize && arrayHeap[rightChild]<arrayHeap[small])
        {
            small=rightChild;
        }
        if (small!=ind)
        {
            int temp=arrayHeap[ind];
            arrayHeap[ind]=arrayHeap[small];
            arrayHeap[small]=temp;
            MinHeapify(small);
        }
    }
    public:
    MinHeap(){}
    MinHeap(int size)
    {
        this->cap=size;
        this->currentSize=0;
        this->arrayHeap=new T [cap];
    }
    ~MinHeap()
    {
        empty();
    }
    void enqueue(T newElement)
    {
        if(currentSize==cap)
        {
            throw range_error("Heap full");
        }
        currentSize++;
        arrayHeap[currentSize-1]= newElement;
        int curr = currentSize-1;
        while(curr>0 && arrayHeap[((curr-1)/2)]>arrayHeap[curr])
        {
            T temp = arrayHeap[((curr-1)/2)];
            arrayHeap[((curr-1)/2)]=arrayHeap[curr];
            arrayHeap[curr]=temp;
            curr=((curr-1)/2);
        }
    }
    void dequeue ()
    {
        if (isEmpty())
        {
            throw out_of_range("Attempted to delete but MinHeap is empty");
        }
        T rootVal=arrayHeap[0];
        arrayHeap[0]=arrayHeap[currentSize-1];
        currentSize--;
        MinHeapify(0);
    }
    T peek()
    {
        return arrayHeap[0];
    }
    int getSize()
    {
        return currentSize;
    }
    int getCapacity()
    {
        return cap;
    }
    bool isEmpty()
    {
        return (currentSize==0);
    }
      void empty()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }  
};