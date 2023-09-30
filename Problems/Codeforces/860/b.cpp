#include <bits/stdc++.h>

#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'

using namespace std;

int32_t main(){__
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>m;
        map<int,int> last;
        vector<int> v[m];
        for(int i = 0;i<m;i++){
            cin>>n;
            for(int j = 0;j<n;j++){
                int x;
                cin>>x;
                v[i].push_back(x);
                last[x] = i;
            }
        }
        vector<int> ans;
        for(int i = 0;i<m;i++){
            bool flag = false;
            for(auto c:v[i]){
                if(last[c]<=i){ans.push_back(c);flag = true;break;}
            }
            if(!flag){
                ans = {-1};
                break;
            }
        }
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
