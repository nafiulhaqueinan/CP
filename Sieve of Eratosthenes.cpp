#include<bits/stdc++.h>
using namespace std;
vector<bool>sieve(int n){
    vector<bool> prime(n,1);
    prime[0]=prime[1]=0;
    for(int i=2;i*i<n;i++){
        if(prime[i]){
            for(int j=i*i;j<n;j+=i)
                prime[j]=0;
        }
    }
    return prime;
}




int32_t main(){
    int n=1000;
    vector<bool> v;
    v=sieve(n);
    for(int i=0;i<n;i++){
        if(v[i]==1){
            cout<<i<<" ";
        }
    }



return 0;
}
