#include<iostream>
using namespace std;

int main () {
	int list[100] , n;
	cout<<"Enter array size : ";
	cin>>n;
	
	cout<<"Enter array elements : ";
	for(int i=0; i<=n-1; i++)
		cin>>list[i];
		
	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++) {
			if(list[j] > list[j+1]) {
				int temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
	
	cout<<"After sorted : ";	
	for(int i=1; i<=n; i++)
		cout<<list[i]<<" ";
		
	return 200;
}
