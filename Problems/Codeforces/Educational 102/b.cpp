#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int lcm(int a,int b){
    return b*(a/__gcd(a,b));
}

int main(){__
	int q= 1,n,m;
    cin>>q;
    while(q--){
        string s,t;
        cin>>s>>t;
        if(t.size()>s.size()){
            swap(s,t);
        }
        string res = ""; 
        int k = lcm(t.size(),s.size());
        for(int i = 0;i<k/s.size();i++)
            res+= s;
        int y = res.size()/t.size();
        string res2 = "";
        for(int i = 0;i<y;i++){
            res2+=t;
        }
        if(res ==res2)cout<<res<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}  

