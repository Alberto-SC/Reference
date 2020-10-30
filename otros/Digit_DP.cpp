#include <bits/stdc++.h>
using namespace std;
int a,b,k;
int DP[20][2][200][200];
vector<int> Num;
int go(int pos,int f,int sum,int rem){
    if(pos == Num.size()){
        if(sum%k == 0 && rem%k == 0)
            return 1;
        return 0;
    }

    int &x = DP[pos][f][sum][rem];
    if(x!= -1)return x;
    int res = 0;
    int LIM ;
    if(!f)LIM = Num[pos];
    else LIM = 9;
    for(int i =0;i<=LIM;i++){
        int nf = f;
        if(i<LIM)nf = 1;
        res +=go(pos+1,nf,(sum+i)%k,(rem*10+i)%k);
    }
    return x = res;
}

int solve(int n){
    Num.clear();
    while(n){
        Num.push_back(n%10);
        n/=10;
    }
    memset(DP,-1,sizeof(DP));
    reverse(Num.begin(),Num.end());
    return go(0,0,0,0);
}
int main(){
    int t;
    cin>>t;
    int cont = 1;
    while(t--){
        cin>>a>>b>>k;
        cout<<"Case "<<cont++<<": "<<solve(b)-solve(a-1)<<endl;
    }
    return 0;
}