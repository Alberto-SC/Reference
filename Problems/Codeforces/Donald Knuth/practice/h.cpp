#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k,a,b,c;
    string A,B,P;
    cin>>a>>b>>c;
    cin>>A>>B>>P;
    int s1 = 0,s2 = 0,s3 = 0;
    for(int i = 0;i<a;i++)
        s1+=A[i]-'0';
    for(int i = 0;i<b;i++)
        s2+=B[i]-'0';
    int x = (s1*s2)%9;
    for(int i = 0;i<c;i++){
        if(P[i]=='*')continue;
        s3+=P[i]-'0';
    }
    s3%=9;
    x-=s3%9;
    if(x<=0)x+=9;
    cout<<x<<endl;
    return 0;
}  
