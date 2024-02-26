#include "LinkedList.h"
#include "Child.h"
#include <fstream>

using namespace std;

template<class ItemType>
LinkedList<ItemType>::LinkedList() {
    head = NULL;
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList() {
    DeleteList();
}

template<class ItemType>
LinkedList<ItemType>::LinkedList(LinkedList& rightside) {
    this->head = NULL;
    *this = rightside;
}

template<class ItemType>
bool LinkedList<ItemType>::Insert(ItemType* obj) {
    Node* addNode = new Node();
    ItemType* data1 = new ItemType();
    *data1 = *obj;
    addNode->data = data1;

    if (head == NULL) {
        head = addNode;
        return true;
    }

    Node* first = head;
    while ((first->next != NULL && *obj == *(first->next->data)) || *head->data == *obj) {
        first = first->next;
    }
    if (((first->next != NULL && *obj == *(first->next->data)) || *head->data == *obj)) {
        return false;
    }
    if (*obj > *(first->data)) {
        addNode->next = first->next;
        first->next = addNode;
    }
    else {
        addNode->next = head;
        head = addNode;
    }
    return true;
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    return (head == NULL);
}

template<class ItemType>
bool LinkedList<ItemType>::BuildList(string fileName) {
    ifstream inFile;
    inFile.open(fileName);
    if (inFile) {
        while (!inFile.eof()) {
            int age;
            string firstName;
            string lastName;

            inFile >> firstName >> lastName >> age;
            ItemType* child = new ItemType(firstName, lastName, age); // Assuming constructor for ItemType exists
            this->Insert(child);
            cout << firstName << " " << lastName << " " << age;
        }
        inFile.close();
        return true;
    }
    else {
        cout << "File " << fileName << " NOT OPENED" << endl;
        return false;
    }
}

template <class ItemType>
void LinkedList<ItemType>::DeleteList(){
    if(head == NULL){
        return;
    }
    Node* t = head;
    while(head != NULL){
        head = head -> next;
        delete t ->data;
        delete t;
        t = head;
    }
}
 
template <class ItemType>
bool LinkedList<ItemType>::Peek(ItemType target, ItemType& result) const{
    if(head != NULL){
        if(*(head->data) != target){
            Node* current = head;
            while(current -> next != NULL && *(current ->next->data) != target){
                current = current -> next;
            }
            if(*(current->next->data) == target){
                result = *(current->next->data);
                return true;
            }
        }
        else{
            result = *head->data;
            return true;
        }
    }
    return false;
}

template <class ItemType>
bool LinkedList<ItemType>::Remove(ItemType target, ItemType& result){
    if(head != NULL){
        if(*head -> data != target){
            Node* curr = head;
            while(curr->next != NULL && target > *(curr->next->data)){
                curr = curr->next;
            }
            if(curr->next != NULL && *(curr->next->data)== target){
                Node* newNode = new Node();
                newNode = curr -> next;
                result = *(curr -> next -> data);
                curr -> next = curr -> next -> next;
                delete newNode -> data;
                delete newNode;
                return true;
            }
        }
        else{
            Node* newNode = head -> next;
            result = *(head -> data); 
            delete head -> data;
            delete head;
            head = newNode;
            return true;
        }
    }
    return false;
}

template <class ItemType>
void LinkedList<ItemType>::operator=(const LinkedList& otherhere){
    this->DeleteList();
        Node* temp = otherhere.head;
        Node* n = new Node();
        head = n;
        while (temp != NULL) {
            ItemType* T = new ItemType();
            *T = *(temp -> data);
            n->data = T;
        
            temp = temp->next;
            if (temp != NULL){
                n->next = new Node();
                n = n->next;
            }
            else{
                n->next = NULL;
            }
        }
}

template <class ItemType>
bool LinkedList<ItemType>::Merge(LinkedList& list1) 
{
    bool check = false;
    Node *newHead;
    Node *one = head;
    Node *two = list1.head;
    
    if(one != NULL){
        while (two != NULL){
            if (*(two->data) < *(head->data)){
                check = true;
                newHead = two->next;
                two->next = head;
                this->head = two;
                two = newHead;
                one = this->head;
            }
            else if (one->next != NULL && (*(two->data) == *(one->data) || *(two->data) == *(one->next->data))){
                two = two->next;
            }
            else if (one->next != NULL && (*(two->data) < *(one->next->data))){
                check = true;
                Node *newHead = two->next;
                two->next = two->next;
                one->next = two;
                two = newHead;
            } 
            else if (one->next != NULL && (*(two->data) > *(one->next->data))){
                one = one->next;
            } 
            else{
                if(two!= NULL)
                    check = true;
                if (one -> data == two -> data){
                    Node* temp = two -> next;
                    delete two->data;
                    delete two;
                    two = temp;
                }
                one->next = two; 
                list1.head = NULL; 
            }
        }
        return check;
    }
    while(two != NULL){
        Node* temp = new Node();
        ItemType* tdata = new ItemType();
        *tdata = *(two -> data);

        temp -> data = tdata;
        if(head == NULL){
                head = temp;
                one = head;
        }
        else{
                one -> next = temp;
                one = one -> next;
        }
        two = two -> next;
        check = true;
    }
    list1.DeleteList();
    return check;
}

template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList &list) const 
{
    LinkedList* one1 = this;
    *one1 += list;
    return *one1;
}

template <class T>
bool LinkedList<T>::operator+=(const LinkedList& list) 
{
    LinkedList *newlist = new LinkedList();
    *newlist = list;
    return this->Merge(*newlist);
}

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList& list) const 
{
    Node *one1 = head;
    Node *two2 = list.head;
    while ((one1 != NULL && two2 != NULL) && (*(one1->data) == *(two2->data))){
        one1 = one1->next; 
        two2 = two2->next;

    }
    if (one1 == NULL && two2 == NULL){
        return true;
    }
    return false;
}

template <class ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList& list)const {
    return !(this == &list);
}

// Define the main function here
int main() {
    
Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11; 
LinkedList<Child> class1, class2, soccer, chess;
int a = 1, b = -1, c = 13;
class1.Insert(&c1);
class1.Insert(&c2);
class1.Insert(&c3);
class1.Insert(&c4);
class1.Insert(&c5);
class1.Insert(&c6);
class1.Insert(&c5);
cout << "class1: " << class1 << endl; 
if (class1.Insert(&c1))
{
cout << "ERROR::: Duplicate" << endl;
}

class2.Insert(&c4);
class2.Insert(&c5);
class2.Insert(&c6);
class2.Insert(&c7);
class2.Insert(&c10);
cout << "Class2: " << class2 << endl; class1.Merge(class2);
class2.Merge(class1);
class1.Merge(class2);
class1.Merge(class1);
cout << "class1 and 2 Merged: " << class1 << endl;
if (!class2.isEmpty()) {
cout << "ERROR:: Class2 should be empty empty" << endl; }
class1.Remove(c4, c11); class1.Remove(c5, c11); class1.Remove(c11, c11); if (class1.Remove(c1, c11)) {
cout << "Removed from class1, student " << c11 << endl;
}
cout << "class1: " << class1 << endl; soccer.Insert(&c6);
soccer.Insert(&c4);
soccer.Insert(&c9);
cout << "soccer: " << soccer << endl;
soccer += class1;
cout << "soccer += class1 : " << soccer << endl; LinkedList<Child> football = soccer;
if (football == soccer) {
cout << "football: " << football << endl; } if (
football.Peek(c6, c11)) {
cout << c11 << " is on the football team" << endl; }
soccer.DeleteList(); if (!soccer.isEmpty()) {
cout << "ERROR: soccer should be empty" << endl; }
LinkedList<int> numbers; numbers.Insert(&a); numbers.Insert(&b); numbers.Insert(&c);
cout << "These are the numbers: " << numbers << endl; numbers.DeleteList();
return 0;
}

