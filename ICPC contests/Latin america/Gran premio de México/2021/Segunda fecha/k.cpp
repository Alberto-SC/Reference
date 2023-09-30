#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,k;
    cin>>t;
    while(t--){
        cin>>k;
        if(k==1){
            cout<<0<<endl;
            continue;
        }
        vector<int> divs;
        for(int i = 1;i*i<=k;i++){
            if(k%i==0){
                divs.push_back(i);
                if(k/i!= i && k/i != k)
                    divs.push_back(k/i);
            }
        }
        int cont = 0;
        for(int i = 0;i<(1<<k);i++){
            string s(k,'0');
            for(int j = 0;j<k;j++)
                if((i>>j)&1)s[j] ='1';
            bool flag = false;
            bool f4 = false , f6 = false;
            for(int j = 0;j<divs.size();j++){
                string x = s.substr(0,divs[j]);
                bool f2 = true;
                for(int z = 0;z<k/divs[j];z++){
                    string y  = s.substr(z*divs[j],divs[j]);
                    if(x!= y)f2 = false;
                }
                if(f2){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cont++;
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}  
// 0 2 2 4 2 10 2 16 8 34 2 76 2 130