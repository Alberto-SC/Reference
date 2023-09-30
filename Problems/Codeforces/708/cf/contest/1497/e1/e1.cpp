#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int prime[10000007] = { 0 }; 
int k[10000007] = { 0 };   
void Sieve() { 
    for (int i=1;i<10000001; i++) 
        k[i] = i; 
    for (int i = 2;i<10000001; i++) { 
        if (prime[i] == 0) 
            for (int j = i; j < 10000001; j += i) { 
                prime[j] = 1; 
                while (k[j] % (i * i) == 0) 
                    k[j] /= (i * i); 
            } 
    } 
} 

signed main(){__
	int t= 1,n,q;
    Sieve();
    cin>>t;
    while(t--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        unordered_map<int,int> mp;
        int ans = 0;
        vector<int> st(10000007);
        for(int i = 0;i<n;i++)
            st[k[nums[i]]]++;
        
        int l = 1;
        for(int i = 0;i<n;i++){
            // cout<<k[nums[i]]<<" ";
            if(mp.count(k[nums[i]])){
                if(q){
                    while(st[l]){
                        l++;
                    }
                    q--;
                    mp[l]++;
                    st[l]++;
                }
                else{
                    ans++;
                    mp.clear();
                    mp[k[nums[i]]]++;
                }
            }
            else mp[k[nums[i]]]++;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}  
