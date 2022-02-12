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

void insertAthead (node* &head , int val) {
	node* n = new node(val);
	n->next = head;
	head = n;
}

void insertAtTail (node* &head , int val) {
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

void deleteAthead (node* &head) {
	node* todelete = head;
	head = head->next;
	
	delete todelete;
}

void deletion (node* &head , int val) {
	node* temp = head;
	if(head == NULL) 
		return;
	if(head->next == NULL) {
		deleteAthead(head);
		return;
	}
	
	while (temp->next->data != val) {
		temp = temp->next;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	
	delete todelete;
}

void display (node* head ) {
	node* temp = head;
	while(temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main () {
	node* head = NULL;
	
	insertAtTail (head , 10);
	insertAtTail (head , 20);
	insertAtTail (head , 30);
	display (head);
	insertAthead(head , 90);
	display(head);
	deletion(head , 30);
	display(head);
	deleteAthead(head);
	display(head);
	
	return 200;
}
