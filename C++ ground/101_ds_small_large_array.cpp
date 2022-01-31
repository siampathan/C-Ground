#include<iostream>
using namespace std;

int main () {
	int list[100];
	int n,max,min;
	
	cout<<"Enter array Size : ";
	cin>>n;
	
	cout<<"Enter array element : ";
	for(int i=0; i<n; i++)
		cin>>list[i];
		
	max = list[0];
	min = list[0];
	
	for(int j=0; j<n; j++) {
		if(list[j] > max)
			max = list[j];
		if(list[j] < min)
			min = list[j];
	}
	
	cout<<"Large Element : "<<max<<" "<<"\nSmall Element : "<<min<<endl;
	
	return 200;
}
