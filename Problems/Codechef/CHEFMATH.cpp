#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
#define endl '\n'

map<pair<pair<int,int>,int>,int> dp;
vector<int> fibo = {1,2};

const int mod = 1e9+7;
vector<int> res;
int solve(int k,int n,int last){
    // cout<<k<<" - "<<n<<" - "<<last<<endl;
    if(k<0)return 0;
    if(n<0)return 0;
    if(k == 0 && n == 0){
        // for(auto c:res)cout<<c<<" ";
        // cout<<endl;
        return 1;
    }
    if(k == 0 && n)return 0;
    if(n == 0 && k)return 0;
    if(dp.count({{n,k},last})){
        return dp[{{n,k},last}];
    }
    int ans = 0;
    for(int i = 0;fibo[i]<=last;i++){
        res.push_back(fibo[i]);
        ans+=solve(k-1,n-fibo[i],fibo[i]);
        res.pop_back();
        ans%=mod;
    }
    dp[{{n,k},last}] = ans;
    return dp[{{n,k},last}];
}

int modpow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

signed main(){
    int t,n,k;
    cin>>t;
    for(int i = 2;i<80;i++)
        fibo.push_back(fibo[i-1]+fibo[i-2]);
    while(t--){
        cin>>n>>k;
        int sz = upper_bound(fibo.begin(),fibo.end(),n)-fibo.begin();

        map<pair<int,int>,int> L;
        map<pair<int,int>,int> R;
        int m = sz/2;
        cout<<m<<endl;
        for(int mask = 0;mask<1<<m;mask++){
            int x = __builtin_popcount(mask);
            int sum = 0;
            bitset<6> bst(mask);
            for(int i = 0;i<m;i++){
                if((mask>>i)&1)sum+=fibo[i];
            }            
            cout<<bst<<" "<<sum<<endl;
            L[{x,sum}]++;
        }
        cout<<endl;
        for(int mask = 0;mask<1<<sz-m;mask++){
            int x = __builtin_popcount(mask);
            int sum = 0;
            bitset<6> bst(mask);
            bst<<=m;
            for(int i = 0;i<m;i++){
                if((mask>>i)&1)sum+=fibo[i+m];
            }
            cout<<bst<<" "<<sum<<endl;
            R[{x,sum}]++;
        }
        cout<<endl;
        int ans = 0;
        map<pair<int,int>,bool> used;
        for(int mask = 0;mask<1<<m;mask++){
            int x = __builtin_popcount(mask);
            if(x>k)continue;
            int sum = 0;
            for(int i= 0;i<m;i++){
                if((mask>>i)&1)sum+=fibo[i];
            }
            bitset<6> bst(mask);
            cout<<bst<<" "<<sum<<" "<<L[{x,sum}]<<" "<<R[{k-x,n-sum}]<<" "<<n-sum<<endl;
            if(sum>n)break;
            if(used[{x,sum}])continue;

            ans+=R[{k-x,n-sum}]* L[{x,sum}];
            ans%=mod;
            used[{x,sum}] = true;
        }
        int x = solve(k,n,n);
        cout<<ans<<endl;
        cout<<x<<endl;
    }
    return 0;
}