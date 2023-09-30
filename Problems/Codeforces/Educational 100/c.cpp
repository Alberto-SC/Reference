#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct rg{
    lli l,r,a,b;
    bool operator<(rg &B)const{
        return r<B.r;
    }
    friend ostream& operator <<(ostream &out,const rg &A){
        out<<A.l<<" "<<A.r<<" "<<A.a<<" "<<A.b<<endl;
        return out;
    }
};

int main(){__
	lli t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        lli last = 0;
        lli lastval = 0;
        vector<lli> ts(n),xs(n);
        for(lli i = 0;i<n;i++)
            cin>>ts[i]>>xs[i];
        vector<rg>ranges;
        ts.push_back(1e+9);
        xs.push_back(1e+9);
        for(lli i = 0;i<n;i++){
            if(ts[i]>=last){
                last = abs(lastval-xs[i])+ts[i];
                ranges.push_back({ts[i],last,lastval,xs[i]});
                lastval = xs[i];
            }
        }
        lli ans = 0;
        sort(ranges.begin(),ranges.end());
        for(auto c:ranges)cout<<c;
        for(lli i =0;i<n;i++){
            lli idx = lower_bound(ranges.begin(),ranges.end(),ts[i]+1,[&](const rg &A,lli x){
                return A.r<x;
            })-ranges.begin();
            if(idx == ranges.size()){
                ans++;
                continue;
            }
            lli moves = min(ranges[idx].r-ts[i],ts[i+1]-ts[i]);
            lli diff = ts[i]-ranges[idx].l;
            lli init = 0;
            if(diff<0){
                ans++;
                continue;
            }
            cout<<idx<<" "<<diff<<" "<<moves<<" ";
            if(ranges[idx].a<ranges[idx].b){
                init = ranges[idx].a+diff;
                cout<<init<<" "<<init+moves<<endl;
                if(xs[i]>=init && xs[i]<=init+moves)ans++;
            }
            else{
                init = ranges[idx].a-diff;
                cout<<init<<" "<<init-moves<<endl;
                if(xs[i]<=init && xs[i]>=init-moves)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}  
//  0 1 2 3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
// [0,0,1,0,−1,−2,−3,−4,−5,−6,−6,−6,−6,−7,−8,−9,−9,−9,−9,−8,−7,−6,−5,−4,−3,−2,−1,−1,…]
