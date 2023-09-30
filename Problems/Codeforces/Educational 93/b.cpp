#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        string t = s;
        bool turn = false;
        int ans = 0;
        vector<int> ones;
        int cont = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== '1')cont++;
            else if(s[i] == '0'){
                if(cont!= 0)
                    ones.push_back(cont);
                cont = 0;
            }
        }
        if(cont!=0)ones.push_back(cont);
        sort(ones.rbegin(),ones.rend());
        // for(auto c:ones)cout<<c<<" ";
        // cout<<endl;
        for(int i = 0;i<ones.size();i++)
            if(i%2 ==0)ans+=ones[i];
        cout<<ans<<endl;
    }
    return 0;
}

