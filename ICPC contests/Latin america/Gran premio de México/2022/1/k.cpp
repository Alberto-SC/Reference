#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,k,p,n;
    cin>>k>>p;

    vector<int> freq(101,0);
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<pair<int, int>> compressed;
    for (int i = 1; i <= 100 ;i++) {
        if (freq[i] > 0) compressed.emplace_back(i, 500000);
    }
    int N = 300007;
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (const auto &[w, k] : compressed) {
        vector<int> ndp = dp;
        for (int p = 0; p < w; p++) {
            int sum = 0;
            for (int multiple = p, count = 0; multiple <= N; multiple += w, count++) {
                if (count > k) {
                    sum -= dp[multiple - w * count];
                    count--;
                }
                if (sum > 0) ndp[multiple] = 1;
                sum += dp[multiple];
            }
        }
        swap(dp, ndp);
    }

    for(int i = 0;i<k;i++){
        int x;
        cin>>x;
        for(int i = x;i<=x+200;i++){
            if(dp[i]){
                cout<<i-x<<endl;
                break;
            }
        }
    }
    return 0;
} 