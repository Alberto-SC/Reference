#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,x,m,l,r;
    cin>>t;
    while(t--){
        cin>>n>>x>>m;
        vector<pair<int,int>> seg;
        for(int i = 0;i<m;i++){
            cin>>l>>r;
            seg.push_back({l,r});
        }
        int idx = 0;
        while(idx<m){
            if(seg[idx].first<=x && seg[idx].second>=x)break;
            idx++;
        }
        if(idx == m){
            cout<<1<<endl;
            continue;
        } 
        int lmn = seg[idx].first,rmx = seg[idx].second;
        for(int i = idx+1;i<m;i++){
            l = seg[i].first;
            r = seg[i].second;
            if(l>=lmn && l<=rmx && r >rmx){
                rmx = r;
            }
            else if(r>=lmn && r<= rmx && l<lmn){
                lmn = l;
            }
            else if(l<lmn && r>rmx){
                lmn = l;
                rmx = r;
            }
        }
        cout<<(rmx-lmn)+1<<endl;
    }
    return 0;
}  

