#include<iostream>
using namespace std;

class TIME {

        int hr,min,sec;
        public:
            void get() {
                cout<<"\nEnter Hour : ";
                cin>>hr;
                cout<<"\nEnter Minutes : ";
                cin>>min;
                cout<<"\nEnter Seconds : ";
                cin>>sec;      
            }    

            void disp() {
                cout<<hr<<":"<<min<<":"<<sec<<endl;
           }
            void sum(TIME &,TIME &);
    };

void TIME::sum(TIME &t1,TIME &t2) {
        sec=t1.sec+t2.sec;
        min=sec/60;
        sec=sec%60;
        min=min+t1.min+t2.min;
        hr=min/60;
        min=min%60;
        hr=hr+t1.hr+t2.hr;
    }

int main() {
	
        TIME t1,t2,t3;
        cout<<"\nEnter 1st time Details : \n";
        t1.get();
        cout<<"\nEnter 2nd time Details : \n";
        t2.get();
        cout<<"\nThe 1st time entered is : ";
        t1.disp();
        cout<<"\nThe 2nd time entered is : ";
        t2.disp();
        t3.sum(t1,t2);

        cout<<"\nThe Sum of two times are : ";
		t3.disp();

        return 0;
    }
