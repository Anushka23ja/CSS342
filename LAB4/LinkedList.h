#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>

using namespace std;

template<class ItemType>
class LinkedList {
private:
    struct Node {
        ItemType* data;
        Node* next;
    };
    Node* head;

public:
    LinkedList();
    LinkedList(LinkedList& rightside);
    ~LinkedList();

    void PrintList();
    void DeleteList();
    bool isEmpty() const;
    bool BuildList(string fileName);
    bool Insert(ItemType* obj);
    bool Merge(LinkedList &list1);
    bool Remove(ItemType value, ItemType& output);
    bool Peek(ItemType target, ItemType &result) const;

    bool operator!=(const LinkedList& list) const;
    bool operator==(const LinkedList& list) const;
    bool operator+=(const LinkedList& list);
    void operator=(const LinkedList& otherhere);
    LinkedList operator+(const LinkedList& list) const;

    friend ostream& operator<<(ostream& os, const LinkedList<ItemType>& list) {
        os << endl;
        if (list.head != NULL) {
            Node* here = list.head;
            while (here != NULL) {
                cout << (*here->data) << endl;
                here = here->next;
            }
            return os;
        }
        cout << "LINKEDLIST IS NOT HERE AS IT DOES NOT EXIST " << endl;
        return os;
    }
};

#endif