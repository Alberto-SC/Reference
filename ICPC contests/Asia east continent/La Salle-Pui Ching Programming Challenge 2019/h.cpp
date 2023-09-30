#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,sa,sb,sc;
    cin>>a>>b>>c;
    int best = 0;
    vector<int> s(3);
    cin>>s[0]>>s[1]>>s[2];
    sort(s.begin(),s.end());
    do{
        int ans = 0;
        if(s[0]>a)ans++;
        if(s[1]>b)ans++;
        if(s[2]>c)ans++;
        best = max(ans,best);

    }while(next_permutation(s.begin(),s.end()));
    cout<<best<<endl;
}
