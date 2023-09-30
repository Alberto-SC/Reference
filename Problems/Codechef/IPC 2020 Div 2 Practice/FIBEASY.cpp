#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        lli z = 1;
        int cont = 1;
        while(1){
            z*=2;
            if(z>n)break;
            cont++;
        }
        lli y = 1ll<<(cont-1);
        vector<lli> fibo(2);
        fibo[0] =0;
        fibo[1] =1;
        for(int i = 2;i<=60;i++)
            fibo.push_back(fibo[i-1]+fibo[i-2]);
        for(int i = 0;i<=60;i++)
            fibo[i]%=10;
        if(y<60)y--;
        cout<<fibo[(y)%60]<<endl;
    }
    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 26
//   2   4   6   8   10    12    14    16    18    20    22    24 
//       4       8         12          16          20          24
//               8                     16                      24
//                                     16 