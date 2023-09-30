#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

const int mod = 1e9+7;

const int maxn = 1000007;
int dp[maxn][3];

int N;

vector<int> v;

int mod_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1)(x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}


int solve(int idx,int last = 2,int type = 0){
    if(idx == N){
        if(type == 0)
            return last == 1;
        return last == 0;
    }
    int &x = dp[idx][last];
    if(x!=-1)return x;
    int ans = 0;
    if(last == 2){
        if(type ==0){
            if(idx&1)
                (ans+=solve(idx+1,1,type)*(mod_pow(2,v[idx])-1))%=mod;
            (ans+=solve(idx+1,2,type))%=mod;
        }
        
        else if(type ==1){
            if(!(idx&1)){
                (ans+=solve(idx+1,0,type)*(mod_pow(2,v[idx])-1))%=mod;
            }
            (ans+=solve(idx+1,2,type))%=mod;
        }
    }
    else{
        (ans += solve(idx+1,last,type))%=mod;
        (ans += solve(idx+1,idx&1,type)*(mod_pow(2,v[idx])-1))%=mod;
    }

    return x= ans;
}

signed main(){__
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        v.clear();
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && s[i]==s[j]){
                j++;
            }

            v.push_back(j-i);
            i = j;
        }
        N = v.size();
        for(int i = 0;i<N;i++)dp[i][0] =dp[i][1]= dp[i][2]  = -1;
            
        int ans = solve(0,2,0);
        for(int i = 0;i<N;i++)dp[i][0] =dp[i][1] = dp[i][2] = -1;
        ans+=solve(0,2,1);
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}

