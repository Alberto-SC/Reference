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
        int ans = 0;
        int cont = 0;
        for(int i = 0;i<10;i++){
            if(s[i]== '?')
                cont++;
        }
        int mn = 10;
        string aux = s;
        for(int mask = 0;mask<(1<<cont);mask++){
            int a1 = 0,a2 = 0,t1 =5,t2= 5,ans = 10,idx = 0;
            s = aux;
            for(int i = 0;i<10;i++){
                if (s[i]== '?'){
                    if((mask>>idx)&1)
                        s[i] = '1';
                    else 
                        s[i] = '0';
                    idx++;
                }
                if(i%2==0){
                    if(s[i]== '1')a1++;
                    t1--;
                }   
                else{
                    if(s[i]== '1')a2++;
                    t2--;
                }
                if(a1>a2){
                    if(a2+t2<a1){
                        ans = i+1;
                        break;
                    }
                }
                else {
                    if(a1+t1<a2){
                        ans = i+1;
                        break;
                    }
                }
            }
            mn = min(mn,ans);
        }
        cout<<mn<<endl;
    }
    return 0;
}  
