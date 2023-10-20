vector<int> spf(int n){
    vector<int> s(n,-1);
    for(int i=2;i<n;i++){
        if(s[i]== -1){
            for(int j=i;j<n;j+=i) if(s[j]== -1) s[j]= i;
        }
    }
    return s;
}
