#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;
signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<pair<string,ld>> forms(n);
        vector<ld> cubes;
        vector<ld> cylinder;
        cubes.push_back(20000);
        cylinder.push_back(20000);
        for(int i = 0;i<n;i++){
            cin>>forms[i].first>>forms[i].second;
            if(forms[i].first=="cube"){
                cubes.push_back(forms[i].second);
            }
            else{
                cylinder.push_back(forms[i].second);
            }
        }
        sort(cubes.rbegin(),cubes.rend());
        sort(cylinder.rbegin(),cylinder.rend());
        vector<string> ans;
        for(int i = 0;i<n;i++){
            int x = cubes.back();
            int y = cylinder.back();
            if(y*2<=x){
                ans.push_back("cylinder "+to_string(y));
                cylinder.pop_back();
            }
            else if(x*x <= 2*y*y){
                ans.push_back("cube "+to_string(x));
                cubes.pop_back();
            }
            else
                return cout<<"impossible"<<endl,0;
        }
        for(auto c:ans)cout<<c<<endl;
    }
    return 0;
}  
