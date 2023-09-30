#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first
#define y second

signed main(){__
	int t= 1,n,m,q,l,r,u,v;
    cin>>n>>m>>q;
    vector<pair<int,int>> A(m);
    vector<pair<int,int>> B(m);
    for(int i = 0;i<m;i++){
        cin>>l>>r;
        A[i] = {l,r};
        B[i] = {l,r};
    }
    sort(A.begin(),A.end(),[&](pair<int,int> a,pair<int,int> b){
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    });
    sort(B.begin(),B.end(),[&](pair<int,int> a,pair<int,int> b){
        if(a.y==b.y)return a.x<b.x;
        return a.y<b.y;
    });
    vector<int> maxA(m);
    vector<int> maxB(m);
    maxA[0]= A[0].y;
    maxB[m-1]= B[m-1].x;
    for(int i = 1;i<m;i++)
        maxA[i] = max(maxA[i-1],A[i].y);
    for(int i = m-2;i>=0;i--)
        maxB[i] = min(maxB[i+1],B[i].x);

    while(q--){
        cin>>u>>v;
        int l = -1,r = m;
        while(l+1<r){
            int m = (l+r)>>1;
            if(A[m].x<=u)
                l = m;
            else 
                r = m;
        }
        int a = -1,b = m;
        while(a+1<b){
            int m =(a+b)>>1;
            if(B[m].y>=u)
                b = m;
            else 
                a = m;
        }
        if(v>=maxB[b]&& v<=maxA[l] && u>=maxB[b] && u<=maxA[l])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}  
