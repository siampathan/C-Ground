#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    
    vector<int> base(n+1, 1);
    for(int i=2;i*i<=n;i++){
        if(!base[i]) continue;
        for(ll k = i*i; k <= n; k *= i){
            base[k] = false;
        }
    }
    
    set<int> pars;
    vector<ll> num_pow;
    num_pow.push_back(0); 
    for(int i=1;i<20;i++){
        if((1 << i) > n) break; 
        for(int j=2;j<=n;j++){

            pars.insert(i*j);
        }
        num_pow.push_back(pars.size());
    }
    
    ll ans = 0;
    for(int a=2;a<=n;a++){
        if(base[a]){
            ll k =a;
            int pw = 1;
            while(k <= n){
                k *= a;
                pw++;
            }pw--;
            ans += num_pow[pw];
        }
    }
    
    cout << ans <<endl;
    
}