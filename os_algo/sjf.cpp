#include<iostream>
using namespace std;

int main()
{
	int A[100][4]; 
	int n, total = 0, index, temp;
	float avg_wt, avg_tat;
	cout<<"Enter number of process: ";
	cin>>n;
	cout<<"Enter Burst Time:\n";

	for (int i = 0; i < n; i++) {
		cout<<"P"<<i + 1<<": ";
		cin>>A[i][1];
		A[i][0] = i + 1;
	}
	
	for (int i = 0; i < n; i++) {
		index = i;
		for (int j = i + 1; j < n; j++)
			 if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;

	for (int i = 1; i < n; i++) {
		A[i][2] = 0;
		for (int j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	cout<<"Proc	 BT	 WT	 TAT\n";

	for (int i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		cout<<"P"<<A[i][0]<<"\t "<<A[i][1]<<"\t "<<A[i][2]<<"\t "<<A[i][3]<<endl;

	}
	avg_tat = (float)total / n;
	cout<<"Average Waiting Time= "<<avg_wt;
	cout<<"\nAverage Turnaround Time= "<< avg_tat;
}

//if convert into C just change header file and cout<<,cin>> to printf(),scanf();

