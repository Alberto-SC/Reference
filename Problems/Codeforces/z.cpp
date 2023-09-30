#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
bool comp(pair<int,pair<int,int>> A,pair<int,pair<int,int>>B){
    return A.second.second<B.second.second;
}
#define maxn 1000007
using namespace std;
int bit[maxn];
int n;

int sum(int i){
    int ans = 0;
    for(++i;i>0;i-= i&-i)ans^=bit[i];
    return ans;
}
void add(int i, int v){
    for(++i;i<=n;i+= i&-i)bit[i]^=v;
}
int sum(int a ,int b){
    return sum(b)^sum(a-1);
}
void printbit(){
    for(int i =0;i<n;i++){
        cout<<sum(i,i)<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    int m,l,r;
    cin>>n;
    // bit.resize(n+7,0);
    vector<int> nums(n+1);
    vector<int> ac(n+1);
    for(int i = 1;i<=n;i++){
        cin>>nums[i];
        ac[i] = ac[i-1]^nums[i];
    }
    cin>>m;
    vector<pair<int,int>> q[n];
    for(int i=0;i<m;i++){
        cin>>l>>r;
        l--;
        r--;
        q[r].push_back( make_pair(l,i) );
    } 
    vector<int> ans(m);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int now=nums[i+1];
        if(mp.count(now))add(mp[now],now);
        add(i,now);
        mp[now]=i;
        // printbit();
        for(int j=0;j<q[i].size();j++){
            pair<int,int> seg=q[i][j];
            int l=seg.first,r=i;
            ans[seg.second] = sum(l,r)^ac[r+1]^ac[l];
        }
    }
    
    for(auto c:ans)cout<<c<<"\n";

    return 0;
}