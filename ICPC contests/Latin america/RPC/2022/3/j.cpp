#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n' 
// Function to return all LCS of substrings `X[0…m-1]`, `Y[0…n-1]`
vector<string> LCS(string X, string Y, int m, int n, auto &lookup){
    if (m == 0 || n == 0){
        return {""};
    }
    if (X[m - 1] == Y[n - 1]){
        vector<string> lcs = LCS(X, Y, m - 1, n - 1, lookup);
        for (string &str: lcs) {        // don't remove `&`
            str.push_back(X[m - 1]);
        }
        return lcs;
    }
 
    if (lookup[m - 1][n] > lookup[m][n - 1]) {
        return LCS(X, Y, m - 1, n, lookup);
    }
    if (lookup[m][n - 1] > lookup[m - 1][n]) {
        return LCS(X, Y, m, n - 1, lookup);
    }
 
 
    vector<string> top = LCS(X, Y, m - 1, n, lookup);
    vector<string> left = LCS(X, Y, m, n - 1, lookup);
 
    top.insert(top.end(), left.begin(), left.end());
    return top;
}
 
void LCSLength(string X, string Y, int m, int n, auto &lookup){
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (X[i - 1] == Y[j - 1]) {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
            }
            else {
                lookup[i][j] = max(lookup[i - 1][j], lookup[i][j - 1]);
            }
        }
    }
}
 
vector<string> LCS(string X, string Y){
    int m = X.length(), n = Y.length();
    vector<vector<int>> lookup(m + 1, vector<int>(n + 1));
    LCSLength(X, Y, m, n, lookup);
    vector<string> v = LCS(X, Y, m, n, lookup);
    return v;
}
 
signed main(){__
    int n,m;
    string s,t;
    string X = "aaaaaaaaaa",  Y = "aaa";
    vector<string> lcs = LCS(X, Y); 
    for (string str: lcs) {
        cout << str << endl;
    }
 
    return 0;
}   