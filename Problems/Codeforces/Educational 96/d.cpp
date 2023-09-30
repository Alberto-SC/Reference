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
        cin>>n;
        vector<char> rev(n);
        for(auto &c:rev)cin>>c;
        reverse(rev.begin(),rev.end());
        int ans = 0;
        int N = n;
        while(rev.size()>1){
            if(rev[N-1]!=rev[N-2]){
                char x = rev.back();
                while(rev.size() && rev.back()==x){
                    rev.pop_back();
                    N--;
                }
                rev.pop_back();
                N--;
            }
            else{
                char x = rev.back();
                while(rev.size() && rev.back()==x){
                    rev.pop_back();
                    N--;
                }
            }
            ans++;
        }
        if(rev.size())ans++;
        cout<<ans<<endl;
    }
    return 0;
}

