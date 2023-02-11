#include<iostream>
using namespace std;

int main() {
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
     
    for(i = 0; i < 10; i++) {
            flags[i] = 0;
            allocation[i] = -1;
    }
        
    cout<<"Enter no. of blocks: ";
    cin>>bno;
        
    cout<<"\nEnter size of each block: ";
    for(i = 0; i < bno; i++) {
		cout<<"\nBlock no. "<<i+1<<": ";
        cin>>bsize[i];
	}
     
        cout<<"\nEnter no. of processes: ";
        cin>>pno;
        cout<<"\nEnter size of each process: ";
    for(i = 0; i < pno; i++) {
		cout<<"\nProcess size no. "<<i+1<<": ";
        cin>>psize[i];
	}
    for(i = 0; i < pno; i++)        
        for(j = 0; j < bno; j++)
            if(flags[j] == 0 && bsize[j] >= psize[i]) {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
        
        cout<<"\nBlock no.\tsize\t\tprocess no.\t\tsize";
        for(i = 0; i < bno; i++) {
            cout<<"\n"<< i+1<<"\t\t"<<bsize[i]<<"\t\t";
            if(flags[i] == 1)
                cout<<allocation[i]+1<<"\t\t\t"<<psize[allocation[i]];
            else
                cout<<"Not allocated";
        }
        
        return 0;
}

