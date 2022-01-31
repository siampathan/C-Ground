#include<iostream>
using namespace std;

class student {
    char name[15],semester[10],section[10];
    int roll,number;
    double subject;
    double total;
    
    public:
        void input_data();
        void calculate_markes();
        void display_data();
};

void student::input_data() {
    cout<<"Enter the student name : ";
    cin>>name;
    cout<<"Enter the student roll : ";
    cin>>roll;
    cout<<"Enter the student semester : ";
    cin>>semester;
    cout<<"Enter the student section : ";
    cin>>section;
}

void student::calculate_markes () {
    cout<<"Enter the number of  subjects : ";
    cin>> number;
    for(int i=1; i<=number; i++){
        cout<<"Enter "<<i<<"st subject : ";
        cin>>subject; 
        total += subject;
    }
}   

void student::display_data () {
    
    cout<<"\nStudent name is : "<<name<<endl;
    cout<<"Student roll is : "<<roll<<endl;
    cout<<"Student semester is : "<<semester<<endl;
    cout<<"Student section is : "<<section<<endl;
    cout<<"Total markes is : "<<total<<endl;
}

int main() {
    student data;
    
    data.input_data();
    data.calculate_markes();
    data.display_data();
    
    return 0;
}
