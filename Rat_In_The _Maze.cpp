#include<bits/stdc++.h>








using namespace std;
//4 way that why 4
int di[]={0,1,0,-1};
int dj[]={1,0,-1,0};
string dir="RULD";
bool isvalid(int i,int j,int n,int m,vector<vector<int>> &v){
	if(i>=0 and j>=0 and i<n and j<m and v[i][j]==0)return true;
	else return false;
}




void generate(int i,int j,int n,int m, vector<vector<int>> &v,string &path){
	if(i== n-1 and j==m-1){cout<<path<<endl;return;}
	v[i][j]=1;
	for(int a=0;a<4;a++){
		if(isvalid(i+di[a],j+dj[a],n,m,v)){path.push_back(dir[a]);
			generate(i+di[a],j+dj[a],n,m,v,path);
			path.pop_back();}}
	v[i][j]=0;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	int n,m;cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m,0));
	string path="";
	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>v[i][j];}}
	generate(0,0,n,m,v,path);
	return 0;
}
