#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool flag = true;
        n = s.size();
        for(int i = 1;i<n-1;i++){
            if(s[i]== s[i+1] && s[i]!= '?')flag = false;
            if(s[i]== '?'){
                if(s[i-1]== 'a' && s[i+1] == 'b')
                    s[i]= 'c';
                if(s[i-1]== s[i+1] && s[i-1]== 'a')
                    s[i] = 'b';
                if(s[i-1]== 'a' && s[i+1]== '?')
                    s[i] = 'b';
                if(s[i-1]== 'a' && s[i+1] == 'c')
                    s[i]= 'b';
                if(s[i-1]== 'b' && s[i+1] == 'c')
                    s[i]= 'a';
                if(s[i-1]== 'b' && s[i+1] == 'a')
                    s[i]= 'c';
                if(s[i-1]== s[i+1] && s[i-1]== 'b')
                    s[i] = 'c';
                if(s[i-1]== 'b' && s[i+1]== '?')
                    s[i] = 'a';
                if(s[i-1]== 'c' && s[i+1] == 'a')
                    s[i] = 'b';
                if(s[i-1]== 'c' && s[i+1] == 'b')
                    s[i] = 'a'  ;
                if(s[i-1]== s[i+1] && s[i-1]== 'c')
                    s[i] = 'b';
                if(s[i-1]== 'c' && s[i+1]== '?')
                    s[i] = 'b';
                if(s[i-1]== '?' && s[i+1]=='?')
                    s[i] = 'a';

            
            }
        }
        if(1<n){
            if(s[0]== '?' && s[1]== 'a')
                s[0] = 'b';
            if(s[0]== '?' && s[1]== 'b')
                s[0] = 'a';
            if(s[0]== '?' && s[1]== 'c')
                s[0] = 'a';
        }
        else{
            if(s[0]== '?')
                s[0] = 'a';
        }

        if(n-2>=0){
            if(s[n-1]== '?' && s[n-2]== 'a')
                s[n-1] = 'b';
            if(s[n-1]== '?' && s[n-2]== 'b')
                s[n-1] = 'a';
            if(s[n-1]== '?' && s[n-2]== 'c')
                s[n-1] = 'b';
            
        }
        else{
            if(s[n-1]== '?')
                s[n-1]= 'a';
        }
        if(s =="??")s = "ab";
        if(1<n && s[0]==s[1])flag = false;
        if(flag)cout<<s<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}  
