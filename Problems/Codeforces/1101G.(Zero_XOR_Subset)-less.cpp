#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

struct basis{
    int base[32],sz = 0;
    basis(){
        for(int i = 0;i<32;i++)
            base[i] = 0;
    }

    void add(int x){
        while(x != 0 && base[31-__builtin_clz(x)]!= 0){
            x^=base[31-__builtin_clz(x)];
        }
        if(!x)return;
        sz++;
        base[31-__builtin_clz(x)] = x;
    }
};

int main(){__
    int n;
    cin>>n;
    basis bs;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    int pref = 0;
    for(int i = 0;i<n;i++){
        pref^=nums[i];
        bs.add(pref);
    }
    if(!pref)return cout<<-1<<endl,0;
    cout<<bs.sz<<endl;
    return 0;
}