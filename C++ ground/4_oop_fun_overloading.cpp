#include<iostream>
using namespace std;

void area_calculate (float half ,float base , float height) {
	cout<<"Area of triangle : "<<half * base * height<<endl;
}

void area_calculate (float radius) {
	cout<<"Area of circle : "<<3.1416 * radius * radius<<endl;
}

void area_calculate (float width , float length) {
	cout<<"Area of rectangle : "<<width * length<<endl;
}

int main () {
	int w,l;
	int r;
	int height , base; 
	
	cout<<"Enter triangle value : "<<endl;
	cout<<"Enter base : ";
	cin>>w;
	cout<<"\nEnter height : ";
	cin>>l;
	
	cout<<"\n\nEnter circle value : "<<endl;
	cout<<"Enter radius : ";
	cin>>r;
	
	cout<<"Enter rectangle value : "<<endl;
	cout<<"Enter width : ";
	cin>>height;
	cout<<"\nEnter length : ";
	cin>>base;
	
	area_calculate(0.5 , w , l);
	area_calculate(r);
	area_calculate(height , base);
	
	return 200;
}
