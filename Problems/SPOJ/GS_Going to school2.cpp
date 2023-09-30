#include<bits/stdc++.h>

using namespace std;

typedef complex<long double> base;

#define pb push_back
#define ll long long
#define ld long double

const int maxn=(int)20;
ld sum[maxn],pr[maxn][maxn],a[maxn][maxn];

vector<ld> gauss(const vector< vector<ld> > mx)
{	
	int n=(int)mx.size();
	
	for(int i=0;i<n;i++)
	{	
		memset(a[i],0,sizeof(a[i]));
		
		for(int j=0;j<n+1;j++)
		{
			a[i][j]=mx[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{	
		int pos=i;
		
		for(int j=i+1;j<n;j++)
		{
			if(fabs(a[j][i])>fabs(a[pos][i]))
			{
				pos=j;
			}
		}
		
		for(int j=0;j<n+1;j++)
		{
			ld temp=a[i][j];a[i][j]=a[pos][j];
			
			a[pos][j]=temp;
		}
		
		ld now=a[i][i];
		
		for(int j=0;j<n+1;j++)
		{
			a[i][j]/=now;
		}
		
		for(int j=0;j<n;j++)
		{
			if(j!=i)
			{
				ld now=a[j][i];
				
				for(int k=0;k<n+1;k++)
				{
					a[j][k]-=(a[i][k]*now);
				}
			}
		}	
	}
	
	vector<ld> ret;
	
	for(int i=0;i<n;i++)
	{	
		ret.pb(a[i][n]);
	}
	
	return ret;
}

int main()
{
	int t;cin>>t;
	
	while(t>0)
	{
		int n,s,e;cin>>n>>s>>e;
		
		s--;e--;
		
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			
			cin>>u>>v>>w;
			
			u--;v--;
			
			sum[u]+=w;
			
			sum[v]+=w;
			
			pr[u][v]=w;pr[v][u]=w;
		}
		
		if(s==e)
		{
			ld res=0;
			
			cout<<fixed<<setprecision(5)<<res<<endl;
		}
		
		else
		{
			vector< vector<ld> > p,id;

			for(int i=0;i<n;i++)
			{
				vector<ld> curr;curr.resize(n,0.0);

				curr[i]=1.0;

				id.pb(curr);
			}

			for(int i=0;i<n;i++)
			{
				if(i!=e)
				{
					vector<ld> row_prob;

					for(int j=0;j<n;j++)
					{
						row_prob.pb(pr[i][j]/sum[i]);
					}

					p.pb(row_prob);
				}
				
				else
				{
					vector<ld> zo;zo.resize(n,0.0);zo[e]=1.0;
					
					p.pb(zo);
				}
			}

			vector< vector<ld> > m;

			for(int i=0;i<n;i++)
			{
				vector<ld> v;

				for(int j=0;j<n;j++)
				{
					ld curr=id[i][j]-p[i][j];

					v.pb(curr);
				}

				m.pb(v);
			}
			
			vector< vector<ld> > mx;
			
			for(int i=0;i<n;i++)
			{
				if(i!=e)
				{
					vector<ld> zz;
					
					for(int j=0;j<n;j++)
					{
						if(j!=e)
						{
							zz.pb(m[i][j]);
						}
					}
					
					zz.pb(1.0);mx.pb(zz);
				}
			}

			vector<ld> ans=gauss(mx);int idx=(s<e?s:s-1);
	
			cout<<fixed<<setprecision(5)<<ans[idx]<<endl;
		}
		
		for(int i=0;i<n;i++)
		{	
			sum[i]=0;

			for(int j=0;j<n;j++)
			{
				pr[i][j]=0;
			}
		}
		
		t--;
	}
	
	return 0;
}



