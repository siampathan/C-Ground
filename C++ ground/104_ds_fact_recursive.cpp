#include<iostream>
using namespace std;

int fact(int n) {
	int f;
	if(n == 1)
		return 1;
	else 
		f = n * fact(n - 1);
}

int main () {
	int n , f;
	
	cout<<"Enter a number : ";
	cin>>n;
	f = fact(n);
	cout<<"Factorial is : "<<f<<endl;
	
	return 20;
}
