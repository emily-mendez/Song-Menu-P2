#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <vector>
using namespace std;

struct Data {
    int listeningTime;
    int vectorIndex;
    Data(int t, int i) : listeningTime(t), vectorIndex(i) {}
};

class MaxHeap {
    private:
        int size = 0;
        vector<Data> arr = {Data(-1, -1)};
        int parent(int i) {
            return i>>1; // i /2
        }
        int left(int i) {
            return i<<1;
        }
        int right(int i) {
            return (i<<1) + 1;
        }

    public:
        bool isEmpty();
        int getMax();
        void insertItem(int val, int i);
        void percolateUp(int i);
        void percolateDown(int i);
        int extractMax();
        int getSize() const;
        int getValue(int i);
        void setValue(int i, int val);
        void printHeap();
        void removeMax();
        void updateIndices(unsigned int i);
        Data getObject(int i);
};

#endif
