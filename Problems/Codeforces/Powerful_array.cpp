#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define endl '\n'
#define __ ios_base::sync_with_stdio(0),cin.tie(0);
lli block;
struct query{
    lli L,R,id;
};
const int maxn = 1000007;
bool comp(query x, query y){
    int aux = x.L/block;
    if (aux != y.L/block)
        return x.L < y.L;
    if(aux & 1)
		return x.R < y.R;
	return x.R > y.R;
}
 
lli total = 0;
vector<lli> b(maxn);
void add(lli x,bool type){
    total-=(b[x]*b[x])*x;
    type == true? b[x]++:b[x]--;
    total+=(b[x]*b[x])*x;
}
int main(){__
    lli n,m,l,r;
    cin>>n>>m;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    vector<query> q(m);
    for(int i = 0;i<m;i++){
        cin>>l>>r;
        l--,r--;
        q[i] = {l,r,i};
    }
    block = sqrt(n);
    vector<lli> ans(m);
    sort(q.begin(),q.end(),comp);
   int L = 0,R = -1;
    for(int i = 0;i<m;i++){
        lli l = q[i].L;
        lli r = q[i].R;
        while(L>l){
            L--;
            add(nums[L],1);
        }
        while(R<r){
            R++;
            add(nums[R],1);
        }
        while(l>L){
            add(nums[L],0);
            L++;
        }
        while(r<R){
            add(nums[R],0);
            R--;
        }
        ans[q[i].id] = total; 
    }   

    for(auto c:ans)cout<<c<<endl;
    return 0;
}