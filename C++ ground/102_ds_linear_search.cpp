#include<iostream>
using namespace std;

int main () {
	int list[100] , n;
	int index = -1 , data;
	
	cout<<"Enter array size : ";
	cin>>n;
	
	cout<<"Enter array element : ";
	for(int i=0; i<n; i++)
		cin>>list[i];
		
	cout<<"\nEnter which element you want : ";
	cin>>data;
	
	for(int j=0; j<n-1; j++)
		if(list[j] == data) {
			index = j;
			break;
		}
		
	if(index == -1)
		cout<<"Data not found in this array ."<<endl;
	else 
		cout<<"Data found at index no : "<<index<<endl;
		
	return 200;
}
