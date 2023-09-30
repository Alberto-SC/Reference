#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<vector<int>> bit2D;
int n,m;
int sum2D(int x, int y) {
    int ret = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret += bit2D[i][j];
    return ret;
}
int sum2D(int x0,int y0,int x,int y){
    return sum2D(x,y)-sum2D(x,y0-1)-sum2D(x0-1,y)+sum2D(x0-1,y0-1);
}

void add2D(int x, int y, int delta) {
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < m; j = j | (j + 1))
            bit2D[i][j] += delta;
}


signed main(){__
	int t= 1,x,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        bit2D.assign(n,vector<int> (m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>x;
                add2D(i,j,x);
            }
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            int last = (m-i)+1;
            for(int j = 0;j<=n-i;j++){
                int l = -1,r = last;
                while(l+1<r){
                    int mid = (l+r)>>1;
                    if(sum2D(j,mid,(j+i)-1,(mid+i)-1)>=k*i*i)
                        r = mid;
                    else 
                        l = mid;
                }
                int y =  (last-r)*(((n-i)+1)-j);
                // cout<<"for size "<<i<<" and row "<<j<<" r: "<<r<<" "<<last<<" "<<y<<endl;
                ans+=y;
                last = r;
            }       
        }   
        cout<<ans<<endl;
    }
    return 0;
}  
