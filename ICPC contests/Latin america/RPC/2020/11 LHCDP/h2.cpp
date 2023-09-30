#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
#define LL long long
string s0,s1,s2;
int flag[3][5005];
int cnt=2147483647;
void biaoji(int len)
{
	memset(flag,1,sizeof(flag));
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(s0[j]==s1[(i+j)%len])
				flag[1][i]=0;
			if(s0[j]==s2[(i+j)%len])
				flag[2][i]=0;
			if(s1[j]==s2[(i+j)%len])
				flag[0][i]=0;
		}
	}
}
void chaxun(int len)
{
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			if(flag[0][(j+len-i)%len]&&flag[1][i]&&flag[2][j])
			{
				cnt = min(cnt, max(i,j));
				cnt = min(cnt, max(len-i,len-j));
				cnt = min(cnt, min(i,len-i) + min(j,len-j));
			}
		}
	}
}
int main()
{
	cin>>s0;
	cin>>s1;
	cin>>s2;
	int len=s1.length();
	biaoji(len);
    for(int i = 0;i<3;i++){
        for(int j = 0;j<len;j++){
            cout<<flag[i][j]<<" ";
        }
        cout<<endl;
    }
	chaxun(len);
	if(cnt==2147483647)
		cout<<-1<<endl;
	else
		cout<<cnt<<endl;
}