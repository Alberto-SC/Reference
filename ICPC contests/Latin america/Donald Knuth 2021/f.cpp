#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define x first 
#define y second
struct S{
    int l,r,v;
    // friend ostream& operator <<(const ostream &out ,const S &A){
    //     out<<A.l<<""<<A.r<<" "<<A.v<<endl;
    //     return out;
    // }
    bool operator<(const S b){
        if(l==b.l)return r<b.r;
        return l<b.l;
    }
};
signed main(){__
	int t= 1,n,x,y,m;
    while(t--){
        cin>>n>>m;
        vector<pair<int,int>> p;
        for(int i = 0;i<m;i++){
            cin>>x>>y;
            p.push_back({x,y});
        }
        vector<S> top;
        vector<S> left;
        vector<S> rigth;
        vector<S> down;
        for(int i = 0;i<m;i++){
            x = p[i].x;
            y = p[i].y;
            down.push_back({max(1ll,y-(n-x)),min(n,y+(n-x)),n-x});
            top.push_back({max(1ll,y-(x-1)),min(n,y+(x-1)),x-1});
            rigth.push_back({max(1ll,x-(n-y)),min(n,x+(n-y)),n-y});
            left.push_back({max(1ll,x-(y-1)),min(n,x+(y-1)),y-1});
        }
        sort(down.begin(),down.end());
        sort(top.begin(),top.end());
        sort(left.begin(),left.end());
        sort(rigth.begin(),rigth.end());
        int mx = 0;
        for(int i = 0;i<left.size()-1;i++){
            if(left[i].r>=left[i+1].l)continue;
            int l = left[i].r,r = left[i+1].l;
            while(l+1<r){
                int m = (l+1<r);
                if(left[i].v+(m-left[i].r)<=left[i+1].v+(left[i+1].l-m));
            }
            mx = max(mx,left[i].v+(m-left[i].r));
            mx = max(mx,left[i+1].v+(left[i+1].l-(m+1)));
        }
        for(int i = 0;i<rigth.size()-1;i++){
            if(rigth[i].r>=rigth[i+1].l)continue;
            int l = rigth[i].r,r = rigth[i+1].l;
            while(l+1<r){
                int m = (l+1<r);
                if(rigth[i].v+(m-rigth[i].r)<=rigth[i+1].v+(rigth[i+1].l-m));
            }
            mx = max(mx,rigth[i].v+(m-rigth[i].r));
            mx = max(mx,rigth[i+1].v+(rigth[i+1].l-(m+1)));
        }
        for(int i = 0;i<down.size()-1;i++){
            if(down[i].r>=down[i+1].l)continue;
            int l = down[i].r,r = down[i+1].l;
            while(l+1<r){
                int m = (l+1<r);
                if(down[i].v+(m-down[i].r)<=down[i+1].v+(down[i+1].l-m));
            }
            mx = max(mx,down[i].v+(m-down[i].r));
            mx = max(mx,down[i+1].v+(down[i+1].l-(m+1)));
        }
        for(int i = 0;i<top.size()-1;i++){
            if(top[i].r>=top[i+1].l)continue;
            int l = top[i].r,r = top[i+1].l;
            while(l+1<r){
                int m = (l+1<r);
                if(top[i].v+(m-top[i].r)<=top[i+1].v+(top[i+1].l-m));
            }
            mx = max(mx,top[i].v+(m-top[i].r));
            mx = max(mx,top[i+1].v+(top[i+1].l-(m+1)));
        }   
        int e1 = 0,e2 =0,e3 = 0,e4 = 0;
        e1 = min((top[0].l-1)+top[0].v,(left[0].l-1)+left[0].v);
        e2 = min((n-top.back().r)+top.back().v,(rigth[0].l-1)+rigth[0].v);
        e3 = min((down[0].l-1)+down[0].v,(n-left.back().r)+left.back().v);
        e4 = min((n-down.back().r)+down.back().v,(n-rigth.back().r)+rigth.back().v);
        mx = max({mx,e1,e2,e3,e4});
        cout<<mx<<endl;
    }
    return 0;
}  
