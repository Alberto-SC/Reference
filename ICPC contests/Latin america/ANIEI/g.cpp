#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        int n1,n2,n3,n4;
        scanf("%d.%d.%d.%d",&n1,&n2,&n3,&n4);
        bitset<8> bs1(n1),bs2(n2),bs3(n3),bs4(n4);
        cout<<bs1<<bs2<<bs3<<bs4<<endl;
    }
    return 0;
}  
