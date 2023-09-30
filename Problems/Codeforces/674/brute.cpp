#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n;
    while(t--){
        cin>>n;
        vector<int> a(3);
        vector<int> b(3);
        for(auto &c:a)cin>>c;
        for(auto &c:b)cin>>c;
        string sa = string(a[0],'a');
        sa+=string(a[1],'b');
        sa+=string(a[2],'c');
        string sb = string(b[0],'a');
        sb+=string(b[1],'b');
        sb+=string(b[2],'c');
        int mn = 1000000000;
        int mx = -1;
        do{
            sort(sb.begin(),sb.end());
            do{
                int winsa = 0;
                // cout<<sa<<" "<<sb<<endl;
                for(int i = 0;i<n;i++){
                    if(sa[i] == 'a' && sb[i]== 'b')winsa++;
                    if(sa[i] == 'b' && sb[i]== 'c')winsa++;
                    if(sa[i] == 'c' && sb[i]== 'd')winsa++;
                }
                mn = min(winsa,mn);
                mx = max(winsa,mx);

            }while(next_permutation(sb.begin(),sb.end()));

        }while(next_permutation(sa.begin(),sa.end()));
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}

