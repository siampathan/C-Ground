#include<iostream>
using namespace std;

int main () {
	int list[100] , n , data;
	
	cout<<"Enter array size : ";
	cin>>n;
	cout<<"\nEnter array element :";
	for(int i=0; i<n; i++)
		cin>>list[i];
		
	int first = 0 , last = n - 1 , mid = (first + last) / 2;
	cout<<"\nEnter which element you want : ";
	cin>>data;
	
	while(first <= last) {
		if(list[mid] < data)
			first = mid + 1;
		else if(list[mid] == data){
			cout<<"Data found at index : "<<mid<<endl;
			break;
		}
		else 
			last = mid - 1;
			mid = (first + last) / 2;
	}
	
	if(first > last)
		cout<<"\nData not found at this array ."<<endl;
		
	return 200;
}
