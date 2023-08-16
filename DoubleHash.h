#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>

using std::ifstream;
using std::cout;
using std::endl;
using std::string;

#ifndef DoubleHash_H
#define DoubleHash_H

class DoubleHash{
    private:
        string* arr;
        unsigned int load;

    public:
        DoubleHash(); // constructor
        DoubleHash (unsigned int ); // overloaded constructor
        ~DoubleHash(); // destructor


        unsigned int hash(const string & ); // hash function
        void add(string ); // adds item to hash table
        bool spellCheck(string ); // checks string in dictionary
        bool inArr(string ); // finds string in dictionary, returns true if found
        void convert(string & ); // converts string to only alphanum
        bool isPrime(int ); // checks if num is prime
        void nextLargestPrime(unsigned int &); // finds next largest prime
        int hash2(const string &key ); // second hash function
        int probe(int , int ); // probes the hash table

        void print(); // prints contents of table

};

#endif 