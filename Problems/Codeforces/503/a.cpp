#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,f,a,b,q,ta,fa,tb,fb;
    cin>>n>>f>>a>>b>>q;
    
    for(int i = 0;i<q;i++){
        cin>>ta>>fa>>tb>>fb;
        if(ta == tb){
            cout<<abs(fa-fb)<<endl;
        }
        else {
            if(fa>=a && fa<=b){
                cout<< abs(tb-ta)+abs(fb-fa)<<endl;
            }
            else{
                if(fa> b){
                    // if(fb>b)
                        cout<<(fa-b)+abs(tb-ta)+abs(b-fb)<<endl;
                    // else cout<<(fa-b)+abs(tb-ta)+abs(a-fb)<<endl;
                }

                else {
                    // if(fb<a)
                    cout<<(a-fa)+abs(tb-ta)+abs(a-fb)<<endl;
                    // else cout<<(a-fa)+abs(tb-ta)+abs(b-fa)<<endl;
                }
            }
        }
    }
    return 0;
}