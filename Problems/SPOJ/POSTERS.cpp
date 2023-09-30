#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define printP(A)for(auto c:A)cout<<"("<<c.x<<","<<c.y<<")  ";cout<<endl;
#define printMP(A)for(auto c:A){printP(c);}
set<int> ans;
vector<int> lazy;
void propagate(int v,int l,int r){
    if(lazy[v] == 0)return;
    if(l!= r){
        lazy[v*2] = lazy[v*2+1] = lazy[v];
        lazy[v] = 0;
    }
}

void update(int v,int sl,int sr,int l,int r,int val){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] = val;
        // propagate(v);
        return;
    }
    // for(int i = 0;i<16;i++)cout<<lazy[i]<<" ";
        // cout<<endl;
    int m = (sl+sr)/2;
    update(v*2,sl,m,l,r,val);
    update(v*2+1,m+1,sr,l,r,val);
    // st[v] = st[v*2]+st[v*2+1];
}
void count(int v,int l,int r){
    if(l>r)return;
    if(lazy[v]){
        ans.insert(lazy[v]);
        return ;
    }
    propagate(v,l,r);
    int m = (l+r)/2;
    count(v*2,l,m);
    count(v*2+1,m+1,r);
}

// int query(int v,int sl,int sr,int l,int r){
//     propagate(v,sl,sr);
//     if(r<sl || l>sr || sl>sr)return 0;
//     if(sl>= l && sr<=r)return st[v];
//     int m = (sl+sr)/2;
//     return query(v*2,sl,m,l,r)+query(v*2+1,m+1,sr,l,r);
// }

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        ans.clear();
        int n; 
        cin >> n;
        set<int> pts;
        vector<pair<int,int>>  ranges(n);
        for(int i = 0; i < n; i++) {
            int l, r; cin >> l >> r;
            pts.insert(l);
            pts.insert(r);
            ranges[i] = {l, r};
        }    
        int k = 0;
        map<int, int> m;
        for(auto p: pts) {
            m[p] = k++;
        }
        lazy.assign(4*(k+1),0);
        for(int i = 0 ;i<n; i++) {
            ranges[i].first = m[ranges[i].first];
            ranges[i].second = m[ranges[i].second];
        }
        // printP(ranges)
        for(int i = 0;i<n;i++){
            update(1,0,k-1,ranges[i].first,ranges[i].second,i+1);
            // for(int i = 0;i<16;i++)cout<<lazy[i]<<" ";
            // cout<<endl<<endl;
        }
        count(1,0,k);
        // for(int i = 0;i<16;i++)cout<<lazy[i]<<" ";
            // cout<<endl<<endl;
        cout<<ans.size()<<endl;
        // for(int i = 0;i<n;i++)cout<<ranges[i].first<<" "<<ranges[i].second<<endl;
    }
}