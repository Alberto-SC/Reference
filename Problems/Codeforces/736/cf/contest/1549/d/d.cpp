#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<int> st;
vector<int> diff;
int N;

void update(int pos,int x,int v = 1,int sl = 0,int sr = N-1){
    if(sl==sr)st[v] = x;
    else {
        int m = (sl+sr)>>1;
        if(pos<=m)
            update(pos,x,v<<1,sl,m);
        else 
            update(pos,x,v<<1|1,m+1,sr);

        st[v] = __gcd(st[v<<1],st[v<<1|1]);        
    }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = N-1){
    if(sl>r || sr<l || sl>sr)return 0;
    if(sl>=l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return __gcd(query(l,r,v<<1,sl,m),query(l,r,v<<1|1,m+1,sr));
}

bool check(int m,vector<int> &v){
    m--;
    for(int i = 0;i<=N-m;i++)
        if(query(i,(i+m)-1)!=1)return true;
    return false;

}

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> nums(n);
        for(auto &c:nums)cin>>c;
        diff.resize(n-1);
        N = n-1;
        for(int i = 1;i<n;i++)
            diff[i-1] = abs(nums[i]-nums[i-1]);
        st.resize(4*N);
        for(int i = 0;i<n-1;i++){
            update(i,diff[i]);
        }
        int l = 0,r = 0,ans =1;
        while(l<N &&r<N){
            int res = query(l,r);
            if(res!=1)ans =max(ans,(r-l)+2);
            if(res==1 && l<r)
                l++;
            else 
                r++;
        }
        cout<<ans<<endl;
    }
    return 0;
}  
