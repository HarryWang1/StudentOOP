#ifndef TEMPL_LL_H
#define TEMPL_LL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * The class template `Node`, which is the building block of our linked list code.
 * */
ostream& operator<<(ostream& os, const vector<int> v) {
    for (int i : v) {
        os << i << ", ";
    }
    os << endl;
    return os;
}


template <typename DATA>
class Node {
public:
    Node(DATA d, Node* n=nullptr) : data(d), next(n) {}
    DATA data;
    Node* next;
    friend std::ostream& operator<<(std::ostream& os, const Node<DATA>* nd) {
        os << nd->data << endl;
        return os;
    }
};


/*
 * The various functions that can operate on our linked lists:
 * */


/*
 * Add a node to the end of a list.
 * */
template <typename DATA>
void add_at_end(Node<DATA>*& head, DATA d) {
    if (!head) {
        head = new Node<DATA>(d, nullptr);
    }
    else {
        add_at_end(head->next, d);
    }
}

template <typename DATA>
void print_list(Node<DATA>* head){
    if(!head) cout << "EMPTY LIST!" <<endl;

    else if(!head->next) cout << head << ";";
    else {
        cout << head << ";";
        print_list(head->next);
    }
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * Once again, you must not share memory.
 * */
template <typename DATA>
Node<DATA>* reverse(Node<DATA>* curr, Node<DATA>* new_next) {
    if (!curr) return new_next;
    else {
        return reverse(curr->next, new Node<DATA>(curr->data, new_next));
    }
}

template <typename DATA>
Node<DATA>* last(Node<DATA>* head){
    if(!head) return nullptr;
    else if (!head -> next) return head;
    else return last(head->next);
}
template <typename DATA>

void add_at_front(Node<DATA>*& head, DATA d){
        head = new Node<DATA>(d,head);
}

template <typename DATA>

bool del_head(Node<DATA>*& head){
    if(!head) return false;
    else{
        Node<DATA>* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
template <typename DATA>

bool del_tail(Node<DATA>*& curr){
    if(!curr) return false;
    else{
        if(curr->next == nullptr){
            curr = nullptr;
            return true;
        }
        else{
            return del_tail(curr->next);
        }
    }
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
template <typename DATA>

Node<DATA>* duplicate(Node<DATA>* head){
    if (!head->next) return new Node<DATA>(head->data,nullptr);
    else{
        return new Node<DATA>(head->data,duplicate(head->next));
        
    }
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
template <typename DATA>

Node<DATA>* join(Node<DATA>*& list1, Node<DATA>* list2){
    Node<DATA>* tail = last(list1);
    tail->next = list2;
    return list1;
}

#endif