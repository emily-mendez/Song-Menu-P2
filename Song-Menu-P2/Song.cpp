#include "Song.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Song::Song(): songId(-1), title(""), heapIndex(-1), isFavorite(false), isRemoved(false) {}

Song::Song(int songId, string title): songId(songId), title(title), isFavorite(false), isRemoved(false) {}

int Song::getSongId() const { return songId; }
const string& Song::getTitle() const { return title; }
bool Song::checkFavorite() { return isFavorite; }
int Song::getHeapIndex() const { return heapIndex; }
Node* Song::getBstNode() const { return bstNode; }
bool Song::checkRemoved() { return isRemoved; }
void Song::setRemoved(bool removed) { isRemoved = removed; }
void Song::setHeapIndex(int i) { heapIndex = i; }
void Song::setBstNode(Node* node) { bstNode = node; }
void Song::setFavorite(bool fav) { isFavorite = fav; }

