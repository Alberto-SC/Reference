#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        string grid[n];
        for(int i = 0;i<n;i++)
            cin>>grid[i];
        bool flag = true;
        for(int i = 0;i<n;i++){
            if(flag);
            for(int j = 0;j<n;j++){
                if(grid[i][j]== '1'){
                    if(i+1 == n || j+1 == n)continue;
                    else {
                        if(grid[i+1][j] == '0' && grid[i][j+1] =='0'){flag = false;break;}
                    }
                }
            }
        }
        cout << "NO\0YES\0" + 3 * flag << endl;
    }
    return 0;
}