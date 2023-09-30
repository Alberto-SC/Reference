#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;
        vector<int> digits;
        int aux =n;
        while(aux){
            digits.push_back(aux%10);
            aux/=10;
        }
        int cont = 0;
        for(int i = 1;i*i<=n;i++){
            if(n%i ==0){
                int aux = i;
                vector<int> digitsb;
                while(aux){
                    digitsb.push_back(aux%10);
                    aux/=10;
                }
                bool flag= false;
                for(auto c:digits)
                    for(auto d:digitsb)if(c==d)flag = true;
                if(flag) cont++;
                if(n/i != i){
                    aux = n/i;
                    digitsb.clear();
                    while(aux){
                        digitsb.push_back(aux%10);
                        aux/=10;
                    }
                    bool flag= false;
                    for(auto c:digits)
                        for(auto d:digitsb)if(c==d)flag = true;
                    if(flag) cont++;
                }
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}  
