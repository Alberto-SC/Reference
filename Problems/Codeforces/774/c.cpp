#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

vector<int> facts;
int best;

int solve(int n,int d = 0){
    if(!n)return 0;
    int x = __builtin_popcountl(n);
    if(d+x>best)return 1e15;
    cout<<n<<" "<<d<<endl;
    for(int i = 0;i<14;i++){
        if(facts[i]<=n)
            x = min(x,1+solve(n-facts[i],d+1));
    }
    return x;
}
signed main(){
    int t,n;
    cin>>t;
    int fact = 1,x;
    for(int i = 1;i<20;i++){
        fact*=i;
        if(fact>1e12)break;
        facts.push_back(fact);
    }
    while(t--){
        cin>>n;
        best = __builtin_popcountll(n);
        cout<<solve(n)<<endl;
    }
}   