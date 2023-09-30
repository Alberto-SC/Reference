#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

struct seg{
    int l,r,c;
};

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<seg> s(n);
        for(int i = 0;i<n;i++){
            cin>>s[i].l>>s[i].r>>s[i].c;    
        }
        int idxl,idxr,l = 1e15,r = 0,lc = 1e15,rc= 1e15;
        seg mx;
        for(int i = 0;i<n;i++){
            if(s[i].r-s[i].l>mx.r-mx.l){
                mx = s[i];
            }
            if(s[i].r-s[i].l==mx.r-mx.l){
                if(s[i].c<mx.c)mx = s[i];
            }
            if(s[i].l<l||(s[i].l==l && s[i].c<lc)){
                idxl = i;
                l = s[i].l;t
                lc = s[i].c;
            }
            if(s[i].r>r || (s[i].r==r&& s[i].c<rc)){
                idxr = i;
                r = s[i].r;
                rc = s[i].c;    
            }

            // cout<<l<<" "<<r<<" "<<lc<<" "<<rc<<" "<<idxl<<" "<<idxr<<endl;
            if(idxl == idxr)cout<<lc<<endl;
            else if(s[idxl].l == s[idxr].l && s[idxr].r == s[idxl].r){
                cout<<min(s[idxl].c ,s[idxr].c)<<endl;
            }
            else if(s[idxr].l==s[idxl].l){
                cout<<rc<<endl;
            }
            else if(s[idxl].r==s[idxr].r){
                cout<<lc<<endl;
            }
            else if(s[idxl].l ==mx.l && s[idxr].r == mx.r){
                cout<<min(mx.c,lc+rc)<<endl;
            } 
            else cout<<lc+rc<<endl;
        }

    }
    return 0;
}  
