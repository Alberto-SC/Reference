#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    string s;
    cin>>s;
    int n = s.size();
    map<char,int> mp;
    vector<int> b(4);
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;
    int idxl,idxr;
    int maxx= -1,minn = n+1;
    for(int i = 0;i<n;i++){
        b.assign(4,0);
        for(int j = i;j<n;j++){
            b[mp[s[j]]]++;
            int mn = n+1;
            int mx = -1;
            for(auto c:b)mn = min(mn,c),mx =max(mx,c);
            if(mx-mn<minn){
                minn = mx-mn;
              
            }
        }
    }
    for(int i = 0;i<n;i++){
        b.assign(4,0);
        for(int j = i;j<n;j++){
            b[mp[s[j]]]++;
            int mn = n+1;
            int mx = -1;
            for(auto c:b)mn = min(mn,c),mx =max(mx,c);
            if(mx-mn == minn){
                if((j-i)+1>maxx){
                    maxx = (j-i)+1;
                    idxl = i+1;
                    idxr = j+1;
                    minn = mx-mn;
                }
            }
        }
    }

    cout<<minn<<" "<<maxx<<endl;
    cout<<idxl<<" "<<idxr<<endl;
    return 0;
}