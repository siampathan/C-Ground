#include<iostream>
#include<fstream>
using namespace std;

int main () {
	string str;
	
	cout<<"Enter your speech : ";
	getline(cin,str);
	
	ofstream file;
		
		file.open("siam.txt"); 
		file<<"\nDisplay speech : "<<str;  
		      
		file.close();
}
