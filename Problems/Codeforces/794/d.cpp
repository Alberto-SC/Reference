#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

signed main(){__
    int t,n;
    cin>>t;
    while(t--){
        string s;
        int a,b,c,d,cA = 0,cB = 0;
        cin>>a>>b>>c>>d;
        cin>>s;
        n = s.size();
        string S;
        for(int i = 0;i<n;){
            int j = i;
            while(j<n && s[i]== s[j]){
                j++;
            }
            if(j-i>=2){
                S+=s[i];
                S+=s[i];
                if(s[i]== 'A')
                    a-=(j-i)-2,cA+=2;
                else 
                    b-=(j-i)-2,cB+=2;
            }
            else S+=s[i],(s[i]=='A'?cA++:cB++);
            i = j;
        }
        string x;
        cout<<S<<endl;
        if(a <0 || b<0 || a+c+d != cA || b+c+d!= cB){
            cout<<"NO"<<endl;
            continue;
        }


        x = S[0];
        int poss = 0,posa = 0,posb = 0;
        vector<int> xa,xb;
        for(int i = 1;i<=S.size();i++){
            if(i == S.size() || S[i]== S[i-1]){
                int k = x.size()/2;
                if(x.size()&1)
                    poss+=k;
                else if(x[0] == 'A')
                    xa.push_back(k);
                else if(x[0]== 'B' && d)
                    xb.push_back(k);
                x = S[i];
            }
            else 
                x+=S[i];
        }
        
        sort(xa.begin(),xa.end());
        sort(xb.begin(),xb.end());
        for(auto C:xa){
            cout<<"A: "<<C<<endl;
            int z = min(C,c);
            c-=z;
            posb +=(C-z)?(C-z)-1:0;
        }
        for(auto C:xb){
            cout<<"B: "<<C<<endl;
            int z = min(C,d);
            d-=z;
            posa +=(C-z)?(C-z)-1:0;
        }

        if(c && d && poss>=c+d)c = 0,d = 0;
        else if(c && posa+poss>=c)c = 0;
        else if(d && posb+poss>=d)d = 0;
        if(c || d)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}
