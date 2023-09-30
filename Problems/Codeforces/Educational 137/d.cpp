#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

string brute(string s){
    vector<string> v;
    int n = s.size();
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            v.push_back(s.substr(i,(j-i)+1));
        }  
    }
    int mx = 0;
    for(auto c:v){
        for(auto d:v){
            int x = stoll(c,nullptr,2);
            int y = stoll(d,nullptr,2);
            int res = x|y;
            mx = max(mx,res);
        }
    }
    bool o = false;
    string ans = "";
    for(int i = 10;i>=0;i--){
        if((mx>>i)&1){
            o = true;
            ans.push_back('1');
        }
        else if(o){
            ans.push_back('0');
        }
    }
    return ans;
}

signed main(){__
    int T = 1,n;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
  
        string ans = "0";
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(s[i]=='1'){
                ans = s.substr(i);
                flag = true;
                break;
            }
        }
        if(!flag){
            return cout<<ans<<endl,0;
        }
        if(n<=10){
            cout<<brute(s)<<endl;
            return 0;
        }
        int zero = 0;
        for(int i = 0;i<ans.size();i++){
            if(ans[i] =='0'){
                zero = i;
                break;
            }
        }
        string best = ans;
        int len = ans.size()-zero;
        for(int i= zero-1;i>=0;i--){
            string x = ans.substr(i,len);
            string nw = ans;
            for(int j = 0;j<len;j++){
                if(nw[zero+j]=='1' || x[j]=='1')nw[zero+j] = '1';
            }
            best = max(best,nw);
        }
        cout<<best<<endl;

    }
    return 0;
}