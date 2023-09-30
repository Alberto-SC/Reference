#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10004;
long long int x[MAXN], y[MAXN];
long long int zx, zy, z2x, z2y;


long long int R(long long int n){
	return (n*(z2x + z2y) - zx*zx - zy*zy);
}
int main()
{
	int t;
	cin>>t;
	for(int a = 0;a<t;a++){
		int n;
		cin>>n;
		zx = z2x = 0;
		zy = z2y = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>x[i]>>y[i];
			zx+=x[i];
			z2x+=(x[i]*x[i]);
			zy+=y[i];
			z2y+=(y[i]*y[i]);
		}
		long long int ans = R(n);
		for(int i = 0;i<n;i++){
			long long int copyx = x[i], copyy = y[i];
			double x_mean = zx - x[i];
			x_mean/=(n - 1);
			double y_mean = zy - y[i];
			y_mean/=(n - 1);
			for (int nu_x = x_mean; nu_x < x_mean + 1; ++nu_x)
			{
				for (int nu_y = y_mean; nu_y < y_mean + 1; ++nu_y)
				{
					zx-=x[i];
					z2x-=(x[i]*x[i]);
					x[i] = nu_x;
					zx+=x[i];
					z2x+=(x[i]*x[i]);
					zy-=y[i];
					z2y-=(y[i]*y[i]);
					y[i] = nu_y;
					zy+=y[i];
					z2y+=(y[i]*y[i]);
					ans = min(ans, R(n));
				}
			}
			zx-=x[i];
			z2x-=(x[i]*x[i]);
			x[i] = copyx;
			zx+=x[i];
			z2x+=(x[i]*x[i]);
			zy-=y[i];
			z2y-=(y[i]*y[i]);
			y[i] = copyy;
			zy+=y[i];
			z2y+=(y[i]*y[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}