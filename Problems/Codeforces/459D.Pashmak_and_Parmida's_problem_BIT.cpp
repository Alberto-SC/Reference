#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
typedef vector<int>::iterator it;
typedef long long int lli;
const int maxn = 1000007;

vector<int> bit(maxn);
int sum(int idx){
    int res = 0;
    for(++idx;idx>0;idx -= idx& -idx)res+=bit[idx];
    return res;
}

void add(int idx,int val){
    for(++idx;idx<maxn;idx+= idx&-idx)bit[idx]+=val;
}
int main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> copy(n);
    vector<int> uniques;
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        copy[i] = nums[i];
    }
    sort(copy.begin(),copy.end());
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    for(int i = 0;i<n;i++)
        nums[i]= lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
    vector<int> L(n);
    vector<int> R(n);
    vector<int> buck(uniques.size());
    for(int i = 0;i<n;i++){
        buck[nums[i]]++;
        L[i] = buck[nums[i]];
    }
    buck.assign(uniques.size(),0);
    for(int i = n-1;i>=0;i--){
        buck[nums[i]]++;
        R[i] = buck[nums[i]];
    }
    lli ans = 0;
    for(int i = n-1;i>0;i--){
        ans+= sum(L[i]-1);
        add(R[i],1);
    }
    cout<<ans<<endl;

    return 0;
}