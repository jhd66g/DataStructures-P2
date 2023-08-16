#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include "Chaining.h"
#include "QuadProbing.h"
#include "DoubleHash.h"
#include <string>

using std::ifstream;
using std::cout;
using std::endl;

int main(int argc, char* argv[]){
    // open file and create hash table
    ifstream fstr(argv[1]); // opens file by command line
    int size {0};
    string s{};
    while (fstr >> s){
        size ++;
    }

    Chaining hashtable1(size);

    //populate hashtable1;
    fstr.clear();
    fstr.seekg(0, std::ios::beg);
    auto start1c = std::chrono::steady_clock::now(); 
    while (fstr >> s){
        hashtable1.add(s);
    }
    auto end1c = std::chrono::steady_clock::now(); // end time 
    auto duration1c = std::chrono::duration_cast<std::chrono::nanoseconds> (end1c - start1c).count();
    cout << "Chaining construction time: " << duration1c << " nanoseconds" << endl;
    
    // search through text file and check mispelled words
    int spellCount = 0;
    ifstream fstr2(argv[2]); // opens file by command line
    auto start1 = std::chrono::steady_clock::now(); 
    while (fstr2 >> s){
        if (!(hashtable1.spellCheck(s))){
            spellCount ++;
        }
    }
    auto end1 = std::chrono::steady_clock::now(); // end time 
    auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds> (end1 - start1).count();
    cout << "Chaining misspelled word count: " << spellCount << endl;
    cout << "Chaining search time: " << duration1 << " nanoseconds" << endl << endl;
    
    //populate hashtable2
    QuadProbing hashtable2(size);
    fstr.clear();
    fstr.seekg(0, std::ios::beg);
    auto start2q = std::chrono::steady_clock::now(); 
    while (fstr >> s){
        hashtable2.add(s);
    }
    auto end2q = std::chrono::steady_clock::now(); // end time 
    auto duration2q = std::chrono::duration_cast<std::chrono::nanoseconds> (end2q - start2q).count();
    cout << "QuadProbing construction time: " << duration2q << " nanoseconds" << endl;

    // search through text file and check mispelled words
    int spellCount2 = 0;
    fstr2.clear();
    fstr2.seekg(0, std::ios::beg);
    auto start2 = std::chrono::steady_clock::now(); 
    while (fstr2 >> s){
        if (!(hashtable2.spellCheck(s))){
            spellCount2 ++;
        }
    }
    auto end2 = std::chrono::steady_clock::now(); // end time 
    auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - start2).count();
    cout << "QuadProbing misspelled word count: " << spellCount2 << endl;
    cout << "QuadProbing search time: " << duration2 << " nanoseconds" << endl << endl;

    //populate hashtable3
    DoubleHash hashtable3(size);
    fstr.clear();
    fstr.seekg(0, std::ios::beg);
    auto start3q = std::chrono::steady_clock::now(); 
    while (fstr >> s){
        hashtable3.add(s);
    }
    auto end3q = std::chrono::steady_clock::now(); // end time 
    auto duration3q = std::chrono::duration_cast<std::chrono::nanoseconds> (end3q - start3q).count();
    cout << "DoubleHash construction time: " << duration3q << " nanoseconds" << endl;
    // search through text file and check mispelled words
    int spellCount3 = 0;
    fstr2.clear();
    fstr2.seekg(0, std::ios::beg);
    auto start3 = std::chrono::steady_clock::now(); 
    while (fstr2 >> s){
        if (!(hashtable3.spellCheck(s))){
            spellCount3 ++;
        }
    }
    auto end3 = std::chrono::steady_clock::now(); // end time 
    auto duration3 = std::chrono::duration_cast<std::chrono::nanoseconds> (end3 - start3).count();
    cout << "DoubleHash misspelled word count: " << spellCount3 << endl;
    cout << "DoubleHash search time: " << duration3 << " nanoseconds" << endl << endl;

    if ((duration1 < duration2) &&(duration1 < duration3)){
        cout << "Chaining was the most time efficient." << endl;
    }
    else if ((duration2 < duration1) &&(duration2 < duration3)){
        cout << "Quadratic Probing was the most time efficient." << endl;
    }
    else{
        cout << "Double Hashing was the most time efficient." << endl;
    }
    cout << endl;

    if ((duration1 > duration2) &&(duration1 > duration3)){
        cout << "Chaining was the least time efficient." << endl;
    }
    else if ((duration2 > duration1) &&(duration2 > duration3)){
        cout << "Quadratic Probing was the least time efficient." << endl;
    }
    else{
        cout << "Double Hashing was the least time efficient." << endl;
    }

    return 0;
}