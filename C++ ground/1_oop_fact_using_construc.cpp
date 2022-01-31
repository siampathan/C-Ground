#include<iostream>
using namespace std;

class fact {
	int num , result;
	public :
		fact () {
			cout<<"Enter a number : ";
			cin>>num;
			result = 0;
		}
		
		void calculate_data();
};

void fact :: calculate_data() {
	result = 1;
	for(int i=1; i<=num; i++)
		result *= i;
		
	cout<<"Factorial is : "<<result<<endl;
}

int main () {
	fact obj;
	obj.calculate_data();
	
	return 200;
}
