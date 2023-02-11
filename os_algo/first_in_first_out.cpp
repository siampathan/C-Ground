#include<iostream>
using namespace std;

int main() {
int i,j,n,ref_str[50],frame[10],no,k,avail,fcount=0;  
	cout<<"\n ENTER THE NUMBER OF PAGES:\n";
	cin>>n;                                       
	cout<<"\n ENTER THE PAGE NUMBER :\n";
	
    for(i=1;i<=n;i++)                                 
       cin>>ref_str[i];
       
	cout<<"\n ENTER THE NUMBER OF FRAMES :";
	cin>>no;
	
    for(i=0;i<no;i++)
        frame[i]= -1; 
		 
	j=0;                          
	cout<<"\n ref string  \t page frames     \tHit/Fault\n";
	
    for(i=1;i<=n;i++) {
        cout<<ref_str[i]<<"\t\t";
            avail=0;
			          
    for(k=0;k<no;k++)
        if(frame[k]==ref_str[i]){
            avail=1;       
            for(k=0;k<no;k++)
                cout<<frame[k]<<"\t";  
                    cout<<"H";                       
        }
        
        if (avail==0) {
            frame[j]=ref_str[i];       
            j=(j+1)%no;          
            fcount++;                
            for(k=0;k<no;k++)
            cout<<frame[k]<<"\t";  
            cout<<"F"      ;
        }
        cout<<endl;
    }
    
cout<<"Page Fault Is "<<fcount;
return 0;
}
