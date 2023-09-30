#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        int n = s.size();
        bool flag = false;
        for(int i = 0;i<n;i++){
            int cont = 0;
            for(int j = i;j<i+4;j++){
                if(j>=n)break;
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u' || s[j]== 'y')break;
                cont++;
            }
            if(cont == 4)flag = true;
        }

        if(flag)cout<<"Difficult"<<endl;
        else cout<<"Easy"<<endl;

    }
    return 0;
}
