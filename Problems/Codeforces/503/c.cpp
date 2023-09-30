#include <bits/stdc++.h>
using namespace std;
const int maxn=100010,maxm=100010;
vector<int>A[maxm],B[maxn];
int main(){
	int n,m,pos=0;
	long long sum=0,ans=1ll<<62;
	cin>>n>>m;
	for(int i=0,p,c;i<n;i++)cin>>p>>c,A[p].push_back(c),p>1?sum+=c:0;
	for(int i=2;i<=m;i++){
		std::sort(A[i].begin(),A[i].end());
		for(int j=A[i].size();j--;)B[A[i].size()-j-1].push_back(A[i][j]);
	}
    for(int i = 0;i<6;i++){
        for(auto c:B[i])cout<<c<<" ";
        cout<<endl;
    }
    cout<<"TOTAL: "<<sum<<endl; 
	int tot=n-A[1].size();
	priority_queue<int>Q;
	for(int i=0;i<=n-A[1].size();i++){
		int l=i+A[1].size()-1;
        cout<<l<<"-----  "<<sum<<endl;
		if(m>1&&l<0)continue;
        cout<<"  pos: "<<pos<<endl;
		for(;pos<l;pos++)
			for(int j=B[pos].size();j--;){sum-=B[pos][j],Q.push(-B[pos][j]),tot--;cout<<B[pos][j]<<" ";}
        cout<<endl;
		for(;tot<i;tot++){sum-=Q.top(),cout<<"TOP: "<<Q.top()<<endl;Q.pop();}
		if(sum<ans)ans=sum;
	}
	printf("%lld\n",ans);
}