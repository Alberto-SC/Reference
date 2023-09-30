#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        vector<int> posz,poso;
        for(int i = 0;i<2*n;i++){
            if(s[i]== '0')posz.push_back(i);
            else poso.push_back(i);
        }
        if(poso.size()==0||posz.size()==0){
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans;
        if(abs(poso[0]-posz[0])<=n){
            ans.push_back(max(posz[0],poso[0]));
            for(int i = 0;i<n-1;i++){
                ans.push_back(ans.back()+1);
            }
        }   
        else{
            ans.push_back(min(poso.back(),posz.back()));
            for(int i = 0;i<n-1;i++){
                ans.push_back(ans.back()-1);
            }
            sort(ans.begin(),ans.end());
        }
        for(auto c:ans)cout<<c+1<<" ";
        cout<<endl;
    }
    return 0;
}