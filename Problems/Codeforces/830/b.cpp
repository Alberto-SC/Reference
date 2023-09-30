#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
    int T = 1,n;
    cin>>T;
    while(T--){
        cin>>n;
        string s;
        cin>>s;
        vector<int> ones,zeros;
        for(int i = n-1;i>=0;i--){
            if(s[i]=='1')ones.push_back(i);
            else zeros.push_back(i);
        }
        int moves = 0;
        for(int i = 0;i<n;i++){
            int x;
            if(zeros.size()==0|| ones.size()==0)break;
            if(ones.back()<zeros.back())
                x = 1;
            else 
                x = 0;

            if(x ==1){
                ones.pop_back();
                moves++;
                swap(zeros,ones);
            }
            else{
                zeros.pop_back();
            }
        }
        cout<<moves<<endl;
    }
    return 0;
}