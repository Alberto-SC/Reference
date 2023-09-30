#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


const int maxk = 62;
const int maxn = 1e5+7;
vector<int> bit[maxk];

void add(int idx,int val,int who){
    for(++idx;idx<maxn;idx+= idx&-idx)bit[who][idx]+=val;
}

int sum(int idx,int who){
    int res = 0;
    for(++idx;idx>0;idx-=idx&-idx)res+=bit[who][idx];
    return res;
}

int sum(int l,int r,int who){
    return sum(r,who)-sum(l-1,who);
}

void print(int k,int n){
    for(int i = 0;i<n;i++){
        cout<<sum(i,i,k)<<" ";
    }
    cout<<endl;
}

signed main(){__
    int T = 1,n,q;
    for(int i =0;i<62;i++)
        bit[i].resize(maxn);
    
    cin>>T;
    while(T--){
        cin>>n>>q;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        for(int i = 0;i<60;i++){
            for(int j = 0;j<n;j++){
                add(j,(nums[j]>>i)&1,i);
            }
            // print(i,n);
        }
        while(q--){
            int l1,r1,l2,r2,k;
            cin>>k>>l1>>r1>>l2>>r2;
            l1--,r1--,l2--,r2--;
            int len1 = (r1-l1)+1;
            int len2 = (r2-l2)+1;

            int sum1 = sum(l1,r1,k);
            int sum2 = sum(l2,r2,k);

            // cout<<len1<<" "<<len2<<" "<<sum1<<" "<<sum2<<endl;
            int ans = sum1*(len2-sum2);
            ans+= (len1-sum1)*sum2;
            cout<<ans<<endl;
        }
        for(int i = 0;i<60;i++){
            for(int j = 0;j<n;j++){
                add(j,-((nums[j]>>i)&1),i);
            }
            // print(i,n);
        }
    }
    return 0;
}