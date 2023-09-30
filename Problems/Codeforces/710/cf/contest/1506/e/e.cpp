#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 200007;
vector<int> bit(maxn);

int sum(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)ret += bit[idx];
    return ret;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void add(int idx, int delta) {
    for (++idx; idx < maxn; idx += idx & -idx) bit[idx] += delta;
}

void print(int n){
    for(int i = 0;i<=n;i++)
        cout<<sum(i,i)<<" ";
    cout<<endl;
}
signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        vector<int> mn(n);
        vector<int> mx(n);
        int last = 0;
        set<int> smn;
        for(int i = 1;i<=n;i++)
            smn.insert(i),add(i,1);
        for(int i = 0;i<n;i++){
            if(nums[i]!=last){
                mn[i] = nums[i];
                mx[i] = nums[i];
                add(nums[i],-1);
                smn.erase(nums[i]);
                last = nums[i];
            }
            else{
                mn[i]= *smn.begin();
                smn.erase(smn.begin());
                int l =0,r = nums[i];   
                while(l+1<r){
                    int m = (l+r)>>1;
                    if(sum(m,nums[i])>=1)
                        l = m;
                    else 
                        r = m;
                }
                mx[i] = l;
                add(l,-1);
            }
            // print(n);
        }
        for(auto c:mn)cout<<c<<" ";
        cout<<endl;
        for(auto c:mx)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  

// 3 3 4 4 7 7 7 
// 3 


// 1 1 0 1 1 1 1 