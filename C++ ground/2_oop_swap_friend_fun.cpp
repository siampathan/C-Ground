#include<iostream>
using namespace std;

class B;
class A {
	int value1;
	public :
		A () {
			cout<<"Enter first number : ";
			cin>>value1;
		}
		
		friend void swapping(A ab1 , B ab2);
};

class B {
	int value2;
	public :
		B () {
			cout<<"Enter Second number : ";
			cin>>value2;
		}
		
		friend void swapping(A ab1 , B ab2);
};

void swapping (A ab1 , B ab2) {
	cout<<"Before Swapping : "<<endl;
	cout<<ab1.value1<<" "<<ab2.value2<<endl;
	
	int temp = ab1.value1;
	ab1.value1 = ab2.value2;
	ab2.value2 = temp;
	
	cout<<"After Swapping : "<<endl;
	cout<<ab1.value1<<" "<<ab2.value2<<endl;
}

int main () {
	A a;
	B b;
	swapping(a , b);
	
	return 200;
}
