#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int maxn = 100007;
vector<int> bit(maxn);

int sum(int idx){
    int x = 0;
    for(++idx;idx>0;idx-= idx&-idx){
        x+= bit[idx];
    }
    return x;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}
int add(int idx,int x){
    for(++idx;idx<maxn;idx+= idx&-idx)bit[idx]+=x;
}


int main(){__
	int t= 1,n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<int> copy = nums;
    sort(copy.begin(),copy.end());
    int last = copy[0];
    vector<int> u;
    u.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            u.push_back(last);
        }
    }
    for(int i = 0;i<n;i++)
        nums[i] =lower_bound(u.begin(),u.end(),nums[i])-u.begin();
    
    int ans = 0;
    vector<int> left(n);
    vector<int> right(n);
    for(int i = 0;i<n;i++){
        left[i] = sum(nums[i]);
        add(nums[i],1);
    }
    bit.assign(maxn,0);
    for(int i = n-1;i>=0;i--){
        right[i] = sum(nums[i]);
        add(nums[i],1);
    }
    
    for(int i = 0;i<n;i++){
        // cout<<left[i]<<" "<<right[i]<<endl;
        ans+= min(left[i],right[i]);
    }
    cout<<ans<<endl;
    return 0;
}  

