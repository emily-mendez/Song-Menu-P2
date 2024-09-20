#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Song.h"
#include "BinarySearchTree.h"
#include "MaxHeap.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

void handleSong(const vector<string> &userInput);
void handleRemove(const vector<string> &userInput);
void handleListen(const vector<string> &userInput);
void handleFavorite();
void handleShow();
void handleTest();

#endif
