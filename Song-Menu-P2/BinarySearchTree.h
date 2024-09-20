#ifndef BinarySearchTree_H
#define BinarySearchTree_H
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Node {
      public:
        string val;
        Node* left;
        Node* right;
        int vectorIndex;
        Node() : left(nullptr), right(nullptr), vectorIndex(-1) {}
        Node(string title) : val(title), left(nullptr) , right(nullptr) {}
};

class BinarySearchTree {
  public:
    Node* root;
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(string title){
       root = new Node(title);
    }
    void setIndex(int i);
    Node* findHelper(Node* curr, string v);
    Node* find(string v);
    void insert(string title);
    void insertHelper(Node* curr, string v);
    Node* remove(Node* root, string title);
    void inOrderPrint(Node* root);
    Node* getRoot();
};

#endif
