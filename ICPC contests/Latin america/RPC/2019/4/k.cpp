#include <bits/stdc++.h>
using namespace std;
int kmp(string x, string y) {
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
    string s,s2;
    cin>>s>>s2;
    bool yes;
    int ans = 0,ant = 0,j;
    for(int i = 0;i<s.size()-1;){
        yes = true;
        j = 1;
        while(yes){
            if(ant+j>s.size())break;
            cout<<"J : "<<j<<"  ANT:  "<<ant<<"  "<<s2.substr(ant,j)<<"  ";
            int kmP = kmp(s2.substr(ant,j),s);
            if(kmP == 0)yes = false;
            cout<<"KMP"<<kmP<<endl;
            i++;
            j++;
        }
        ant = i-1;
        ans++;
        cout<<"ANS = "<<ans<<endl;
    }
    cout<<ans-1<<endl;
    return 0;
}