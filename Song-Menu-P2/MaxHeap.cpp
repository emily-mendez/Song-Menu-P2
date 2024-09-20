#include "MaxHeap.h"
#include "Song.h"

extern vector<Song> songList;

bool MaxHeap::isEmpty() {
    return (size==0);
}

int MaxHeap::getMax() {
    return arr[1].listeningTime;
}

void MaxHeap::updateIndices(unsigned int i) {
  for(; i < songList.size(); i++) {
    (arr[songList.at(i).getHeapIndex()].vectorIndex)++;
  }
}

//struct
void MaxHeap::percolateUp(int i) { //i is the index of the element
    if(i > size) {
        return;
    }
    if(i == 1) {
        return;
    }
    if(arr[i].listeningTime > arr[parent(i)].listeningTime) {
        songList[arr[parent(i)].vectorIndex].setHeapIndex(i);
        songList[arr[i].vectorIndex].setHeapIndex(parent(i));
        swap(arr[parent(i)], arr[i]);
    }
    percolateUp(parent(i));
}

//struct
void MaxHeap::insertItem(int val, int i) {
    if(static_cast<unsigned int>(size) + 1 >= arr.size()) {
        arr.push_back(Data(0, i));
	size++;
    } else {
	size++;
	arr.insert(arr.begin() + size, Data(val, i));
	for(unsigned int j = size + 1; j < arr.size(); j++) {
	  songList[arr[j].vectorIndex].setHeapIndex(j);
        }
    }
    percolateUp(size); //shift up element to proper place (val is currently at index size)
}

//struct
void MaxHeap::percolateDown(int i) { //i is the index of the element
    if(i > size) {
        return;
    }
    int swapId = i;
    if(left(i) <= size && arr[i].listeningTime < arr[left(i)].listeningTime) {
        swapId = left(i);
    }
    if(right(i) <= size && arr[swapId].listeningTime < arr[right(i)].listeningTime) {
        swapId = right(i);
    }

    if(swapId != i) {
        songList[arr[swapId].vectorIndex].setHeapIndex(i);
        songList[arr[i].vectorIndex].setHeapIndex(swapId);
        swap(arr[i], arr[swapId]);
        percolateDown(swapId);
    }
}

void MaxHeap::removeMax() {
    songList[arr[1].vectorIndex].setHeapIndex(size);
    songList[arr[size].vectorIndex].setHeapIndex(1);
    swap(arr[1], arr[size--]);
    percolateDown(1);
}

int MaxHeap::extractMax() {
    int max = arr[1].listeningTime;
    songList[arr[1].vectorIndex].setHeapIndex(size);
    songList[arr[size].vectorIndex].setHeapIndex(1);
    swap(arr[1], arr[size--]);
    //later on, add code here that updates the array holding the heap indexes
    percolateDown(1); //move down the element at the top (index 1)
    //later on, add code here that updates the array holding the heap indexes
    return max;
}

int MaxHeap::getSize() const { return size; }

int MaxHeap::getValue(int i) {
    return arr[i].listeningTime;
}

Data MaxHeap::getObject(int i ) {
  return arr[i];
}

void MaxHeap::setValue(int i, int val) {
    arr[i].listeningTime = val;
    percolateUp(i);
    return;
}

void MaxHeap::printHeap() {
    if (isEmpty()) {
        cout << "Heap is empty!" << endl;
        return;
    }
    for (int i = 1; i <= size; ++i) {
        cout << arr[i].listeningTime << " ";
    }
    cout << endl;
}
