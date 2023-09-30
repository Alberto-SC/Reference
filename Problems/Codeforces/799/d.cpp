#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

bool isPalindrome(string s){
    int n = s.size();
    for(int i = 0;i<n/2;i++){
        if(s[i]!=s[(n-1)-i])return false;
    }
    return true;
}

signed main(){
	int t,n,h,m,x;
    scanf("%d",&t);
    while(t--){
        scanf("%d:%d %d",&h,&m,&x);
        int xh = x/60 ,xm = x%60; 
        int h1 = h,m1 = m; 
        int cont = 0;
        do{ 
            string a = to_string(h1);
            string b = to_string(m1);
            if(a.size()==1)a = "0"+a;
            if(b.size()==1)b = "0"+b;
            // cout<<a<<" "<<b<<endl;
            if(isPalindrome(a+b))cont++;
            m1+=xm;
            int z = m1/60;
            m1%=60;
            h1+=xh+z;
            h1%=24;
        }while(!(h ==h1 && m==m1));
        cout<<cont<<endl;
    }
    return 0;
} 