#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int fx[]={+0,+1,+1};  
const int fy[]={+1,+0,+1};  
int main(){
    int n;
    cin>>n;
    cout<<7+((n-1)*3)<<endl;
    int x = 1, y = 1;
    cout<<x<<" "<<y<<endl;
    cout<<x+1<<" "<<y+1<<endl;
    cout<<x-1<<" "<<y-1<<endl;
    cout<<x+1<<" "<<y<<endl;
    cout<<x<<" "<<y+1<<endl;
    cout<<x-1<<" "<<y<<endl;
    cout<<x<<" "<<y-1<<endl;
    x++,y++;
    for(int i = 1;i<n;i++){
        for(int j = 0;j<3;j++){
            cout<<fx[j]+x<<" "<<fy[j]+y<<endl;
        }
        x++,y++;
    }
    return 0;
}