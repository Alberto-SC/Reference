#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int main(){__
    int t,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        int mn = n+10;        
        if(n == 1){cout<<0<<endl;continue;}
        for(int i = 0;i<10;i++){
            for(int j = i;j<10;j++){
                int cont = 0; 
                bool findi = false,findj = false;
                for(int k = 0;k<n;k++){
                    if(s[k]!= char(i+'0') && s[k]!= char(j+'0'))cont++;  
                    if(s[k]== char(i+'0'))findi = true;
                    if(s[k]== char(j+'0'))findj = true;
                }
                if(findi && !findj && cont == 0)mn = 0;
                if(!findi && findj && cont == 0)mn = 0;
                if(findi && findj){
                    int cont1 =0,cont2 = 0;
                    bool turn = false;
                    for(int k = 0;k<n;k++){
                        // cout<<s[k]<<" "<<turn<<endl;
                        if(s[k]== char(j+'0') && !turn)cont1++;
                        if(s[k]== char(i+'0') && turn)cont1++;
                        if(s[k]== char(i+'0') && !turn)turn= !turn;
                        else if(s[k]== char(j+'0') && turn)turn= !turn;
                    }
                    turn = false;
                    for(int k = 0;k<n;k++){
                        if(s[k]== char(j+'0') && turn)cont2++;
                        if(s[k]== char(i+'0') && !turn)cont2++;
                        if(s[k]== char(i+'0') && turn)turn= !turn;
                        else if(s[k]== char(j+'0') && !turn)turn= !turn;
                    }
                    int ans1 = cont+cont1,ans2 = cont+cont2;
                    if((n-ans1)&1)ans1++;
                    if((n-ans2)&1)ans2++;
                    mn = min({mn,ans1,ans2});
                }
            }
        }
        vector<int>b(10);
        for(int i = 0;i<n;i++)b[s[i]-'0']++;
        for(int i = 0;i<10;i++)mn = min(mn,n-b[i]);
        if(mn == n+10)cout<<n-2<<endl;
        else cout<<mn<<endl;
    }
    return 0;
}