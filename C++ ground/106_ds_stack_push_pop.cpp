#include<iostream>
using namespace std;

int stack[100] , n = 100 , top = -1;

void push(int val) {
	if(top >= n-1)
		cout<<"Stack overflow "<<endl;
	else {
		top ++;
		stack[top] = val;
	}
}

void pop() {
	if(top <= -1)
		cout<<"Stack underflow "<<endl;
	else {
		cout<<"Popped element is : "<<stack[top]<<endl;
		top --;
	}
}

void display () {
	if(top >= 0) {
		cout<<"Stack elements is : ";
		for(int i=top; i>=0; i--)
			cout<<stack[i]<<" ";
			cout<<endl;
	}
	else 
		cout<<"Stack are empty "<<endl;
}

int main () {
	int choose , num;
	
	cout<<"1. for push "<<endl;
	cout<<"2. for pop "<<endl;
	cout<<"3. for display "<<endl;
	cout<<"4. for Exit "<<endl;
	
	do {
		cout<<"Enter your choice : ";
		cin>>choose;
		
		if(choose == 1) {
			cout<<"Enter stack element : ";
			cin>>num;
			push(num);
		}
		else if (choose == 2)
			pop();
		else if (choose == 3)
			display ();
		else if(choose == 4) {
			cout<<"Exit "<<endl;
			break;
		}
		else 
			cout<<"Invalid choice "<<endl;
	} while(choose != 4);
	
	return 200;
}
