#include <bits/stdc++.h>
using namespace std;
 
#define lli long long
#define mod 998244353
#define pb push_back
#define pi pair<int,int>
#define vi vector<int>
#define vpi vector< pi > 
const int N=33;

lli mat[N][N],deg[N];
lli pwr(lli a,lli b){
	lli r=1;
	while(b){
		if(b&1) r=r*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return r;
}

int determinantOfMatrix(lli mat[][N],int n)   {   
    lli num1,num2,det = 1,index,total = 1;   
    lli temp[n + 1];   
    for(int i = 0; i < n; i++){       
        index = i;    
        cout<<"   "<<index<<endl; 
        while(mat[index][i] == 0 && index < n) {   
            cout<<"HERE "<<index<<endl;
            index++;                   
        }   
        if(index == n)     
            continue;        
        if(index != i){   
            for(int j = 0; j < n; j++)   
                swap(mat[index][j],mat[i][j]);      
            det = (det*pwr(-1,index-i)%mod + mod)%mod;     
        }      
        for(int j = 0; j < n; j++)      
           temp[j] = mat[i][j];   
        for(int j = i+1; j < n; j++){   
            num1 = temp[i];    
            num2 = mat[j][i];    
            for(int k = 0; k < n; k++)      
                mat[j][k] = (num1 * mat[j][k]%mod - num2 * temp[k]%mod+2*mod)%mod;              
            total = (total * num1%mod +mod)%mod; 
        }   
    }   
    for(int i = 0; i < n; i++)    
        det = (det * mat[i][i]%mod+mod)%mod;       
    return (det*pwr(total,mod-2)%mod+mod)%mod;   
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,x,y;
		cin>>n>>m>>k;
		memset(mat,0,sizeof mat);
		memset(deg,0,sizeof deg);
		for(int i=1;i<=m;i++){
			cin>>x>>y;
            x--;
            y--;
			mat[x][y]=mat[y][x]=1;
			deg[x]++;
            deg[y]++;
		}  
		for(int i=0;i<n;i++)
			mat[i][i]=(1ll*n*k%mod-deg[i]+mod)%mod;
        for(int i =0 ;i<n;i++)  
            for(int j = 0;j<n;j++)
                cout<<mat[i][j]<<" \n"[j == n-1];
		lli res=pwr(1ll*k*n%mod*k%mod*n%mod,mod-2);
		res=res*pwr(determinantOfMatrix(mat,n),k)%mod;
		cout<<res<<"\n";
	}
	return 0;
}