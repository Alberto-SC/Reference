#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    string s;
    cin>>s;
    n = s.size();
    vector<pair<int,int>> ans;
    vector<pair<int,int>> h;
    vector<pair<int,int>> v;
    h.push_back({1,1}); 
    h.push_back({1,3});
    v.push_back({3,1}); 
    v.push_back({3,2}); 
    v.push_back({3,3}); 
    v.push_back({3,4});
    int vc = 0,hc = 0; 
    for(int i = 0;i<n;i++){
        if(s[i]== '0'){
            vc++;
            ans.push_back(v[vc%4]);
        }  
        else{
            hc++;
            ans.push_back(h[hc%2]);
        }     
    }

    for(auto c:ans){
        cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}  

