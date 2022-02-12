#include<iostream>
using namespace std;

class node {
	public :
		int data;
		node* next;
	node (int val) {
		data = val;
		next = NULL;
	}
};

void insertAthead (node* &head, int val) {
	node* n = new node(val);
	n->next = head;
	head = n;
}

void insertAtTail (node* &head, int val) {
	node* n = new node(val);
	if(head == NULL) {
		head = n;
		return;
	}
	
	node* temp = head;
	
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}

void display (node* head) {
	node* temp = head;
	
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main () {
	node* head = NULL;
	
	insertAtTail(head,71);
	insertAtTail(head,74);
	insertAtTail(head,72);
	insertAthead(head,91);
	display(head);
	
	return 200;
}
