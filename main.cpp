#include <iostream>
#include <string>
#include <vector>
#include "linkedlist.cpp"

using namespace std;

void readFile(linkedlist & list, const char * file);

int main() {
  linkedlist *list = new linkedlist();
  readFile(*list, "list.txt");
  cout << "The average is: " << list->average() << endl;
  ofstream outData("list.txt");
  list->writeData(outData);
  outData.close();
  delete list;
  return 0;
}

// reads into the file and sorts the data in a linked list
void readFile(linkedlist & list, const char * file) {
  ifstream inData(file);
  int num;
  string line;
  vector<int> * unsorted = new vector<int>;
  while (inData >> num) {
    unsorted->push_back(num);
  }
  getline(inData, line);
  int temp;
  for (int i = 0; i < unsorted->size()-1; i++) {
    for (int j = i+1; j < unsorted->size(); j++) {
      if (unsorted->at(j) < unsorted->at(i)) {
        temp = unsorted->at(i);
        unsorted->at(i) = unsorted->at(j);
        unsorted->at(j) = temp;
      }
    }
  }
  for (int i = unsorted->size()-1; i >= 0; i--) {
    list.addToFront(unsorted->at(i));
  }
  delete unsorted;
}
