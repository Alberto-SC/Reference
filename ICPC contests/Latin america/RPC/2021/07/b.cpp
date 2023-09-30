#include <bits/stdc++.h>
 
using namespace std;
char a[200][200]={0};
char b[2000]={0};
int dy[]={0,-1,-1,-1,0,0,1,1,1};
int dx[]={0,-1,0,1,-1,1,-1,0,1};
int n,m,k;
int vis[21][21][210][210]={0};
int dfs(int x,int y,int sum,int sum1,int last)
{
    if(vis[x][y][sum][sum1]==-1)
        return 0;
    if(sum1>k+1)
        return 0;
    if(b[sum+1]=='\0'&&sum1==k+1)
    {
        cout<<"Yes"<<endl;
        exit(0);
    }
    for(int i=1;i<=8;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx<=0||xx>n||yy<=0||yy>m)
            continue;
        if(a[xx][yy]==b[sum+1])
            dfs(xx,yy,sum+1,sum1+(i!=last),i);
    }
    vis[x][y][sum][sum1]=-1;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    cin>>k;
    cin>>b+1;
    if(strlen(b+1)==0)
    {
        if(k==0)
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
        return 0;
    }
    if(strlen(b+1)<k)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==b[1]&&strlen(b+1)==1&&k==0)
            {
                cout<<"Yes"<<endl;
                exit(0);
            }
            if(a[i][j]==b[1])
            {
                dfs(i,j,1,0,0);
            }
        }
    }
    cout<<"No"<<endl;
}