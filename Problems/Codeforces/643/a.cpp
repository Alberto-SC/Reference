#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    lli t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        k--;
        for(int i = 0;i<k;i++){
            lli x = n;
            vector<lli> digits;
            while(x){
                digits.push_back(x%10);
                x/=10;
            }
            sort(digits.begin(),digits.end());
            if(digits[0] == 0)break;
            n+=digits[0]*digits.back();
        }
        cout<<n<<endl;
    }
    return 0;
}