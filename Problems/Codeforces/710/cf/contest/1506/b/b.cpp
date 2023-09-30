#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> pos;
        for(int i = 0;i<n;i++)
            if(s[i]=='*')pos.push_back(i);
        
        int x=0;
        int last = 0;
        for(int i = 1;i<pos.size()-1;i++){
            if(pos[i+1]-pos[last]>k){
                last = i;
            }
            else{
                x++;
            }
        }
        cout<<pos.size()-x<<endl;
    }
    return 0;
}  
