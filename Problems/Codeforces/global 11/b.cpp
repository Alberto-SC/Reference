#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        vector<pair<int,int>> h;
        int fw = -1;
        int lw = -1;
        for(int i = 0;i<n;i++){
            if(s[i]== 'W'){
                fw = i;
                break;
            }
        }
        for(int i = n-1;i>=0;i--){
            if(s[i]== 'W'){
                lw = i;
                break;
            }
        }
        for(int i = fw;i<lw;){
            int j = i;
            if(s[i] == 'L'){
                while(j<n &&  s[j] == 'L'){
                    j++;
                }
                h.push_back({j-i,-i});
            }
            if(j ==i)j++;
            i = j;
        }
        int score = 0;
        sort(h.begin(),h.end());
        for(auto c:h){
            // cout<<c.first<<" "<<c.second<<endl;
            for(int i = 0;i<c.first&&k;i++){
                s[(-c.second)+i]= 'W';
                k--;
            }
        }
        // cout<<k<<endl;
        // cout<<s<<endl;
        while(k){
            lw++;
            if(lw<n)
                s[lw]= 'W';
            else break;
            k--;
        }
        while(k){
            fw--;
            if(fw>=0)
                s[fw] = 'W';
            else 
                break;
            k--;
        }
        // cout<<s<<endl;
        for(int i = 0;i<n;i++){
            if(s[i]== 'W' && i-1>=0 && s[i-1] == 'W')score+=2;
            else if(s[i]== 'W')score++;
        }
        cout<<score<<endl;
    }
    return 0;
}


// LWLWLWWWLWLLWL
// 29