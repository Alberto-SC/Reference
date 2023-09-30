#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t,n,x;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        int n = s.size();
        int f0 = -1,l0 = -1,f1 = -1,l1 = -1;
        int zero = 0,uno = 0;
        for(int i = 0;i<n;i++){
            if(s[i]== '0' && f0 == -1)f0 = i;
            if(s[i]== '1' && f1 == -1)f1 = i;
        }
        for(int i = n-1;i>=0;i--){
            if(s[i]== '0' && l0 == -1)l0 = i;
            if(s[i]== '1' && l1 == -1)l1 = i;
        }
        int ans1 = 0,ans2 = 0,ans3 = 0,ans4 = 0;
        if(f1>l0 || f0>l1){cout<<0<<endl;continue;}
        for(int i = f0;i<l0;i++){
            if(s[i]== '1')ans1++;
        }
        ans1+=f0;
        for(int i = f1;i<l1;i++){
            if(s[i]== '0')ans2++;
        }

        for(int i = l0;i>=f0;i--){
            if(s[i]== '1')ans3++;
        }
        ans3+=n-1-l0;
        for(int i = l1;i>=f1;i--){
            if(s[i]== '0')ans4++;
        }
        ans4+=n-1-l1;
        cout<<min({ans2,ans1,ans3,ans4})<<endl;
    }
    return 0;
}