#include <bits/stdc++.h>
using namespace std;
vector<int> st[26];
vector<int> lazy[26];

int n;
void propagate(int v,int l,int r,int who){
    if(lazy[who][v] == -1)return;
    st[who][v] = ((r-l)+1)*lazy[who][v];
    if(l != r){
        lazy[who][v<<1] = lazy[who][v];
        lazy[who][v<<1|1] = lazy[who][v];
    }
    lazy[who][v] = -1;
}

void update(int l,int r,int x ,int who,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(sl>r || sr<l || sl>sr)return;
    if(sl>=l && sr<=r){
        lazy[who][v] = x;
        propagate(v,sl,sr,who);
        return ;
    }
    int m = (sl+sr)>>1;
    update(l,r,x,who,v<<1,sl,m);
    update(l,r,x,who,v<<1|1,m+1,sr);
    st[who][v] = st[who][v<<1]+st[who][v<<1|1];
}

int query(int l,int r,int who,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr,who);
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[who][v];
    int m = (sl+sr)>>1;
    return query(l,r,who,v<<1,sl,m)+query(l,r,who,v<<1|1,m+1,sr);
}

int main(){
    int q,l,r,t;
    cin>>n>>q;
    for(int i = 0;i<26;i++)
        st[i].resize(4*n),lazy[i].resize(4*n,-1);
    string s;
    cin>>s;
    for(int i = 0;i<n;i++){
        update(i,i,1,s[i]-'a');
    }
    for(int i = 0;i<q;i++){
        cin>>l>>r>>t;
        l--,r--;
        vector<int> b(26);
        for(int j= 0;j<26;j++){
            b[j] = query(l,r,j);
            update(l,r,0,j);
        }
        int last = l;
        for(int j = t?0:25;t?j<26:j>=0;t?j++:j--){
            if(b[j] ==0)continue;
            update(last,(last+b[j])-1,1,j);
            last+=b[j];
        }

    }
    for(int i = 0;i<n;i++){
        int j;
        for(j = 0;j<26;j++){
            if(query(i,i,j))break;
        }
        cout<<char(j+'a');
    }
    cout<<endl;
    return 0;
}