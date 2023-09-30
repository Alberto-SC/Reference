#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        string t;
        set<char> s;
        cin>>t;
        n = t.size();
        int l = 0,r  = 0;
        int sz = 0,ans = n+1;
        vector<int> b(3);
        while(r<n){
            while(r<n && s.size()<3){
                s.insert(t[r]);
                b[t[r]-'1']++;

                sz++;
                r++;
            }
            if(s.size() == 3)ans = min(sz,ans);
            while(l<r &&  s.size()==3){
                if(b[t[l]-'1'] == 1)s.erase(t[l]);
                b[t[l]-'1']--;
                l++;
                sz--;
            }
            ans = min(ans,sz+1);
        }
        if(ans == n+1)ans =0;
        cout<<ans<<endl;
    }
    return 0;
}