#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli DP[10][2][10][2];

vector<int> num;
string snum;
lli go(int idx,int f,int tlz,int fz){
    if(idx == num.size()){
        // cout<<snum<<endl;
        int j = 0;
        while(snum[j]== '0')j++;
        for(int i = j,k = 0;i<snum.size();i++,k++){
            if(snum[i]!= snum[snum.size()-1-k])return 0;
        }
        // cout<<snum<<" "<<tlz<<endl;
        return 1;
    }
    lli &x = DP[idx][f][tlz][fz];
    // if(x!= -1 && fz){
        // cout<<snum<<" "<<tlz<<" "<<fz<<" "<<x<<endl;
        // return x;
    // }
    int LIM;
    if(f)LIM = 9;
    else LIM = num[idx];
    lli ans = 0;
    for(int i = 0;i<=LIM;i++){
        int nf = i<LIM?1:f;
        snum.push_back(i+'0');
        ans+=go(idx+1,nf,(i== 0 && fz == 0)?tlz+1:tlz,(i != 0)?1:fz);
        snum.pop_back();
    }
    return x = ans;

}

lli solve(lli n){
    num.clear();
    lli aux = n;
    while(aux){
        num.push_back(aux%10);
        aux/=10;
    }
    memset(DP,-1,sizeof(DP));
    reverse(num.begin(),num.end());
    for(auto c:num)cout<<c<<" ";
    cout<<endl;
    go(0,0,0,0);
}

int main(){
    lli a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1)<<endl;
    return 0;
}