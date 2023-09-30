#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef unsigned long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    lli t,n,s;
    cin>>t;
    while(t--){
        cin>>n>>s;
        string t = to_string(n);
        lli sum = 0;
        for(int i = 0;i<t.size();i++)
            sum+=t[i]-'0';
        if(sum<=s){cout<<0<<endl;continue;}
        int i ;
        sum = 0;
        for(i = 0;i<t.size();i++){
            sum+=(t[i]-'0');
            if(sum>=s)break;
        }
        if(i == 0){
            string nt =string(t.size(),'0');
            nt = "1"+nt;
            lli nw = stoll(nt);
            lli ans = nw-n;
            cout<<ans<<endl; 
        }
        else {
            
            string nt = t;
            for(int j = i;j<t.size();j++)
                nt[j] = '0';
            i--;
            // cout<<nt<<endl;
            while(i>=0 && nt[i] == '9'){
                nt[i] = '0';
                i--;
            }
            // cout<<nt<<endl;
            if(nt[0]== '0'){
                string nt2 =string(t.size(),'0');
                nt2 = "1"+nt;
                nt = nt2;
            }
            else {
                nt[i]= nt[i]+1;
            }
            // cout<<nt<<endl;
            lli nw = stoll(nt);
            lli ans = nw-n;
            cout<<ans<<endl;
        }
    }
    return 0;
}

