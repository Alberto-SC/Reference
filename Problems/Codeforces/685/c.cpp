#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s,t;
        cin>>s>>t;
        vector<int> b1(26);
        vector<int> b2(26);
        char mn = 'z';
        for(int i = 0;i<n;i++){
            b1[s[i]-'a']++;
            b2[t[i]-'a']++;
        }
        for(int i = 0;i<n;i++){
            if(b1[t[i]-'a']){
                b1[t[i]-'a']--;
                b2[t[i]-'a']--;
            }
        }     
        s = "";
        t = "";
        for(int i = 0;i<26;i++){
            for(int j = 0;j<b1[i];j++)
                s+=char(i+'a');
            for(int j = 0;j<b2[i];j++)
                t+=char(i+'a');
        }
        // cout<<s<<" "<<t<<endl;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        bool flag = true;
        for(int i = 0;i<26;i++){
            if(b1[i]%k)flag = false;
            if(b2[i]%k)flag = false;
        }
        if(flag){
            for(int i = 0;i<s.size();i++)
                if(s[i]>t[i])flag = false;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}  

