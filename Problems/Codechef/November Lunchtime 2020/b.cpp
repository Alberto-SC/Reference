#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}
int x,y;
int DP[32][2];
vector<int> Num;
int go(int pos,int f,int xz,int xy){
    if(pos == Num.size()){
        if(xz<xy)
            return 1;
        return 0;
    }
    int &x = DP[pos][f];
    // if(x!= -1)return x;
    int res = 0;
    int LIM ;
    if(!f)LIM = Num[pos];
    else LIM = 1;
    for(int i =0;i<=LIM;i++){
        int nf = f;
        if(i<LIM)nf = 1;
        res +=go(pos+1,nf,(xz<<1) | ((x>>(31-pos))&1)^i,(xy<<1) | ((y>>(31-pos))&1)^i);
    }
    return x = res;
}

int solve(int n){
    Num.clear();
    for(int i = 0;i<32;i++){
        if((n>>i)&1)Num.push_back(1);
        else Num.push_back(0);
    }
    memset(DP,-1,sizeof(DP));
    reverse(Num.begin(),Num.end());
    return go(0,0,0,0);
}
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>x>>y>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}  

