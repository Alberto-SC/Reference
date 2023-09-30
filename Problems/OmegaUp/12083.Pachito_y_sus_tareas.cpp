#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

lli nextInt() {
    lli x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

int main(){__
    lli n,x,t;
    n = nextInt();   
    t = nextInt();
    vector<lli> a(n);
    for(int i = 0;i<n;i++)
        a[i] = nextInt();
    sort(a.begin(),a.end());
    int cont = 0;
    for(int i = 0;i<n;i++){
        t-=a[i];
        if(t>=0)cont++;
        else break;
    }
    cout<<cont<<endl;
    return 0;
}