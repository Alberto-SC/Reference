#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>> p(2,vector<int>(n,0));
    for(int z=1,l=0,r=0;z<2;z++,l=0,r=0)
        for(int i=0;i<n;i++)
        {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            int L=i-p[z][i], R=i+p[z][i]-!z;
            cout<<L<<" "<<R<<" "<<(L-1>=0) <<" "<<(R+1<n)<<endl;
            while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
            if(R>r) l=L,r=R;
        }
    for(int i = 0;i<n;i++)cout<<p[0][i]<<" "<<p[1][i]<<endl;
}   