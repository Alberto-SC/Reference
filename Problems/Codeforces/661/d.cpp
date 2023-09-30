#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define x first
#define y second
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        cin>>s;
        set<pair<int,int>> st;
        vector<int> ans(n);
        ans[0] = 1;
        st.insert({s[0]-'0',1});
        int last = 1;
        for(int i = 1;i<n;i++){
            if(s[i]== '0'){
              auto it = st.end();
              it--;
              if(it->x == 1){
                pair<int,int> nw = {0,it->y};
                st.erase(it);
                st.insert(nw);
                ans[i] = nw.y;
              }
              else {
                st.insert({0,last+1});
                ans[i]= last+1;
                last++;
              }
            }
            else {
              auto it = st.begin();
              if(it->x == 0){
                pair<int,int> nw = {1,it->y};
                st.erase(it);
                st.insert(nw);
                ans[i] = nw.y;
              }
              else {
                st.insert({1,last+1});
                ans[i] = last+1;
                last++;
              }
            }
        }  
        cout<<last<<endl;
        for(auto c:ans)cout<<c<<" ";
        cout<<endl;
      
    }
    return 0;
}

