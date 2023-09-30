#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
struct basis{
    lli base[64];
    int sz = 0;
    basis(){
        for(int i = 0;i<64;i++)
            base[i]= 0;
    }

    void add(lli x){
        while(x!= 0 && base[63-__builtin_clzll(x)]!= 0){
            x^=base[63-__builtin_clzll(x)];
        }
        if(!x)return;
        sz++;
        base[63-__builtin_clzll(x)] = x;
    }

    lli get_max(){
        lli ans = 0;
        for(int i = 63;i>=0;i--)
            if(base[i]!= 0)
                if(!((ans>>i)&1))
                    ans^=base[i];
        return ans;
    }
};
int main(){__
    int n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    basis bs;
    for(auto c:nums)bs.add(c);
    cout<<bs.get_max()<<endl;
    return 0;
}