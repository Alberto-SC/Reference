#include <bits/stdc++.h>
using namespace std;

int dlog(int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * a) % m;
    map<int, int> vals;
    for (int p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * an) % m;
    }

    for (int q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - q;
            return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

int main(){
    int x = 1,z = 1,k = 1;
    while(x!= 0 && z!= 0 && k != 0){
        cin>>x>>z>>k;
        int dl = dlog(x,k,z);
        if(dl== -1)cout<<"No solution"<<endl;
        else cout<<dl<<endl;
    }

    return 0;
}