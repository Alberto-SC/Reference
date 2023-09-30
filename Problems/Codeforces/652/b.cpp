#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    int t,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        string t = "";
        bool one = false;
        int last = -1;
        for(int i = n-1;i>= 0;i--)
            if(s[i]== '0'){last = i;break;}

        if(last ==-1){cout<<s<<endl;continue;}
        string ans;
        for(int i = 0;i<last;i++){
            if(i+1<last  &&  s[i]== '1' && s[i+1] == '0'){
                ans+=s[i],i++;
                while(i<last && s[i+1] == '0')i++;
            }
            else ans+=s[i]; 
        }
        for(int i = last;i<n;i++)ans+=s[i];
        bool zero = false;
        for(int i = ans.size();i>=0;i--){
            if(ans[i] == '0')t+=ans[i],zero = true;
            else if(ans[i] == '1' && !zero){
                t+=ans[i];
            }
        }
        reverse(t.begin(),t.end());
        cout<<t<<endl;
    }
    return 0;
}