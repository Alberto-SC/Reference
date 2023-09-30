#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,sol = 1,anta = 0, antb= 0;
    cin>>n; 
    for(int i = 0;i<n;i++){
        cin>>a>>b;
        if(a == 0 && b == 0)continue;
        if(anta==antb)
            sol += min(a,b)-anta;
        else if(anta>antb){
            if(a>b){
                if(b>=anta) sol+=b-anta+1;
            }
            else sol+=a-anta+1;
        }
        else{
            if(a<b){
                if(a>=antb) sol+=a-antb+1;
            }
            else sol+=b-antb+1;
        }
        anta=a,antb=b;
    }

    cout<<sol;
    return 0;
}