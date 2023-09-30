#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define fi first
#define se second
#define pii pair<ll,ll>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define cd complex<double>
#define pb push_back
const double PI=acos(-1);

void fft(vector<cd> &a,int invert){
	int n=a.size();
	for(int i=1,j=0;i<n;i++){
		int z=(n>>1);
		for(;(j&z);z=(z>>1)){
			j=(j^z);
		}
		j=(j^z);
		if(i<j)
		swap(a[i],a[j]);
	}
	for(int len=2;len<=n;len=(len<<1)){
		double ang=(2*PI/len)*((invert?-1:1));
		cd wlen(cos(ang),sin(ang));
		for(int i=0;i<n;i+=len){
			cd w(1);
			for(int j=0;j<len/2;j++){
				cd u=a[i+j],v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if(invert){
		for(int i=0;i<n;i++){
			a[i]/=n;
		}
	}
}
vector<int> mult(vector<int> const& a, vector<int> const& b){
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int n=1;
    while(n<(a.size()+b.size()))
        n=(n<<1);
    fa.resize(n);
    fb.resize(n);
    fft(fa,0);
    fft(fb,0);
    for (int i=0;i<n;i++)
        fa[i]*=fb[i];
    fft(fa,1);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}
string s,t;
void conv(char x,char y,vector<int>&a,vector<int>&b){
	//cout<<x<<" "<<y<<endl;
	for(int i=0;i<s.size();i++){
		if(s[i]==x)
		a[i]=1;
		else
		a[i]=0;
	}
	for(int i=0;i<t.size();i++){
		if(t[i]==y)
		b[t.size()-i-1]=1;
		else
		b[t.size()-i-1]=0;
	}
}
vector<int>adj[6];
vector<int>vis(6);
int cnt=0;
void dfs(int i){
	vis[i]=1;
	cnt++;
	for(int j=0;j<adj[i].size();j++){
		if(vis[adj[i][j]]==0)
		dfs(adj[i][j]);
	}
}
int main(){
	io;
	cin>>s>>t;
	vector<int>a(s.size(),0);
	vector<int>b(t.size(),0);
	vector<int>res[6][6];
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(i==j)
			continue;
			conv(char('a'+i),char('a'+j),a,b);
			res[i][j]=mult(a,b);
		}
	}
	
	for(int k=t.size()-1;k<s.size();k++){
		for(int i=0;i<6;i++)
		{
			adj[i].clear();vis[i]=0;
		}
		for(int i=0;i<6;i++){
			for(int j=i+1;j<6;j++){
				if(res[i][j][k]>0 || res[j][i][k]>0){
					adj[i].pb(j);
					adj[j].pb(i);
				}
			}
		}
		int ans=0;
		for(int i=0;i<6;i++){
			if(vis[i]==0){
			dfs(i);
			ans+=cnt-1;
			cnt=0;
			}
		}
		cout<<ans<<" ";
	}
	return 0;
}
