#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include <cstring>
#include <cstdlib>
#include<climits>
using namespace std;


/*int main()
{
set<int>ans1;
set<int>::iterator it;
int a,b;
cin>>a>>b;
for(int i = 0 ; i < a; ++i)
{
    int t;
    cin>>t;
    ans1.insert(t);

}

for(int i=0;i<b;++i)
{
    int temp;
    cin>>temp;
    it=ans1.lower_bound(temp);
    if(*it==temp)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}


}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a;
    cin>>a;
    for(int i=0;i<a;++i)
    {
        int k=0;
        int temp;
        cin>>temp;
        int *ans=new int[temp];
        for(int j=0;j<temp;++j)
        {
            int f;
            cin>>f;
            if(j==0)
            {
                ans[0]=f;
                k++;
            }
            else
            {
                if(f>ans[0])
                {
                    ans[k]=f;
                    k++;
                }
                else
                {
                   for(int l=k;l>0;--l)
                   {
                       ans[l]=ans[l-1];
                   }
                   ans[0]=f;
                   k++;
                }
            }
        }
        for(int j=0;j<temp;++j)
        {
            cout<<ans[j]<<' ';
        }
        delete[] ans;
        cout<<'\n';
    }

}
