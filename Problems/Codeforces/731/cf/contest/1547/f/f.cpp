#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> st;

int n;
void update(int pos,int val ,int v = 1,int sl = 0,int sr = n-1){
    if(sl== sr)st[v] = val;
    else {
        int m = (sl+sr)>>1;
        if(pos<=m)
            update(pos,val,v<<1,sl,m);
        else
            update(pos,val,v<<1|1,m+1,sr);
        st[v] = __gcd(st[v<<1],st[v<<1|1]);
    }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    if(sl>r ||sr<l|| sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return __gcd(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

signed main(){__
	int t= 1;
    cin>>t;
    while(t--){
        cin>>n;
        st.assign(4*n,0);
        vector<int> nums(n);
        int target = 0;
        for(auto &c:nums)cin>>c,target= __gcd(target,c);
        for(int i = 0;i<n;i++)
            update(i,nums[i]);
        int cont = 0;
        int mx = 0;
        for(int i = 0;i<n;i++){
            int l = -1,r =n-1;
            while(l+1<r){
                int m = (l+r)>>1;
                if(i+m>=n){
                    int gcd = query(i,n-1);
                    gcd = __gcd(gcd,query(0,(i+m)%n));
                    if(gcd==target)r = m;
                    else l = m;
                }
                else{
                    int gcd = query(i,i+m);
                    if(gcd==target)r = m;
                    else l = m;
                }
            }
            mx = max(r,mx);
        }
        cout<<mx<<endl;
    }
    return 0;
}  
