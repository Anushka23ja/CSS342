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

    Node* prev = NULL;
    Node* curr = head;
    
    while (curr != NULL && (*obj > *(curr->data))) {
        prev = curr;
        curr = curr->next;
    }
    
    if (prev != NULL && (*prev->data == *obj)) {
        delete addNode->data;
        delete addNode;
        return false;
    }

    if (prev == NULL) {
        addNode->next = head;
        head = addNode;
    } else {
        addNode->next = curr;
        prev->next = addNode;
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
