#include<iostream>
using namespace std;

void menu() {
	cout<<"\n\t***********MENU************"<<endl;
	cout<<"\t	1.for diposite "<<endl;
	cout<<"\t	2.for withdraw "<<endl;
	cout<<"\t	3.for displaty "<<endl;
	cout<<"\t	4.for exit "<<endl;
	cout<<"\n\t****************************"<<endl;
}

int main () {
	double city,diposite,withdraw;
	int choice;
	
	cout<<"\tEnter your bank amount : ";
	cin>>city;
	
	menu();
	cout<<"\n\tYour accout is ready now, your account balance is : "<<city<<endl;
	do {
		cout<<"\n\tEnter your choice : ";
		cin>>choice;
		
		if(choice == 1) {
			cout<<"\tDiposite : ";
			cin>>diposite;
			city += diposite;	
		}
		else if(choice == 2) {
			cout<<"\n\tWithdaraw money : ";
			cin>>withdraw;
			
			if(city >= withdraw) {
				city -= withdraw;
			}
			else
				cout<<"\n\tYou have not enough money ."<<endl;
		}
		else if(choice == 3)
			cout<<"\tNow your balance : "<<city<<endl;		
		else if(choice == 4) {
			cout<<"		Exit "<<endl;
			break;
		}
		else
			cout<<"\n\tInvalid choice "<<endl;
	} while(choice != 4);
	
	
	return 100;
}
