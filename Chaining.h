#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

#ifndef Chaining_H
#define Chaining_H

template <typename T> class LinkedList {
  private:
    struct Node {
        T data;
        Node *next;

        Node(): data{}, next{nullptr} {}
	    Node(string data, Node *p = nullptr): data{data}, next{p}{}
	    ~Node(){}
    };
    Node *head;

  public:
    LinkedList(); // constructor
    ~LinkedList(); // destructor

    void push_front(T ); // adds item to the front
    void push_back(T ); // adds item to the back
    bool search(T ); // searches list for item

    T remove_front(); // removes front item

    void print(); // prints contents of list
};

class Chaining{
    private:
       //unique_ptr<LinkedList<string> []> arr = nullptr;
       LinkedList<string> *arr;
        unsigned int load;

    public:
        Chaining(); // constructor
        Chaining (unsigned int ); // overloaded constructor
        ~Chaining(); // destructor


        unsigned int hash(const string & ); // hash function
        void add(string ); // adds item to hash table
        bool spellCheck(string ); // checks string in dictionary
        bool inArr(string ); // finds string in dictionary, returns true if found
        void convert(string & ); // converts string to only alphanum

        void print(); // prints contents of table

};

#endif