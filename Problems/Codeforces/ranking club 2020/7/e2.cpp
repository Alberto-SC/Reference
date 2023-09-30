#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long int lli;
const int maxn = 100007;
#define x first 
#define y second
vector<int> bit(maxn);
struct query{
    int l,r,id;
};
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
int raiz;
bool comp(query x, query y){
    int aux = x.l/raiz;
    if (aux != y.l/raiz)
        return x.l < y.l;
    if(aux & 1)
		return x.r < y.r;
	return x.r > y.r;
}

void printbit(){
    for(int i = 0;i<10;i++){
        cout<<sum(i,i)<<" ";
    }
    cout<<endl; 
}
int main(){__
    int n,m,t,v,l,r,z,a,b;
    cin>>n>>m;
    vector<int> nums(n);
    raiz = ceil(sqrt(n*1.0));
    for(auto &c:nums)cin>>c;
    vector<query>querys;
    vector<pair<int,int>> AB;
    vector<int> ans(m);
    for(int i = 0;i<m;i++){
        cin>>l>>r>>a>>b;   
        l--,r--;  
        AB.push_back({a,b});      
        querys.push_back({l,r,i});
    }
    int L = 0,R = -1;
    vector<int> bk(maxn);
    sort(querys.begin(),querys.end(),comp);
    for(int i = 0;i<m;i++){
        // cout<<querys[i].l<<" "<<querys[i].r<<endl;
        while(L>querys[i].l){
            L--;
            bk[nums[L]]++;
            if(sum(nums[L],nums[L]) == 0)
                add(nums[L],1);
        }
        while(R<querys[i].r){
            R++;
            bk[nums[R]]++;
            if(sum(nums[R],nums[R]) == 0)
                add(nums[R],1);
        }
        while(L<querys[i].l){
            bk[nums[L]]--;
            if(bk[nums[L]] == 0)
                add(nums[L],-1);
            L++;
        }
        while(R>querys[i].r){
            bk[nums[R]]--;
            if(bk[nums[R]]== 0)
                add(nums[R],-1);
            R--;
        }
        ans[querys[i].id] = sum(AB[querys[i].id].y)-sum(AB[querys[i].id].x-1);
    }
    for(auto c:ans)cout<<c<<endl;
    cout<<endl;
    return 0;
}