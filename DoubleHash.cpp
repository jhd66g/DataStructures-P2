#include "DoubleHash.h"

// constructor
DoubleHash::DoubleHash(): load{10} {
    nextLargestPrime(load);
    arr = new string [load];
}  
// overloaded constructor
DoubleHash::DoubleHash (unsigned int n): load{n} {
    nextLargestPrime(load);
    arr = new string [load];
}  
// destructor
DoubleHash::~DoubleHash(){
    delete [] arr;
} 

// hash function
unsigned int DoubleHash::hash(const string & key){
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 37*hashVal + ch;
    }
    return hashVal % load;
} 

// adds item to hash table
void DoubleHash::add(string s){
    unsigned int location = hash(s);
    int step = hash2(s);
    int i = 0;
    while (arr[location] != "" && arr[location] != s){
        i++;
        location = probe(location, i*step);
    }
    arr[location] = s;
}

// checks string in dictionary
bool DoubleHash::spellCheck(string s){
    convert(s);
    // if '-' is found
    auto pos = s.find('-');
    if (pos != std::string::npos) { 
        // check both single '-' and double '--'
        return ((inArr(s.substr(0, pos)) && inArr(s.substr(pos + 1))) || 
        (inArr(s.substr(0, pos)) && inArr(s.substr(pos + 2))));
    }
    // if the string is a number
    else if (std::isdigit(s[0])){
        for (char c: s){
            if (std::isalpha(c)){
                return inArr(s); // if there is a letter check arr
            }
        }
        return true; // no letters, assume true
    }
    else{
        return inArr(s);
    }
} 

// finds string in dictionary, returns true if found
bool DoubleHash::inArr(string s){
    unsigned int location = hash(s);
    int step = hash2(s);
    int i = 0;
    while (arr[location] != "" && arr[location] != s) {
        i++;
        location = probe(location, i*step);
    }
    if (arr[location] == s){
        return true;
    } 
    else{
        return false;
    }
}

// converts string to only alphanum
void DoubleHash::convert(string & s){
    // remove non '-' punctuation
    for (int i = 0; i < s.length(); i++){
        if (!isalnum(s[i]) && (s[i]!='-')){
            s.erase(i, 1);
            i--;
        }
    }
    // if first and second characters are upper make everything lower
    if (std::isupper(s[0])){
        for (char& c : s){
            c = std::tolower(c);
        }
    }
    return;
}

// checks if num is prime
bool DoubleHash::isPrime(int n){
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
} 

// finds next largest prime
void DoubleHash::nextLargestPrime(unsigned int &n){
    n *= 2;
    while (!isPrime(n)){
        n++;
    }
    return;
}

// probes the hash table
int DoubleHash::hash2(const string &key){
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 31*hashVal + ch;
    }
    return hashVal % load;
}

// probes the hash table
int DoubleHash::probe(int key, int f) {
    return (key + f) % load;
}

// prints contents of table
void DoubleHash::print(){
    for (int i = 0; i < load; i++){
        cout << i << "| " << arr[i]  << endl;
    }
    return;
} 