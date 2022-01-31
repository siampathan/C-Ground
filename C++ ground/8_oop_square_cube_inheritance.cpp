#include<iostream>
using namespace std;

class calculateData {
	 protected: 
		int number;
		
	public:
		void input () {
			cout<<"Enter a number : ";
			cin>>number;
		}
};

class calculate: public calculateData { 
	int squr,cube;
	public:
		void squrCalculate () {
			squr = number * number;
		}
		
		void cubeCalculate () { 
			cube = number * number * number;
		}
		
	void output () {
		cout<<"\nResult of Square : "<<squr;  
		cout<<"\nResult of Cube : "<<cube;	
	}
};

int main () {
	calculate data;
	data.input();
	data.squrCalculate();
	data.cubeCalculate();
	data.output();
	
	return 0;
}
