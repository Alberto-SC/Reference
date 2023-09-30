#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,q,l,r;
    cin>>t;
    while(t--){
        string s;
        cin>>n>>q;
        cin>>s;
        vector<int> ac1(1);
        vector<int> ac0(1);
        ac0[0] = 0;
        ac1[0] = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='1')ac1.push_back(ac1.back()+1),ac0.push_back(ac0.back());
            else ac0.push_back(ac0.back()+1),ac1.push_back(ac1.back());
        }
        // for(auto c:ac1)cout<<c<<" ";
        // cout<<endl;
        // for(auto c:ac0)cout<<c<<" ";
        // cout<<endl;
        for(int i = 0;i<q;i++){
            cin>>l>>r;
            bool flag = false;
            if(s[l-1]== '0' && ac0[l-1]>=1)
                flag = true;
            else if(s[l-1] == '1' && ac1[l-1]>=1)
                flag = true;

            if(s[r-1]== '0' && (ac0[n]-ac0[r]>0))
                flag = true;
            else if(s[r-1] == '1' && (ac1[n]-ac1[r]>0))
                flag = true;
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}  

