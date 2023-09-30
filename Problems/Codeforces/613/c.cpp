#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<lli> divisors;
void get_divisors(lli n){
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0) {
            if (n/i == i)
                divisors.push_back(i);
            else {
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
}
int main(){
    clock_t begin = clock();
    lli x;
    cin>>x;
    get_divisors(x);
    int n = divisors.size();
    // cout<<n<<endl;
    // for(auto c:divisors)cout<<c<<" ";
    // cout<<endl;
    pair<lli,lli>ans;
    lli min = 1000000000000;
    for(int i = 0;i<n;i++){
        lli a = divisors[i],b = divisors[i];
        if((lli)a*((x/a)/__gcd(a,(x/a))) == x){
            if(max(a,x/a)<min){
                ans = {a,x/a};
                min = max(a,x/a);
            }
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // cout<<fixed<<setprecision(6)<<time_spent<<endl;
    return 0;
}