#include <iostream>
using namespace std;

long long Mod(long long x, long long y, long long m) {
    long long ans = 1, tmp = x;
    while(y) {
        if(y&1) {
            ans *= tmp;
            ans %= m;
        }
        y >>= 1;
        tmp *= tmp, tmp %= m;
    }
    return ans;
}

int main() {
    long long x, y,n,c;
    cin>>c;
    while(c--){
        cin>>x>>y>>n;
        cout<<Mod(x,y,n)<<endl;
    }
    cin>>c;
    return 0;
}