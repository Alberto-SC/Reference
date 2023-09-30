#include <bits/stdc++.h>
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

vector<int> Criba(int n) {
    int raiz = sqrt(n);
    vector<int> criba(n + 1);
    for (int i = 4; i <= n; i += 2)
        criba[i] = 2;
    for (int i = 3; i <= raiz; i += 2)
        if (!criba[i])
            for (int j = i * i; j <= n; j += i)
                if (!criba[j]) criba[j] = i;
    return criba;
}
int main(){
    int t,n;
    cin>>t;
    vector<int> primos;
    primos = Criba(20000);
    int cont = 1;
    while(t--){
        cin>>n;
        cout<<"Case #"<<cont<<": ";
        cont++;
        if(n == 1)cout<<n<<endl;
        else if(primos[n] == 0)cout<<Mod(2,n-1,n)<<endl;
        else cout<<((n-1)%n)*((n-1)%n)%n<<endl;
    }


    return 0;
}