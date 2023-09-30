#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int trie[10000000][2];
int val[10000000];
int key = 1;
int k;
int newNode(){
    trie[key][0] = -1;
    trie[key][1] = -1;
    return key++; 
}

void add(int x){
    int u = 0;
    for(int i = k-1;i>=0;i--){
        int bit = (x>>i)&1;
        if(trie[u][bit] == -1)
            trie[u][bit] = newNode();
        u = trie[u][bit];
    }

    val[u] = x;
}

int bestAnd(int x){
    int u = 0;
    for(int i = k-1;i>=0;i--){
        int bit = (x>>i)&1;
        if(trie[u][bit]!= -1)
            u = trie[u][bit];
        else 
            u = trie[u][!bit];
    }
    return val[u];
}

signed main(){
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n>>k;
        key = 1;
        trie[0][0] = -1;
        trie[0][1] = -1;
        vector<int> nums(n);
        map<int,int> mp;
        int id = 0;
        for(auto &c:nums){
            cin>>c;
            if(mp.count(c)==0)mp[c]= id++;
        }

        int N = (1ll<<k)-1;
        int ans = -1;

        int ai = 0,aj = 0,x =0;

        for(int i = 0;i<n;i++){
            if(i){
                int best = bestAnd(nums[i]);
                int res = (best&nums[i]) | (N^(best^nums[i]));
                if(res>ans){
                    ans = res;
                    ai = mp[best];
                    aj = i;
                    x = 0;
                    for(int j = k-1;j>=0;j--){
                        if(res&(1ll<<j) && (nums[i]&(1ll<<j)) == 0){
                            x|= (1ll<<j);
                        }
                    }
                }
            }
            add(nums[i]);
        }
        cout<<ai+1<<" "<<aj+1<<" "<<x<<endl;
    
    }
    return 0;
}