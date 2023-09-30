#include <bits/stdc++.h>
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define int long long 
using namespace std;
vector<int> st[26];
vector<int> lazy[26];
void propagate(int v,int l ,int r,int who){
    if(lazy[who][v]==-1)return ;
    
    st[who][v] = ((r-l)+1)*lazy[who][v];
    if(l!= r){
        lazy[who][v<<1] = lazy[who][v];
        lazy[who][v<<1|1] = lazy[who][v];
    }
    lazy[who][v] = -1;
}
int n; /*+ n is global for use default values and send less parameters */
void update(int l,int r,int val,int who,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[who][v] = val;
        propagate(v,sl,sr,who);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,who,v<<1,sl,m);
    update(l,r,val,who,v<<1|1,m+1,sr);
    st[who][v] = st[who][v<<1]+st[who][v<<1|1];
}

int query(int l,int r,int who ,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(r<sl || l>sr || sl>sr)return 0; 
    if(sl>= l && sr<=r)return st[who][v];
    int m = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,m)+query(l,r,who,v<<1|1,m+1,sr);
}



signed main(){__
    int q;
    string s;
    cin>>s;
    n = s.size();
    for(int i = 0;i<26;i++){
        st[i].resize(4*n);
        lazy[i].resize(4*n,-1);
    }

    for(int i = 0;i<n;i++)
        update(i,i,1,s[i]-'a');

    cin>>q;
    while(q--){
        int t,l,r;
        char c;
        cin>>t;
        if(t == 1){
            cin>>l>>r>>c;
            l--,r--;
            for(int i = 0;i<26;i++)
                update(l,r,0,i);
            
            update(l,r,1,c-'a');
        }
        else{
            cin>>l>>r;
            l--,r--;
        
            int cn = 0;
            for(int i = 0;i<26;i++){
                int s = query(l,r,i);
                if(s&1)cn++;
            }
            if(cn<=1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}
