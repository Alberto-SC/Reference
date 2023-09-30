#include <bits/stdc++.h>
using namespace std;
vector<int> ind;
vector<int> strong_borders (const string& pat) {
    int m = pat.size(), t = -1;
    vector<int> sbord(m + 1);
    
    sbord[0] = -1;
    for (int j = 1; j <= m; ++j) {  // t eh igual a bord[j - 1]
        while (t >= 0 and pat[t] != pat[j - 1]) t = sbord[t];
        ++t;
        if (j == m or pat[t] != pat[j])  sbord[j] = t;
        else  sbord[j] = sbord[t];
    }

    return sbord;
}
int kmp (const string& text, const string& pat) {
    int n = text.size(), m = pat.size(), i = 0, j = 0, occ = 0;
    vector<int> bords = strong_borders(pat);
    while (i <= n - m) {
        while (j < m and pat[j] == text[i + j]) ++j;
        if (j == m) ind.push_back(i+1);
        int KMP_shift = j - bords[j];
        i += KMP_shift;
        j = max(0, j - KMP_shift);
    } 

    return occ;
}

int main(){
    int n,m,q,l,r;
    string s,t;
    cin>>n>>m>>q;
    cin>>s>>t;
    kmp(s,t);
    for(int i = 0 ;i<q;i++){
        cin>>l>>r;
        int il = lower_bound(ind.begin(),ind.end(),l)-ind.begin();
        int ir = upper_bound(ind.begin(),ind.end(),r-(m-1))-ind.begin();
        // cout<<il<<"  "<<ir<<endl;
        if(((r-ir)+1)<m)ir--;
        if(ir<il)cout<<0<<endl;
        else cout<<(ir-il)<<endl;

    }

    return 0;
}