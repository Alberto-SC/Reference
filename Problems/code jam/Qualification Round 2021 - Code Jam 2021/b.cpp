#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,id = 1,X,Y;
	cin>>t;
    while(t--){
        cin>>X>>Y;
        string s;
        cin>>s;
        n = s.size();
        int ans = 0;
        if(s.size()==1){
            cout<<"Case #"<<id<<": "<<ans<<endl;
            id++;
            continue;
        }
        for(int i = 0;i<n;i++){
            if(s[i]== '?'){
                int j = i;
                while(j<n && s[i]==s[j]){j++;}
                bool f = true;
                if(i && j<n-1){
                    if(s[i-1]==s[j]&&s[i-1]== 'C')
                        f = false;   
                }
                else{
                    if(i ==0){
                        if(s[j]== 'C')
                            f = false;
                    }
                    else if(j >= n-1){
                        if(s[i-1]== 'C')
                            f = false;
                    }
                }

                for(int k = i;k<j;k++)
                    f?s[k] = 'J':s[k]='C';
                i = j;
            }
        }
        for(int i = 0;i<n-1;i++){
            if(s[i]== 'C' && s[i+1]== 'J')ans+=X;
            if(s[i]== 'J' && s[i+1]== 'C')ans+=Y;
        }
        // cout<<s<<endl;
        cout<<"Case #"<<id<<": "<<ans<<endl;
        id++;
    }
    return 0;
}  
