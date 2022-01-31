#include<iostream>
using namespace std;

class complex {
	public :
		int real , imag;
		
		complex () {
			real = 0;
			imag = 0;
		}
		complex (int tempReal , int tempImag) {
			real = tempReal;
			imag = tempImag;
		}
		
		complex addComp (complex c1 , complex c2) {
			complex temp;
			temp.real = c1.real + c2.real;
			temp.imag = c1.imag + c2.imag;
			return temp;
		}
};

int main () {
	int real1,real2,imag1,imag2;
	
	cout<<"Enter first complex number element : "<<endl;
	cout<<"\nreal number : ";
	cin>>real1;
	cout<<"\nimag number : ";
	cin>>imag1;
	
	complex c1(real1 , imag1);
	cout<<"First complex number : "<<c1.real<<" + "<<c1.imag<<"i"<<endl;
	
	cout<<"\nEnter second complex number element : "<<endl;
	cout<<"\nreal number : ";
	cin>>real2;
	cout<<"\nimag number : ";
	cin>>imag2;
	
	complex c2(real2 , imag2);
	cout<<"Second complecx number : "<<c2.real<<" + "<<c2.imag<<endl;
	
	complex c3;
	c3 = c3.addComp(c1 ,c2);
	cout<<"Sum of complex number is : "<<c3.real <<" + "<<c3.imag<<"i"<<endl;
	
	return 200;
}
