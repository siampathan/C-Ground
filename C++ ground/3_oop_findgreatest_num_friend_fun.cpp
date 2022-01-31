#include<iostream>
using namespace std;

class second;
class third;

class first {
	int value1;
	public :
		first () {
			cout<<"Enter first number : ";
			cin>>value1;
		}
		
		friend void greatest (first ab1 , second ab2 , third ab3);
};

class second {
	int value2;
	public :
		second () {
			cout<<"Enter second number : ";
			cin>>value2;
		}
		
		friend void greatest (first ab1 , second ab2 , third ab3);
};

class third {
	int value3;
	public :
		third () {
			cout<<"Enter third number : ";
			cin>>value3;
		}
		
		friend void greatest (first ab1 , second ab2 , third ab3);
};

void greatest (first ab1 , second ab2 , third ab3) {
	cout<<"\nBefore compare number : ";
	cout<<ab1.value1<<" "<<ab2.value2<<" "<<ab3.value3<<endl;
	
	if(ab1.value1 > ab2.value2 && ab1.value1 > ab3.value3)
		cout<<"Here Largest number is : "<<ab1.value1<<endl;
	else if(ab2.value2 > ab1.value1 && ab2.value2 > ab3.value3)
		cout<<"Largest number is : "<<ab2.value2<<endl;
	else 
		cout<<"Largest number is : "<<ab3.value3<<endl;
}	

int main () {
	first first_obj;
	second second_obj;
	third third_obj;
	
	greatest (first_obj , second_obj , third_obj);
	
	return 200;
}
