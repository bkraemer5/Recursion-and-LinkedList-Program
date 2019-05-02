#include "linkedlist.h"
#include <fstream>
#include <iostream>

using namespace std;

// constructor
linkedlist::linkedlist() {
  head = nullptr;
}

// deconstructor
linkedlist::~linkedlist() {
  delete head->next;
}

// recursive function to count the nodes in the linked list
int linkedlist::count(node * t) {
   if(t != nullptr) {
     return 1 + count(t->next);
   }
   else {
     return 0;
   }
}

// creates a new node and adds it to the front of the linked list
void linkedlist::addToFront(int n) {
  head = new node{n, head};
}

// returns the average of all numbers in the linked list
double linkedlist::average() {
  return (double)sum(head)/(double)count(head);
}

// recursive function to compute the sum of all nodes in the linked list
int linkedlist::sum(node * t) {
  if(t != nullptr) {
    return t->data + sum(t->next);
  }
  else {
    return 0;
  }
}

// writes each node from the linked list to a file
void linkedlist::writeInorder(ofstream &file) {
  node *temp = head;
  while (temp != nullptr) {
    file << temp->data << " ";
    temp = temp->next;
  }
}

// recursive function to write each node from the linked list in reversed order and into a file
void linkedlist::writeReversed(ofstream &file, node *t) {
  if (t == nullptr) {
    return;
  }
  writeReversed(file, t->next);
  file << t->data << " ";
}

void linkedlist::writeData(ofstream &file) {
  writeInorder(file);
  file << endl;
  writeReversed(file, head);
  file << endl;
}
