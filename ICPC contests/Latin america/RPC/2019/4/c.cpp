 #include <bits/stdc++.h>
 using namespace std;
 int main(){
   int n;
    cin >> n;
    vector<int> divs;
    for(int i = 1; i*i <= n; ++i) {
        if(n%i == 0) {
            divs.push_back(i);
            if(i*i != n) divs.push_back(n/i);
        }
    }
    sort(divs.begin(), divs.end());
    long long res = 1e18;
    for(int c : divs) {
        int l = c;
        int rem = n/c;
        for(int c2 : divs) {
            if(rem%c2 != 0) continue;
            const int w = rem/c2;
            const int h = c2;
            assert(l*w*h == n);
            res = min(res, 2LL*((l*w)+(w*h)+(h*l)));
        }
    }
    cout << res << '\n';
    return 0;
 }