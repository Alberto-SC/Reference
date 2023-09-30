#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	lli t= 1,n;
    vector<lli> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    lli mod = (1ll<<31)-1;
    for(int i = 2;i<=10000;i++)
        fibo.push_back((fibo[i-1]+fibo[i-2])%mod);
    
    set<lli> st(fibo.begin(),fibo.end());
    cin>>t;
    while(t--){
        cin>>n;
        if(st.find(n)!= st.end())cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } 
    return 0;
}  

