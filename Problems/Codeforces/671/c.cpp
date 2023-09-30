#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
 
int main()
{
    IOS
    int t;
    cin>>t;
 
    while (t--)
        {
             int n,x;
             cin>>n>>x;
             ll arr[n];
             for (int i=0;i<n;i++) cin>>arr[i];
 
              bool equal=true;int check=arr[0];
            bool same=false;
            for (int i=0;i<n;i++) if (arr[i]==x) {same=true;break;}
              for (int i=1;i<n;i++)
                 {    
                           if (arr[i]!=check) {equal=false;break;}
 
                 }
 
                if (equal)
                {
                    if (x==check) cout<<0<<endl;
                    else cout<<2<<endl;
                }
                else if (same)
                 cout<<1<<endl;
 
                else
                  {
                    ll c=0;
                    for (int i=0;i<n;i++)
                        c+=(arr[i]-x);
                      if (c!=0) cout<<2<<endl;
                      else cout<<1<<endl;
                  } 
 
             
        }
}  