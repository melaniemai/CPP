//#ifndef LLIST_H
//#define LLIST_H

///*
//    Linked List class that store integers, with [] operator.
//    Uses head pointer.
//    Paul Talaga
//    September 2015
//*/
//#include <ostream>
//#include <stdexcept>

//#define int int

//using namespace std;

//struct node_t {
//    int data;
//    node_t* next;
//};

//// This implementation will use a head pointer,
//// allowing O(1) insertion on the front,
//// and O(n) on the end.
//class LList {

//public:
//    LList(){
//        head = NULL;
//    }

//    ~LList(){
//        clear();
//    }

//    LList(const LList& other){
//        // Do the same as the default constructor
//        head = NULL;
//        // Check if the other LList is empty
//        if(other.head == NULL){
//            return;
//        }
//        // Not empty?  Iterate through the other list
//        // and push_back on myself.
//        node_t* temp = other.head;
//        while(temp){
//            push_back(temp->data);
//            temp = temp->next;
//        }
//    }

//    // Similar to copy constructor, but check for self
//    // assignment, if not, clear and copy all data.
//    LList& operator= (const LList& other){
//        if(this == &other){
//            return *this;
//        }
//        clear();
//        if(other.head == NULL){
//            return *this;
//        }
//        node_t* temp = other.head;
//        while(temp){
//            push_back(temp->data);
//            temp = temp->next;
//        }
//        return *this;
//    }


//   bool empty() const {
//        // TODO: Fill me in
//       if(head == NULL){    // list is empty / nothing
//           return true;
//       } else{
//           return false;
//       }
//    }

//    unsigned int size() const {
//        // TODO: Fill me in
//        node_t* temp = head;
//        unsigned int size = 0;
//        while(temp != NULL){    // if temp is null then head is has no data
//            size++;
//            temp = temp->next;  // temp node points to next node
//        }
//        return size;
//    }

//    void push_back(int value){
//        // TODO: Fill me in
//        node_t* current = head;
//        if(empty() == true){
//            head = new node_t;
//            head->data = value;
//            head->next = NULL;
//        } else{
//            while(current->next != NULL){
//                current = current->next;
//            }
//            current->next = new node_t;
//            current->next->data = value;
//            current->next->next = NULL;
//        }
//    }

//    void push_front(int value){
//        // Empty list?
//        if(head == NULL){
//            head = new node_t;
//            head->data = value;
//            head->next = NULL;
//        }else{ // Not empty
//            node_t* temp = new node_t;
//            temp->data = value;
//            temp->next = head;
//            head = temp;
//        }
//    }

//    void pop_front(){
//        if(head == NULL) return;
//        node_t* temp = head;
//        head = head->next;
//        delete temp;
//    }

//    void pop_back(){
//        // TODO: Fill me in
//        node_t* current = head;
//        node_t* previous = head;
//        if(!empty()){   // List isn't empty
//            while(current->next != NULL){
//                previous = current;     // previous has data from current node
//                current = current->next;
//            }
//            previous->next = NULL;
//            delete current;     // delete to free memory and node
//        }
//        return;
//    }


//    // Overload [] operator
//    // Return logic error if index out of bounds
//    int& operator[](unsigned pos){
//        node_t* temp = head;
//        while(temp != NULL && pos > 0){
//            temp = temp->next;
//            pos--;
//        }
//        // As long as I don't have a null pointer, assign.
//        if(pos == 0 && temp != NULL){
//            return temp->data;
//        }
//        throw logic_error("Index invalid");
//    }

//    LList reverse() const {
//        // TODO: Fill me in
//        node_t* temp = head;
//        LList reverseList;
//        while(temp != NULL){    // if head is NULL then it has nothing in it
//            reverseList.push_front(temp->data);
//            temp = temp->next;
//        }
//        return reverseList;
//    }

//    bool operator==(const LList& other) const {
//        node_t* node1 = head;
//        node_t* node2 = other.head;
//        while(node1 != NULL && node2 != NULL){
//            if((node1->data) != (node2->data)){     // Data doesn't match each other
//                return false;
//            }
//            node1 = node1->next;    // Shift to next node in linked-list
//            node2 = node2->next;    // Shift to next node in linked-list
//        }
//        if((node1 == NULL) && (node2 == NULL)){
//            return true;
//        } else{
//            return false;
//        }
//    }

//    bool operator!=(const LList& other) const {
//        return !operator==(other);
//    }

//    LList operator+ (const LList& other){   // Override addition operator
//        LList a;
//        int count = 0, i = 0;
//        if(size() < other.size()){
//            count = size();
//        } else{
//            count = other.size();
//        }
//        for(int i = 0; i < count; i++){     // Get values from either list to add together from each node
//            int value = this->getAt(i) + other.getAt(i);
//            a.push_back(value);     // Push back the added value to list
//        }
//        if(count < size()){
//            while(i < size()){
//                a.push_back(this->getAt(i));
//                i++;
//            }
//        } else if(count < other.size()){
//            while(i < other.size()){
//                a.push_back(other.getAt(i));
//                i++;
//            }
//        }
//        return a;
//    }

//    // Return value at given position, or throw a logic error if the index
//    // is invalid.
//    int getAt(unsigned pos) const{
//        node_t* temp = head;
//        while(temp != NULL && pos > 0){     // pos = position
//            temp = temp->next;
//            pos--;      // go back in the list
//        }
//        // position is at the very first element and the value isn't nothing
//        if(pos == 0 && temp != NULL){   // assign when there isn't a null pointer
//            return temp->data;      // returns value at given position
//        }
//        throw logic_error("There was a problem with the index.");   // index is invalid
//    }

//    // Assign the given value to the given position or throw a logic error if the
//    // index is invalid.
//    void setAt(int val, unsigned pos) const{
//        node_t* temp = head;
//        while(temp != NULL && pos > 0){
//            temp = temp->next;
//            pos--;
//        }
//        if(pos == 0 && temp != NULL){
//            temp->data = val;       // sets given value to given position
//        }
//        throw logic_error("There was a problem - Invalid index.");      // index is invalid
//    }

//    void clear(){
//        node_t* last = head;
//        while(head){
//            head = head->next;
//            delete last;
//            last = head;
//        }
//        // Normaly you never want to change head or you'll orphan part
//        // of the list, but in this case we are wiping the list,
//        // so it is ok to so and saves us a variable.
//        head = NULL;
//    }


//private:
//    node_t* head;

//};

//// Note this function is O(n^2) because getAt is O(n) and we are
//// doing it n times.

//ostream& operator<<(ostream& out, const LList other){
//    out << "[";
//    for(unsigned int i = 1; i < other.size(); i++){
//        out << other.getAt(i-1) << ", ";
//    }
//    if(other.size() > 0){
//        out << other.getAt(other.size() - 1);
//    }
//    out << "]";
//    return out;
//}

//#endif
