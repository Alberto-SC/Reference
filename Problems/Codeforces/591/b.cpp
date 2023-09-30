#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;

int main(){
    int q;
    string s,t;
    cin>>q;
    while(q--){
        cin>>s>>t;
        int n = s.size();
        if(s == t)cout<<"YES"<<endl;
        else {
            vector<bool> b1(27,false);
            vector<bool> b2(27,false);
        
            for(int i = 0;i<n;i++){
                b1[s[i]-'a'] = true;
                b2[t[i]-'a']=true;
            }
            bool flag = false;
            for(int i = 0;i<27;i++)
                if(b1[i] && b2[i]){flag= true;break;}
            if(flag)cout<<"YES"<<endl;
            else 
                cout<<"NO"<<endl;
        }
    }
    return 0;
}