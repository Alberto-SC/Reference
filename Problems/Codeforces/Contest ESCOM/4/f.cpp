#include <bits/stdc++.h>
using namespace std;
int kmp(vector<int>& x, vector<int>& y) {
        int m = x.size(), n = y.size();
        vector<int> f(m + 1);
        int i = 0, j = f[0] = -1;
        while (i < m){
            while (~j && x[i] != x[j]) j = f[j];
            f[++i] = ++j;
        }
        int cnt = 0;
        i = j = 0;
        while (i < n){
            while (~j && y[i] != x[j]) j = f[j];
            i++, j++;
            if (j == m) cnt++, j = 0;
        }
        return cnt;
}
int main(){     
    int n;
    cin>>n;
    vector<string> S(n);
    unordered_map<string, int> m;
    vector<int> a(n), len(n);
    int sum = n-1,cont = 1;
    for (int i = 0; i < n; i++){
        string s;
        cin>>s;
        if(!m[s]){m[s]=cont;cont++;}
        a[i] = m[s];
        len[i] = s.size();
        sum+=s.size();
    }
    // for(int i = 0;i<n;i++)
    //     cout<<a[i]<<" ";
    // cout<<endl;
    // cout<<sum<<endl;
    int ans = sum;
    for (int i = 0; i < n; i++){
        vector<int> p;
        int aa = 0;
        for (int j = i; j < n; j++){
            p.push_back(a[j]);
            aa += len[j] - 1;
            int cnt = kmp(p, a);
            if (cnt == 1) continue;
            ans = min(ans, sum - (aa + (j - i)) * cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}