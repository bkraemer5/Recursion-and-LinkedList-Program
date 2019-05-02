#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node {
    int data;
    node * next;
};

class linkedlist {
private:
    node * head;
    int count(node * t); // RECURSIVE
    int sum(node * t); // RECURSIVE

public:
    linkedlist();
    ~linkedlist(); // RECURSIVE
    void addToFront(int n);
    double average(); // uses sum and count functions
    void writeInorder(ofstream &file);
    void writeReversed(ofstream &file, node * t);
    void writeData(ofstream &file);
};
#endif // end linkedlist.h
