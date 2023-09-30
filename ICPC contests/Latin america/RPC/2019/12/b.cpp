#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli ans = 0;
int main(){
    string s;
    while(cin>>s){
        int n = s.size();
        string num;
        int price;
        int i = 0,mul;
        if(s[0] >='0' &&s[0]<='9'){
            while(s[i]>='0' && s[i]<='9'){
                i++;
            }
            num = s.substr(0,i);
            price = atoi(s.c_str());
            i+=2;
            mul = n-i;
            if(mul == 0)mul = 1;
            ans+= price*mul;

        }
        else{
            price = 42;
            mul = n;
            ans+= price*mul;
        }
    }
    int ans2 = ceil(ans/10.0);
    cout<<ans2*10<<",-"<<endl;
    return 0;
}