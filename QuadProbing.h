#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

#ifndef QuadProbing_H
#define QuadProbing_H

class QuadProbing{
    private:
        string* arr;
        unsigned int load;

    public:
        QuadProbing(); // constructor
        QuadProbing (unsigned int ); // overloaded constructor
        ~QuadProbing(); // destructor


        unsigned int hash(const string & ); // hash function
        void add(string ); // adds item to hash table
        bool spellCheck(string ); // checks string in dictionary
        bool inArr(string ); // finds string in dictionary, returns true if found
        void convert(string & ); // converts string to only alphanum
        bool isPrime(int ); // checks if num is prime
        void nextLargestPrime(unsigned int &); // finds next largest prime
        int probe(int , int ); // probes the hash table

        void print(); // prints contents of table

};

#endif 