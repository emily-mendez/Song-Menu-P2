#ifndef Song_H
#define Song_H

#include "BinarySearchTree.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class Song {
  private:
    int songId;
    string title;
    int heapIndex;
    Node* bstNode;
    bool isFavorite;
    bool isRemoved;
    
  public:
    Song();
    Song(int songId, string title);
    int getSongId() const;
    const string& getTitle() const;
    bool checkFavorite();
    int getHeapIndex() const;
    void setBstNode(Node* node);
    Node* getBstNode() const;
    bool checkRemoved();
    void setRemoved(bool removed);
    void setHeapIndex(int i);
    void setFavorite(bool fav);
};

#endif
