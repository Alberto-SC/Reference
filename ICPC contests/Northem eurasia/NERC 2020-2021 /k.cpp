#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#include <bits/extc++.h> /** keep-include */
// To use most bits rather than just the lowest ones:
struct chash { // large odd number for C
	const uint64_t C = lli(4e18 * acos(0)) | 71;
	lli operator()(lli x) const { return __builtin_bswap64(x*C); }
};

int main(){__
	int t= 1,n;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        n = s.size();
        int x = 5000,y = 5000;
        set<pair<int,int>> st;
        for(int i = 0;i<n;i++){
            if(s[i] =='L'){ 
                x--;
            }
            else if(s[i]== 'R'){
                x++;
            }
            else if(s[i] == 'D'){
                y--;
            }
            else if(s[i] == 'U'){
                y++;
            }
            st.insert({x,y});
        }
        gp_hash_table<lli,int,chash> grid({},{},{},{},{1<<16});
        auto f = [&](int x,int y){
            return (y*10000)+x;
        };
        pair<int,int> ans= {5000,5000};
        for(auto c:st){
            if(c.first == 5000 && c.second == 5000)continue;
            grid[f(c.first,c.second)] = true;
            x = 5000,y = 5000;
            for(int i = 0;i<n;i++){
                if(s[i] =='L'){ 
                    if(!grid[f(x-1,y)])
                        x--;
                }
                else if(s[i]== 'R'){
                    if(!grid[f(x+1,y)])
                        x++;
                }
                else if(s[i] == 'D'){
                    if(!grid[f(x,y-1)])
                        y--;
                }
                else if(s[i] == 'U'){
                    if(!grid[f(x,y+1)])
                        y++;
                }
            }
            // cout<<x<<" "<<y<<endl;
            if(x == 5000 && y == 5000){
                ans = c;
                break;
            }
            grid[f(c.first,c.second)] = false;
        }
        cout<<ans.first-5000<<" "<<ans.second-5000<<endl;
    }
    return 0;
}  
