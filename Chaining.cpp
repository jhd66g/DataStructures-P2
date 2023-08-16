#include "Chaining.h"

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <typename T>
LinkedList<T>:: ~LinkedList() {
    Node *curr = head;
    while (head != nullptr) {
        head = head->next;
        delete curr;
        curr = head;
    }
    delete head;
}

template <typename T>
void LinkedList<T>::push_front(T data) {
      Node *new_node = new Node;
      new_node->data = data;
      new_node->next = head;
      head = new_node;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    if (head == nullptr) {
        head = new_node;
    }
}
template <typename T>
bool LinkedList<T>::search(T item){
    Node *curr = head;
	while (curr != nullptr){
	    if (curr->data == item){
            return true;
        }
		curr = curr->next; // update curr
	}
    return false;
}

template <typename T>
T LinkedList<T>::remove_front() {
    if (head == nullptr) {
        throw std::runtime_error("LinkedList is empty");
    }
    T data = head->data;
    Node *temp = head;
    head = head->next;
    delete temp;
    return data;
}

template <typename T>
void LinkedList<T>::print(){
    // create another node pointer to iterate over list
	Node *curr = head;
	while (curr != nullptr){
	    cout << curr->data << " ";
		curr = curr->next; // update curr
	}
	cout << endl;
	return;
}

// constructor
Chaining::Chaining(): load{10}{
    arr = new LinkedList<string> [load];
}

// overloaded constructor
Chaining::Chaining (unsigned int s): load{s}{
    arr = new LinkedList<string> [load];
} 

// destructor
Chaining::~Chaining(){
    delete[] arr;
}

// hash function
unsigned int Chaining::hash(const string & key){
    unsigned int hashVal = 0;
    for (char ch: key){
        hashVal = 37*hashVal + ch;
    }
    return hashVal % load;
} 

// adds item to hash table
void Chaining::add(string s){
    unsigned int location = hash(s);
    arr[location].push_front(s);
    return;
} 

// checks string in dictionary, returns true if correct
bool Chaining::spellCheck(string s){
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
bool Chaining::inArr(string s){
    unsigned int location = hash(s);
    return (arr[location]).search(s); // search linked list at location
}

// converts string to only alphanum
void Chaining::convert(string& s){
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

// prints contents of table
void Chaining::print(){
    for (int i = 0; i < load; i++){
        cout << i << "| ";
	    arr[i].print();
    }
} 