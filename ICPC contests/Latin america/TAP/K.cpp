#include <bits/stdc++.h>
#define xx first
#define yy second
#define forn(a,n) for(int i = (a) ; i < (n) ; ++i)
using namespace std;
#define endl "\n"
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

bool SRT(const pll &p1 , const pll &p2)
{
	return p1.xx < p2.xx || (p2.xx == p2.xx && p1.yy < p1.yy);
}

ll inter(pll p1 , pll p2)
{
	ll x = min(p1.yy,p2.yy)-max(p1.xx,p2.xx);
	return max(0LL,x);
}

int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
	ll n , a , b;
	char c;
	cin >> n;
	map<ll,ll> D , J;
	forn(0,n)
	{
		cin >> c >> a >> b;
		if(c == 'D')
			D[a] = max(D[a],b);
		else
			J[a] = max(J[a],b);
	}


 	cout <<"SMF\n";


	vpll v1(D.size());
	vpll v2(J.size());
	cout << v1.size() << " " << v2.size() << '\n';
	map<ll,ll>::iterator it;
	int i;
	for(it = D.begin() , i = 0 ; it != D.end() ; it++ , ++i)
		v1[i] = *it;
	for(it = J.begin() , i = 0 ; it != J.end() ; it++ , ++i)
		v2[i] = *it;

 	cout <<"SMF\n";
	
	ll x =	-1 , y;
	sort(v1.begin() , v1.end() , SRT);
	sort(v2.begin() , v2.end() , SRT);
	pll ans(0,0);

 	cout <<"SMF\n";

	forn(0,v2.size())
	{
		y = inter(v1[0] , v2[i]);
		if(y > x)
		{
			x = y;
			ans = pll(0,i);
		}
	}

	a = 1;
	b = ans.yy;
	c = 0; 
 	cout <<"SMF\n";


	while(!(a == v1.size()-1 && b == v2.size()-1))
	{
		if(a >= v1.size()-1)
			c = 1;
		if(b >= v2.size()-1)
			c = 0;
//		cout << a << ' ' << b << '\n';
		y = inter(v1[a],v2[b]);
		if(!c)
		{
			if(y > x)
			{
				x = y;
				ans = pll(a,b);
				c = 1;
				b++;
			}else
			{
				a++;
			}
		}else
		{
			if(y > x)
			{
				x = y;
				ans = pll(a,b);
				c = 0;
				a++;
			}else
			{
				b++;
			}
		}
	}
	 	cout <<"SMF\n";

	cout << x << '\n';

	return 0;
}