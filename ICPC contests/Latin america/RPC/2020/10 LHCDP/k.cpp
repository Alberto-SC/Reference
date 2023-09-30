#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
// #define printM(A) for(auto c:A){print(c);}
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const lli mod = 1e9+7;
vector<int> bit;
int m;

const int maxn = 100007;
struct points{
    int x,y,i;
    bool operator <(points B){
        if(x==B.x)return y>B.y;
        return x<B.x;
    }
};

int sum(int idx){
    int res = 0;
    for(++idx;idx>0; idx-= idx&-idx)res+=bit[idx];
    return res;
}
void add(int idx,int v){
    for(++idx;idx<maxn;idx+=idx&-idx)bit[idx]+=v;
}

bool comp(points A,points B){
    if(A.x==B.x)return A.y<B.y;
    return A.x<B.x;
}
int main(){
    int t = 1,n,a,b,x,y;
    while(t--){
        cin>>n;
        vector<points> P;
        vector<int> xs;
        vector<int> ys;
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            P.push_back({x,y,i});
            xs.push_back(P[i].x);
            ys.push_back(P[i].y);
        }
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());
        sort(P.begin(),P.end());
        // for(auto c:ys)cout<<c<<" ";
        // cout<<endl;
        for(int i = 0;i<n;i++){
            P[i].y = lower_bound(ys.begin(),ys.end(),P[i].y)-ys.begin()+1;
            P[i].x = lower_bound(xs.begin(),xs.end(),P[i].x)-xs.begin()+1;
        }
        // for(auto c:P){
            // cout<<c.x<<" "<<c.y<<" "<<c.i<<endl;
        // }
        bit.resize(maxn+7);
        vector<lli> back(n+1);
        lli ans = 0;
        for(int i = 0;i<n;i++){
            lli fwd = sum(P[i].y-1);
            ans+=(fwd*(fwd-1))>>1;
            // cout<<"HI"<<endl;
            add(P[i].y,1);
        }
        bit.assign(bit.size(),0);
        for(int i = n-1;i>=0;i--){
            back[P[i].i] = sum(n+1)-sum(P[i].y);
            add(P[i].y,1); 
        }
        sort(P.begin(),P.end(),comp);
        // for(auto c:back)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:P){
            // cout<<c.x<<" "<<c.y<<" "<<c.i<<endl;
        // }
        bit.assign(bit.size(),0);
        // cout<<ans<<endl;
        for(int i = 0;i<n;i++){
            lli fwd = sum(P[i].y);
            add(P[i].y,1);
            ans-= fwd*back[P[i].i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

// 10
// 4 2
// 9 4
// 1 5
// 2 4
// 10 5
// 6 1
// 3 3
// 2 8
// 2 3
// 7 2