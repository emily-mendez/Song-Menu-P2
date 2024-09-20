#include "Functions.h"
#include <stdio.h>
using namespace std;

BinarySearchTree BST;
MaxHeap maxHeap;
vector<Song> songList;

void handleSong(const vector<string> &userInput) {
  int durationInSeconds = stoi(userInput.at(3));
  string artist = userInput.at(2);
  int minute = durationInSeconds / 60;
  int seconds = durationInSeconds % 60; 
  int songId = stoi(userInput.at(1));
  string title = userInput.at(4);
  Song newSong = Song(songId, title);
  unsigned int i = 0;
  BST.insert(title);
  newSong.setBstNode(BST.find(title));
  if(songList.size() != 0) {
    while(i != songList.size() && songId > songList.at(i).getSongId()) {
      i++;
    }
    newSong.getBstNode()->vectorIndex = i;
    maxHeap.insertItem(0, i);
    newSong.setHeapIndex(maxHeap.getSize());
    songList.insert(songList.begin() + i, newSong);
    
    for(unsigned int j = i + 1; j < songList.size(); j++) {
      (songList.at(j).getBstNode()->vectorIndex)++;
    }
    maxHeap.updateIndices(i + 1);
  } else {
    maxHeap.insertItem(0, 0);
    newSong.setHeapIndex(maxHeap.getSize());
    songList.push_back(newSong);
    newSong.getBstNode()->vectorIndex = i;
  }
  if(seconds < 10) {
    cout << "new song " << songId << " " << title << " by " << artist << " " << minute << ":0" << seconds << endl;
  } else {
    cout << "new song " << songId << " " << title << " by " << artist << " " << minute << ":" << seconds << endl;
  }
}

void handleRemove(const vector<string> &userInput) {
  string title = userInput.at(1);
  Node* song = BST.find(title);
  int vectorIndex = song->vectorIndex;
  int heapIndex = songList.at(vectorIndex).getHeapIndex();
  if(songList.at(vectorIndex).checkFavorite()) {
    songList.at(vectorIndex).setFavorite(false);
    songList.at(vectorIndex).setRemoved(true);
    cout << "Removed " << title << " from your favorites" << endl;
  } else {
    songList.at(vectorIndex).setRemoved(true);
    maxHeap.setValue(heapIndex, 99999999);
    maxHeap.removeMax();
    cout << "Removed " << title << " from your songs" << endl;
  } 
}

void handleListen(const vector<string> &userInput) {
    string title = userInput.at(1);
    int seconds = stoi(userInput.at(2));
    int vectorIndex = BST.find(title)->vectorIndex; 
    if(!songList[vectorIndex].checkFavorite()) {
      int heapIndex = songList.at(vectorIndex).getHeapIndex(); 
      maxHeap.setValue(heapIndex, maxHeap.getValue(heapIndex) + seconds); //setValue handles percolating
      cout << "Listened to " << title << " for " << seconds << " seconds." << endl;
    }
    else {
      cout << "Song " << title << " is a favorite." << endl;
    }
}

void handleFavorite() {
  if(maxHeap.isEmpty())
    {
      cout << "No song to favorite" << endl;
      return;
    }
  songList[maxHeap.getObject(1).vectorIndex].setFavorite(true);
  string title = songList[maxHeap.getObject(1).vectorIndex].getTitle();
  int listenTime = maxHeap.extractMax();
  cout << "Song " << title << " added to list of favorites (Listened for " << listenTime << " seconds)" << endl;
}

void handleShow() {
  for(unsigned int i = 0; i < songList.size(); i++) {
    if(!songList.at(i).checkRemoved()) {
      cout << songList.at(i).getSongId() << " " << songList.at(i).getTitle() << " has been listened to for " << maxHeap.getValue(songList.at(i).getHeapIndex()) << " seconds"<< endl;
    }
  }
}

void handleTest() {
  cout << "This is the BST: " << endl;
  BST.inOrderPrint(BST.getRoot());
  cout << endl;
  cout << "This is the array along with song title and heap index : " << endl;
  for(unsigned int i = 0; i < songList.size(); i++) {
    if(!songList.at(i).checkRemoved()){
    cout << "title: " << songList.at(i).getTitle() << " || " << "heap index: " << songList.at(i).getHeapIndex() << endl;
    }
  }
  cout <<"This is the MaxHeap: " << endl;
  maxHeap.printHeap();
  cout << "These are the vectorIndices: " << endl;
  for(unsigned int i = 0; i < songList.size(); i++) {
    if(!songList.at(i).checkRemoved()) {
      cout << songList.at(i).getSongId() << " " << songList.at(i).getTitle() << " has been listened to for " << maxHeap.getValue(songList.at(i).getHeapIndex()) << " seconds"<< endl;
    }
  }
  cout << "Heap size: " << maxHeap.getSize() << endl;
}
