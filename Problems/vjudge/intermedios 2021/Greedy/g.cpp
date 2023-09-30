#include <bits/stdc++.h>
using namespace std;
#define int long long
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

int n,m,s = 0;
bool check(int x,vector<pair<int,int>> &sales,vector<int> &k){
    int total= s;
    vector<bool> used(n);
    for(int i = 0;i<m;i++){
        if(sales[i].first>x)break; 
        if(used[sales[i].second])continue;
        x-=k[sales[i].second];
        s-=k[sales[i].second]*2;
        used[sales[i].second] = true;
    }
    x-=s;
    if(x<0)return false;
    return true;

}

signed main(){__
    int d,t;
    cin>>n>>m;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c,s+=c*2;
    vector<pair<int,int>> sales;
    for(int i = 0;i<m;i++){
        cin>>d>>t;
        t--;
        sales.push_back({d,t});
    }
    int l = 0,r = s;
    
    while(l+1<r){
        int m = (l+r)>>1;
        if(check(m,sales,nums))
            r = m;
        else 
            l = m;
    }    
    cout<<r<<endl;

    return 0;
}

