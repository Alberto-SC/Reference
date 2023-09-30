#include <bits/stdc++.h>
using namespace std;
string s;
int k,n;

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        sort(s.begin(),s.end());
        if(s[n-1]== s[0]){
            string ans = string(ceil(n/(k*1.0)),s[0]);
            cout<<ans<<endl;
        }
        else{
            char letter = s[0];
            int i = 0,cont = 0;
            while(s[i]== letter){cont++;i++;}
            if(cont<k)cout<<s[k-1];
            else{
                string ans = string(1,s[0]);
                ans+=s.substr(k);
                cout<<ans<<endl;
            }
        }
    }
    
    return 0;
}