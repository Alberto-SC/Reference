#include <bits/stdc++.h>
using namespace std;
struct query{
    int l,r,id;   
};
const int maxn = 100000;
vector<int> bit(maxn,0);
vector<int> nums;

int sum(int idx){
    int ans = 0;
    for(idx++;idx>0;idx-= idx & -idx)ans+=bit[idx];
    return ans;
}

int sum(int a,int b){
    return sum(b)-sum(a-1);
}

void add(int idx,int val){
    for(idx++;idx<maxn;idx+= idx & -idx)bit[idx]+=val;
}

int total = 0;
void add_Mo(int idx,bool side){
    if(!side)
        total+=sum(nums[idx]-1);
    else 
        total+=sum(nums[idx]+1,maxn-1);
    // cout<<sum(nums[idx]+1,maxn-1)<<endl;
    add(nums[idx],1);
}

void rem(int idx,bool side){
    if(!side)
        total-=sum(nums[idx]-1);
    else 
        total-=sum(nums[idx]+1,maxn-1);
    add(nums[idx],-1);
}

int block;
bool comp(query A,query B){
    int x = A.l/block;
    if(x != B.l/block)return x<B.l/block;
    // if(x & 1)
		return A.r < B.r;
	// return A.r > B.r;
}
int main(){
    int n,m,l,r;
    cin>>n;
    nums.resize(n);
    for(auto &c:nums)cin>>c;
    vector<int> copy = nums;
    sort(copy.begin(),copy.end());
    int id = 0;
    map<int,int>mp;
    for(auto c:copy)
        mp[c] = id++;
    for(auto &c:nums)c = mp[c];
    cin>>m;
    
    vector<int> ans(m);
    vector<query> q(m);
    for(int i= 0;i<m;i++){
        cin>>l>>r;
        q[i] = {l-1,r-1,i};
    }
    block = sqrt(n);
    sort(q.begin(),q.end(),comp);
    l = 0,r = -1;
    for(int i = 0;i<m;i++){
        while(l>q[i].l){
            l--;
            add_Mo(l,false);
        }
        while(r<q[i].r){
            r++;
            add_Mo(r,true);
        }
        while(l<q[i].l){
            rem(l,false);
            l++;
        }
        while(r>q[i].r){
            rem(r,true);
            r--;
        }
        ans[q[i].id] = total;
    }
    for(auto c:ans)cout<<c<<endl;
    return 0;
}