#include "llist.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void add_at_end(Node*& head, int data){
	if(!head){
		head = new Node(data,nullptr);
	}
	else add_at_end(head->next,data);
}

Node* last(Node* head){
	if(!head) return nullptr;
	else if (!head -> next) return head;
	else return last(head->next);
}

void add_at_front(Node*& head, int data){
	head = new Node(data,head);
}

void print_list(Node* head){
	if(!head) cout << "EMPTY LIST!" <<endl;

	else if(!head->next) cout << head << ";";
	else {
		cout << head << ";";
		print_list(head->next);
	}
}

bool del_head(Node*& head){
	if(!head) return false;
	else{
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
}

bool del_tail(Node*& curr){
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

Node* reverse(Node* curr, Node* new_next){
	if(!curr) return new_next;
	else{
		return reverse(curr->next, new Node(curr->data,new_next));
	}
}

Node* duplicate(Node* head){
	if (!head->next) return new Node(head->data,nullptr);
	else{
		return new Node(head->data,duplicate(head->next));
		
	}
}

Node* join(Node*& list1, Node* list2){
	Node* tail = last(list1);
	tail->next = list2;
	return list1;
}

ostream& operator << (ostream& os, Node* node){
	os << node->data << endl;
	return os;
}