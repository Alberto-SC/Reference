#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
const int maxn = 400007;
vector<int> bit(maxn);
int sum(int idx){
    int res = 0;
    for(++idx;idx>0; idx-= idx&-idx)res+=bit[idx];
    return res;
}

void add(int idx,int val){
    for(++idx;idx<maxn;idx+= idx&-idx)bit[idx]+=val;
}

int sum(int l,int r){
    return sum(r)-sum(l-1);
}
int main(){__
	int t= 1,n,l,r;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> segments;
        set<int> un;
        for(int i = 0;i<n;i++){
            cin>>l>>r;
            segments.push_back({l,r});
            un.insert(l);
            un.insert(r);
        }
        vector<int> nw;
        for(auto c:un)nw.push_back(c);
        for(int i = 0;i<n;i++){
           segments[i].first = lower_bound(nw.begin(),nw.end(),segments[i].first)-nw.begin();
           segments[i].second = lower_bound(nw.begin(),nw.end(),segments[i].second)-nw.begin();
        }
        vector<pair<int,pair<int,int>>> events; 
        for(int i = 0;i<n;i++){
            events.push_back({segments[i].x,{1,segments[i].y}});
            events.push_back({segments[i].y,{2,segments[i].x}});
        }
        sort(events.begin(),events.end());
        int mx = 0;
        for(int i = 0;i<events.size();i++){
            if(events[i].y.x ==1)
                add(events[i].y.y,1);
            else
                mx = max(mx,sum(events[i].y.y,2*n));
            
        }
        cout<<n-mx<<endl;
        for(int i = 0;i<events.size();i++){
            if(events[i].y.x ==1)
                add(events[i].y.y,-1);
        }
    }
    return 0;
}  

