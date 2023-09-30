#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
 
// Find all possibles values of subset sum


signed main(){__
    int N;
    cin >> N;

    // Sum of elements <= N implies that every element is <= N
    vector<int> freq(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        freq[x]++;
    }

    vector<pair<int, int>> compressed;
    for (int i = 1; i <= N; i++) {
        if (freq[i] > 0) compressed.emplace_back(i, freq[i]);
    }

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

    cout << "Possible subset sums are:\n";
    for (int i = 0; i <= N; i++) {
        if (dp[i] > 0) cout << i << " ";
    }

    // DP if you need the minimum  elements needed to form the sum x
    
    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (const auto &[w, k] : components) {
        vector<int> ndp = dp;
        for (int i = 0; i < w; i++) {   
            deque<pair<int, int>> window;

            for (int j = i, mul = 0; j <= N; j += w, mul++) {
                while (!window.empty() && window.front().second < mul - k)
                    window.pop_front();

                if (!window.empty()) min(ndp[j], window.front().first + mul);

                while (!window.empty() && window.back().first >= dp[j] - mul)
                    window.pop_back();
                
                window.emplace_back(dp[j] - mul, mul);
            }
        }

        swap(ndp, dp);
    }
}

// Subset sum with bitset, complexity is  k²/32 if you try to find if the sum k is obtenible,
// and you compress the array propertly for example only take a[i]<=k and m[i]*a[i]<=k where m[i]
// represent the frecuency of the number a[i] in our array, 
// Otherwise if the total sum is bounded to N equal to the number of elements , the complexity is 
// O(n/32 sqrt(n))

// Using a normal array of elements call solve(a) where a is the array of elements
vector<int> b;
template <int len = 1>
void subset_sum(int n) {
    if (n >= len) {
        subset_sum<std::min(len*2, maxn)>(n);
        return;
    }
    
    bitset<len> dp;
    
    dp[0] = 1;
    for (int x: b) {
        dp = dp | (dp << x);
    }
}

int solve(vector<int> &a) {
    if (a.empty()) return 0;
    sort(a.begin(),a.end());
    int total = 0;
    for (int x: a) total += x;    
    
    int n = a.size();
    a.push_back(0);
    b.clear();
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            int cnt = i-last;
            int x = a[i - 1];
            
            int j = 1;
            while (j < cnt) {
                b.push_back(x * j);
                cnt -= j;
                j *= 2;
            }            
            b.push_back(x * cnt);

            last=i;
        }
    }

    subset_sum(total);
    return closest;
}

// Using a vector of frequencies.
// You can call directrly subset_sum(a) where a is the vector of frequencies or solve(a) where a is the array of elements to build 
// the array of frequencies
template <int len = 1>
void subset_sum(int n,vector<pair<int,int>> &b) {
    if (n >= len) {
        subset_sum<std::min(len*2, maxn)>(n);
        return;
    }
    
    bitset<len> dp;
    dp[0] = 1;
    for(int i = 0;i<b.size();i++){
        int m = b[i].second;
        int val = b[i].first;
        for(int x = 0;(1<<x)<=m;x++){
            dp|= (dp<<((1<<x)*val));
            m-=1<<x;
        } 
        dp |= (dp<<(m*val));
    }

}
 
int solve(vector<int> &a) {
    sort(a.begin(),a.end());
    a.push_back(0);
    b.clear();
    int last = 0;
    vector<pair<int,int>> b;
    for (int i = 1; i <a.size(); i++) {
        if (a[i] != a[i - 1]) {
            int cnt = i-last;
            b.push_back({a[i - 1], cnt});
            last=i;
        }
    }
 
    subset_sum(accumulate(a.begin(), a.end(), 0LL),b);
    return closest;
}