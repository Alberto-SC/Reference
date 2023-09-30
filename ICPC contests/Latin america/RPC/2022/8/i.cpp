#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

string lcs(const string& X, const string& Y, int m, int n)
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];

    char lcs[index + 1];
    lcs[index] = '\0'; 
    
    int i = m, j = n;
    while (i > 0 && j > 0) {

        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1]
                = X[i - 1]; 
            i--;
            j--;
            index--; 
        }


        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;

}


signed main (){__

    string s1; cin>>s1;
    string s2; cin>>s2;

    int idx = 0;
    while(idx< s1.size() && idx<s2.size() && s1[idx]==s2[idx]){
        idx++;
    }

    int n1 = s1.size();
    int n2 = s2.size();

    string X = s1;
    string Y = s2;
    int m = n1;
    int n = n2;

    string strLcs = lcs(X, Y, m, n);
    int N = strLcs.size();

    int idx2 = 0;
    while(idx2 <N && idx2<n2 && s2[idx2]==strLcs[idx2]){
        idx2++;
    }
    string Z = lcs(X.substr(idx),Y.substr(idx),X.substr(idx).size(),Y.substr(idx).size());
    int ans = n1-idx;
    ans+= (n2-N);
    ans+= Z.size();

    cout<<ans<<endl;
    
    return 0;
}
// djdj|

// djd|
// dj|d
// djj|d
// djjd|

// djdj
// djjd 

// djd