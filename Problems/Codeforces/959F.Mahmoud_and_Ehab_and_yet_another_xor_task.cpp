#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;
lli bin_pow(lli a ,lli b){
    lli x = 1;
    while(b){
        if(b&1) (x*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return x;
}

struct basisxor {
    int base[31];
    int sz = 0;
    basisxor(){
        for(int i = 0;i<31;i++)
            base[i] = 0;
    }

    bool check(int x){
        while(x!= 0 && base[31-__builtin_clz(x)]!= 0){
            x^=base[31-__builtin_clz(x)];
        }
        if(x)return false;
        return true;
    }
    void add(int x){
        while(x!=0 && base[31-__builtin_clz(x)]!= 0){
            x^= base[31-__builtin_clz(x)];
        }
        if(!x)return ;
        base[31-__builtin_clz(x)] = x;
        sz++;
    }
};


struct query{
    int l,x,id;
    bool operator <(const query B){
        return l<B.l;
    }
};

int main(){
    int n,l,x,q;
    cin>>n>>q;
    basisxor bs;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    vector<query> querys;
    for(int i = 0;i<q;i++){
        cin>>l>>x;
        l--;
        querys.push_back({l,x,i});
    }
    vector<lli> ans(q);
    int li = 0;
    sort(querys.begin(),querys.end());
    for(int i =0;i<q;i++){
        l = querys[i].l;
        x = querys[i].x;
        int id = querys[i].id;
        while(li<=l){
            bs.add(nums[li]);
            li++;
        }
        if(bs.check(x))
            ans[id] = bin_pow(2,(l+1)-bs.sz);
    }
    for(auto c:ans)cout<<c<<endl;
    return 0;
}