#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }
    int carry = 0;
    string ans;
    for(int i= 49;i>=0;i--){
        int c = 0;
        for(int j = 0;j<n;j++){
            c+=s[j][i]-'0';
        }
        c+=carry;
        ans+= char((c%10)+'0');
        carry = c/10;
    }
    string t = to_string(carry);
    reverse(t.begin(),t.end());
    ans+=t;
    reverse(ans.begin(),ans.end());
    for(int i = 0;i<10;i++)
        cout<<ans[i];
    cout<<endl;
}
