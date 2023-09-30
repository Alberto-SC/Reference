#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        bool flag = true,even = false;
        int sum = 0;
        int zero= 0;
        for(int i = 0;i<n;i++){
            sum+=s[i]-'0';
            if((s[i]-'0')%2==0 && s[i]!= '0')even  = true;
            if(s[i]== '0')zero++;
        }
        if(sum == 0){
            cout<<"red"<<endl;
            continue;
        }
        if(sum%3)flag = false;
        if(!even){
            if(zero<=1)
                flag = false;
        }
        else{
            if(!zero)flag = false;
        }
        if(flag)cout<<"red"<<endl;
        else cout<<"cyan"<<endl;
    }
    return 0;
}  
