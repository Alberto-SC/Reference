#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){__
    string s;
    cin>>s;
    vector<lli> a;
    lli n = s.size();
    lli bi = 0,bp = 0,ai = 0,ap = 0;
    lli pair = 0,impair = 0;
    for(lli i = 0;i<n;i++){
        if(s[i]== 'a' && i&1)ai++;
        if(s[i]== 'a' && !(i&1))ap++;
        if(s[i]== 'b' && i&1)bi++;
        if(s[i]== 'b' && !(i&1))bp++;
    }
    // cout<<bi<<" "<<bp<<" "<<ap<<" "<<ai<<endl;
    for(lli i = 0;i<n;i++){
        if(i&1){
            if(s[i]== 'a'){
                impair+=ai;
                pair+=ap;
                ai--;
            }
            else{
                impair+=bi;
                pair+=bp;
                bi--;
            } 
        }
        else {
            if(s[i] == 'a'){
                impair+=ap;
                pair+=ai;
                ap--;
            }
            else{
                impair+=bp;
                pair+=bi;
                bp--;
            }
        }
    }
    cout<<pair<<" "<<impair<<endl;
    return 0;
}