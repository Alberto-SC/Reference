#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> s((n*2)-2);
    for(int i = 0;i<(2*n)-2;i++)
        cin>>s[i];
    string ans = string((n*2)-2,'Z');
    vector<bool> used(2*n-2,false);
    bool flag = false;
    for(int i = 0;i<(2*n)-2;i++){
        string t = s[i];
        if(t.size()== n-1){
            // cout<<"PREFIX/SUFFIX "<<t<<endl;
            ans = string((n*2)-2,'X');
            // cout<<ans<<endl;
            ans[i] ='P';
            used.assign((n*2)-2,false);
            bool prefix;
            used[i] =true;
            for(int j = 0;j<n-2;j++){
                string x = t.substr(0,j+1);
                // cout<<"X "<<x<<endl;
                for(int k = 0;k<(2*n)-2;k++)
                    if(s[k] == x && !used[k]){ans[k] = 'P';used[k]= true;break;}
                
            }
            int count = 0;
            for(int k = 0;k<(2*n)-2;k++){
                if(ans[k]== 'P')count++;
            }
            // cout<<ans<<endl;
            if(count ==n-1){
                string other;
                for(int j = 0;j<(2*n)-2;j++)if(s[j].size()== n-1 && j!= i)other = s[j];
                string extra = other.substr(n-2);
                // cout<<"E"<<extra<<" "<<other<<endl;
                for(int j = 1;j<=n-1;j++){
                    string x = t.substr(j)+extra;
                    // cout<<"Z "<<x<<endl;
                    for(int k = 0;k<(2*n)-2;k++)
                        if(s[k] == x && !used[k]){ans[k] = 'S';break;}
                    
                }
                int count2 = 0;
                // cout<<ans<<endl;
                for(int k = 0;k<(2*n)-2;k++)
                    if(ans[k]== 'S')count2++;
                if(count2 == n-1)flag = true;   
            }
        }
        if(flag)break;
    }
    cout<<ans<<endl;
    return 0;
}