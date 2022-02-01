#include<iostream>
using namespace std;

void towerOfHanoi (int num , char A , char B , char C) {
	if(num == 0) 
		return;
	else{
		towerOfHanoi (num - 1 , A,C,B);
		cout<<"Move disk "<<num<<" from "<<A<<" to "<<C<<endl;
		towerOfHanoi(num -  1 , B,A,C);
	}
}

int main () {
	int numOfdisks;
	
	cout<<"Enter number of disks : ";
	cin>>numOfdisks;
	
	towerOfHanoi (numOfdisks , 'A','B','C');
	
	return 200;
}
