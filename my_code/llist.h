using namespace std;
#include <iostream>
class Node{
public:
	Node* next;
	int data;
	Node(int data,Node* next) : next(next),data(data){}
	friend std::ostream& operator<<(ostream& os, Node* node);
};

void add_at_end(Node*& node, int data);
Node* last(Node* head);
void add_at_front(Node*& head, int data);
void print_list(Node* head);

bool del_head(Node*& head);

bool del_tail(Node*& curr);

Node* reverse(Node* curr, Node* new_next);

Node* duplicate(Node* head);
Node* join(Node*& list1, Node* list2);
