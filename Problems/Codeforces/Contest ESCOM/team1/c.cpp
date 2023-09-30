#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        n = s.size();
        int lastr = 0;
        vector<int>R;
        for(int i = 0;i<n;i++){
            if(s[i] == 'R')R.push_back(i-lastr),lastr=i;
        }
        R.push_back(n-lastr);
        cout<<max_element(R.begin(),R.end());
    }   
    return 0;
}