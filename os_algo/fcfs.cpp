#include<iostream>
using namespace std;

int waitingtime(int proc[], int n,int burst_time[], int wait_time[]) {
   wait_time[0] = 0;
 
   for (int i = 1; i < n ; i++ )
   wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}

int turnaroundtime( int proc[], int n,int burst_time[], int wait_time[], int tat[]) {
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}

int avgtime( int proc[], int n, int burst_time[]) {
   int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
   int i;

   waitingtime(proc, n, burst_time, wait_time);

   turnaroundtime(proc, n, burst_time, wait_time, tat);

   cout<<"Processes   Burst    Waiting  Turn around ";

   for ( i=0; i<n; i++) {
      total_wt +=  wait_time[i];
      total_tat += tat[i];
      cout<<"\n "<<i+1<<"\t\t"<<burst_time[i]<<"\t"<<wait_time[i]<<"\t"<<tat[i]<<endl;
   }
   cout<<endl;
   cout<<"Average waiting time ="<<(float)total_wt / (float)n<<endl;
  cout<<"Average turn around time = "<<(float)total_tat / (float)n;
   return 0;
}

int main() {
   int proc[] = { 1, 2, 3};
   int n = sizeof proc / sizeof proc[0];
   int burst_time[] = {5, 8, 12};
   avgtime(proc, n, burst_time);
   return 0;
}


//if you want to convert in C just change cout<< to printf() and header file <stdio.h> 
//remove using namespace std;
