#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define x first 
#define y second
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> h(n);
        for(auto &c:h)cin>>c;
        vector<pair<int,int>> rc;
        for(int i = 0;i<n;i++){
            if(i == 0 || i ==n-1){
                rc.push_back({h[i],h[i]+k});
            }
            else{
                rc.push_back({h[i],((2*k)-1)+h[i]});
            }
        }
        bool flag = true;
        for(int i = 1;i<n-1;i++){
            if(h[i-1]>=h[i] && h[i+1]>=h[i]){
                if(rc[i].y<= rc[i-1].x || rc[i].y<=rc[i+1].x){
                    flag = false;
                }
            }
            else if(h[i-1]>=h[i] && h[i+1]<h[i]){
                if(rc[i].y<= rc[i-1].x || rc[i].x>=rc[i+1].y){
                    flag = false;
                }
            }
            else if(h[i-1]<h[i] && h[i+1]>=h[i]){
                if(rc[i].x>= rc[i-1].y || rc[i].y<=rc[i+1].x){
                    flag = false;
                }
            }
            else {
                if(rc[i].x>= rc[i-1].y || rc[i].x>=rc[i+1].y){
                    flag = false;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}  

