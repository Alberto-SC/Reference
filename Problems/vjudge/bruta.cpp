#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
int a,b,k;
int DP[12][200][2][200];
vector<int> Num;
int go(int pos,int sum,int f,int numR){
    if(pos == Num.size()){
        if(numR%k == 0 && sum%k == 0){
            return 1;
        }
        else return 0;
    }
    int &x = DP[pos][sum][f][numR];
    if(x!= -1)return x;
    int res = 0;
    int LIM ;
    if(!f)LIM = Num[pos];
    else LIM = 9;
    for(int i =0;i<=LIM;i++){
        int nwNum = ((numR*10)+i)%k;
        int nwRem = (sum+i)%k;
        int nf = f;
        if(i<LIM)nf = 1;
        res +=go(pos+1,nwRem,nf,nwNum);
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
    while(t--){
        cin>>k;
        int ans =0;
        for(int i = 1;i<=10000;i++){
            int aux = i;
            int sum = 0;
            while(aux){
                sum+=aux%10;
                aux/=10;
            }
            if(sum%k == 0 && i%k == 0)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}