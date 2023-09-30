#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    string s;
    cin>>s;
    vector<string> a = { 
    ":-X", 
    ":~(" ,  
    "%0",
    ":-P",
    ":D",
    ":C",
    "8-0", 
    ":-\\",
    ":-E", 
    ":-0",
    "[:|||:]",
    ":-|",
    ";-)",
    ";-(", 
    ":)",
    ":("
    };
    vector<string> ans;
    vector<int> b(256);
    for(int i = 0;i<s.size();i++)
        b[s[i]]++;

    // for(int i = 0;i<150;i++){
        // cout<<"("<<char(i)<<","<<b[i]<<") ";
    // }
    for(int i = 0;i<a.size();i++){
        // for(int i = 0;i<150;i++)cout<<b[i]<<" ";
        // cout<<endl;
        while(1){
            bool flag = true;
            for(int j = 0;j<a[i].size();j++){
                b[a[i][j]]--;
                // cout<<a[i][j]<<" "<<b[a[i][j]]<<endl;
                if(b[a[i][j]]<0){
                    flag = false;
                }
            }
            if(!flag){
                for(int j = 0;j<a[i].size();j++){
                    b[a[i][j]]++;
                }
                break;
            }
            ans.push_back(a[i]);
        }
    }
    for(auto c:ans)cout<<c<<endl;
    cout<<"LOL"<<endl;
    return 0;
}  

