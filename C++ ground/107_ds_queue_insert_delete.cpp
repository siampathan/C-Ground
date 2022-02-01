#include <iostream>
using namespace std;

int queue[100], n = 100, front = - 1, rear = - 1;

void Insert() {
   int val;
   if (rear == n - 1)
      cout<<"Queue overflow"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : ";
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}

void Delete() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow "<<endl;
      return ;
   } else {
      cout<<"deleted from queue is : "<< queue[front] <<endl;
      front++;
   }
}
void Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i=front; i<=rear; i++)
        cout<<queue[i]<<" ";
        cout<<endl;
   }
}
int main() {
   int num;
   
   cout<<"1. for Insert element "<<endl;
   cout<<"2. for Delete element "<<endl;
   cout<<"3. for Display elements"<<endl;
   cout<<"4. Exit"<<endl;
   do {
      cout<<"Enter your choice : ";
      cin>>num;
      
	  if(num ==1)
		Insert();
	  else if(num == 2)
	    Delete();
	  else if(num ==3)
	    Display();
	  else if(num == 4) {
	    cout<<"Exit"<<endl;
	    break;
	  }
	  else 
	    cout<<"Invalid choice "<<endl;
   } while(num!=4);
   
   return 200;
}
