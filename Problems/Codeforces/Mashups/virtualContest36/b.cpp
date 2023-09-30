#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,a,b;
    while(t--){
        cin>>a>>b;
        if(a>b+1|| b>(a*2)+2)cout<<-1<<endl;
        else if(a==b+1 ||a==b){
            for(int i = 0;i<a+b;i++){
                if(i&1)cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
        else if(b==a+1){
            for(int i = 0;i<a+b;i++){
                if(i&1)cout<<0;
                else cout<<1;
            }
        }
        else if(b ==2*a || b==(2*a)-1 || b==(2*a)-2){
            for(int i = 0;i<a+b;i++){
                if(i%3==0)cout<<0;
                else cout<<1;
            }
        }
        else if(b == (2*a)+1|| b==(2*a)+2){
            for(int i = 0;i<a+b;i++){
                if(i%3==2)cout<<0;
                else cout<<1;
            }
        }
        else {
            int idx = 0;
            int last = 0;
            while(b>a+1){ 
                if(idx%3==2)cout<<0,a--,last = 0;
                else cout<<1,b--,last = 1;
                idx++;
            }
            if(last==1)
                cout<<"011";
            a--,b-=2;
            if(b==a+1){
                for(int i = 0;i<a+b;i++){
                    if(i&1)cout<<0;
                    else cout<<1;
                }
            }
            else if(a==b+1 ||a==b){
                for(int i = 0;i<a+b;i++){
                    if(i&1)cout<<1;
                    else cout<<0;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}  
