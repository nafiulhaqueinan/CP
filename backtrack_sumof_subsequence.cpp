/*
	Author : LazyWizard(Md.Nafiul Haque)
"Success is not final,
 failure is not fatal: 
 it is the courage to continue that counts."
  - Winston Churchill
*/


#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#ifndef _GLIBCXX_NO_ASSERT
//#include<cassert>
#endif
//it for C++11 standard or later is supported by the compiler.
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
//#include <cuchar>
#endif
// Declaring Ordered Set
/*typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
    pbds;
*/
#define     INF 100000000000000007
#define     pii 3.14159265358979323846264338327
#define     modd 100010
#define fb find_by_order
#define ok order_of_key
#define mem(x,y) memset(x,y,sizeof x)//set arr x to value y for all element ;
#define endl        "\n"
#define int         long long int
#define pb          push_back
#define pf          push_front
#define F           first
#define S           second
#define vint        std::vector<int> 
#define mp          midpoint
#define READ(x)     freopen(x,"r",stdin)
#define WRITE(x)    freopen(x,"w",stdout)
#define BOOST       ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define chk         printf("Came Here!!!!!!!!!!!!!!!\n")
#define bug(...) __f (#__VA_ARGS__,__VA_ARGS__)
#define fr(i,n)     for(int i=0; i<(n); i++)
#define rep(i,a,n)  for(int i=(a);i<=(n);i++)
#define fat(n)      for(auto x:n)
#define srt(v)      sort(v.begin(),v.end())
#define all(v)      v.begin(),v.end()
#define mxe(v)      *max_element(all(v))// find max element in vector
#define mne(v)      *min_element(all(v))// find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));// remove all duplicate from vector
//make sure to sort before use unq

template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

void modadd(int &a , int b) {a=((a%modd)+(b%modd))%modd;}
void modsub(int &a , int b) {a=((a%modd)-(b%modd)+modd)%modd;}
void modmul(int &a , int b) {a=((a%modd)*(b%modd))%modd;}

typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef pair<int,int> pi;

inline int modmul(int a,int b,int mod){
    int ans =0;
    a=a%mod;
    while (b>0)
    {
        if(b%2)ans=(ans%mod + a%mod)%mod;
        a=(a%mod * 2%mod)%mod;
        b/=2;
    }
    return ans%mod;
}
// rounds up the division
int rup(int ik,int ikk){if(ik%ikk==0) return ik/ikk;else return (ik/ikk)+1;}
int gcd(int a,int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return (a*b)/gcd(a,b);}
int modpow(int x1,int n1,int m1){
    if (n1 == 0) return 1%m1;
    int u1 = modpow(x1,n1/2,m1);
    u1 = (u1*u1)%m1;
    if (n1%2 == 1) u1 = (u1*x1)%m1;
    return u1;
}
int npow(int a,int b){
    if(b==0) return 1;
    int c=npow(a,b/2);
    int u=c*c;
    if(b%2==1)u*=a;
    return u;
}
//provide a fast, non-cryptographic hash 
// struct boost{
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
int c=0;
void sumcount(int i,int sum,vi v,int n,int target){
	if(i==n){
		if(sum==target)
			c++;
		return;
	}
	sumcount(i+1,sum+v[i],v,n,target);
	sumcount(i+1,sum,v,n,target);
}
int sumcount2(int i,int sum,vi v,int n,int target){
	if(i==n){
		if(sum==target){
			return 1;
		}
		return 0;
	}
	int pick = sumcount2(i+1,sum+v[i],v,n,target);
	int no_pick = sumcount2(i+1,sum,v,n,target);
	return pick+no_pick;
}
void solve(){
   int n,x;cin>>n>>x;
   vi v(n);
   fr(i,n){cin>>v[i];}
   sumcount(0,0,v,n,x);
   cout<<c<<endl;
   cout<<sumcount2(0,0,v,n,x)<<endl;
}

int32_t main(){
    BOOST;
    #ifndef ONLINE_JUDGE
    READ("in.txt");
    WRITE("o.txt");
    #endif
    clock_t z = clock();
    int t=1;
    //cin>>t;
    while (t--){solve();}
    cerr << "\nRun Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}
