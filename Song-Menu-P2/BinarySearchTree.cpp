#include "BinarySearchTree.h"
#include <stdio.h>
#include <iostream>
using namespace std;

Node* BinarySearchTree::findHelper(Node *curr, string v){
  if(curr == nullptr){
    return curr;
  }
  if(curr->val == v){
    return curr;
  }
  if(curr->val > v){
    return findHelper(curr->left, v);
  }
    return findHelper(curr->right, v);
  }

Node* BinarySearchTree::find(string v){
  return findHelper(root, v);
}

void BinarySearchTree::insertHelper(Node* curr, string v){
  if(curr->val > v){
    if(curr->left == nullptr){
      curr -> left = new Node(v);
    }else{
      insertHelper(curr->left, v);
    }
  }else{
    if(curr->right == nullptr){
      curr -> right = new Node(v);
    }else{
      insertHelper(curr->right, v);
    }
  }
}

void BinarySearchTree::insert(string title){
  if(root == nullptr){
    root = new Node(title);
    return;
  }
  insertHelper(root, title);
}

Node* BinarySearchTree::remove(Node* root, string title){
  if(root == nullptr){
    return root;
  }
  if(title < root->val){
    root -> left = remove(root->left, title);
    return root;
  }
  else if(title > root->val){
    root -> right = remove(root->right, title);
    return root;
  }

  if(root -> left == nullptr){
    Node* temp = root -> right;
    delete root;
    return temp;
  }
  else if(root -> right == nullptr){
      Node* temp = root -> left;
      delete root;
      return temp;
  }

  Node* succParent = root;
  Node* succ = root -> right;
  while(succ -> left != nullptr){
    succParent = succ;
    succ = succ -> left;
  }

  root -> val = succ -> val;

  if(succParent -> left == succ){
    succParent -> left = succ -> right;
  }
  else{
    succParent -> right = succ -> right;
  }
  delete succ;
  return root;
}

void BinarySearchTree::inOrderPrint(Node* root) {
  if(root == nullptr) return;
  inOrderPrint(root->left);
  cout << root->val << ", ";
  inOrderPrint(root->right);
}

Node* BinarySearchTree::getRoot() {
  return root;
}
