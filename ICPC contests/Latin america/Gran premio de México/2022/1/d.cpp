
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> vi;
const lli mod = 1e9+7;

struct Matrix{
  
    vector<vector<lli>> A;
    
    int r,c;
    
    Matrix(int n,int m){
        A.resize(n,vector<lli> (m,0));
        r = n;
        c = m;
    }
     
    Matrix(int n){
        A.resize(n,vector<lli>(n,0));
        for(int i = 0;i<n;i++)A[i][i] = 1;
        r = c = n;
    }
    
    Matrix (vector<vector<lli>> matriz){
    	
    	int n = matriz.size();
    	int m = matriz[0].size();
    	 A.resize(n, vector<lli>(m, 0));
    	 
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < m; j++){
    			A[i][j] = matriz[i][j];
    		}
    	}
    	r = n, c = m;
    }
    
    Matrix(int n,int m,int v){
        A.resize(n,vector<lli>(m,v));
        r = n;
        c = m;
    }
    
    Matrix operator * (const Matrix B){
        Matrix res(r,B.c,0);
        for(int i = 0;i<r;i++)
            for(int j = 0;j<B.c;j++)
                for(int k = 0;k<c;k++)
                    res[i][j]=(res[i][j] + (A[i][k]*B[k][j])),res[i][j]>=8*mod*mod?res[i][j]%=mod:0;
        for(int i = 0;i<r;i++)for(int j = 0;j<B.c;j++)res[i][j]%=mod;
        return res;
    }
    
    void operator *=(const Matrix B){
        (*this) = (*this)*B;
    }
    
    Matrix operator ^ (lli p){
    	
    	//cout << r << " " << c << endl;
        Matrix id(c);
        Matrix res(r,c);
        
        for(int i = 0; i < r; i++){
        	for(int j = 0; j < c;j++){
        		//cout << A[i][j] << " ";
        		res [i][j] = A[i][j];
        	}
        	//cout << endl;
        }		//res[i][j] = A[i][j];
        
        //cout << "Aqui\n";
        
        while(p){
            if(p&1) id*=res;
            res*=res;
            p>>=1;
        }
        
        return id;
    }

    vector<lli>& operator [](int i){
        return A[i];
    }
    const vector<lli>&  operator [](int i)const{
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out; 
    }
};
	
	
const int inf = 1 << 30;
vector<vi> floyd(vector<vi> & costMatrix, int n){
	
		vector<vi> tmp = costMatrix;
		int V = n;
		
		for(int k = 0; k < V; ++k)
			for(int i = 0; i < V; ++i)
				for(int j = 0; j < V; ++j)
					if(tmp[i][k] != inf && tmp[k][j] != inf)
						tmp[i][j] = min(tmp[i][j], tmp[i][k] + tmp[k][j]);
		return tmp;
}
	


int main (){
	
	int n, m;
	lli k;
	cin>>n>>m>>k;
	
	vector<vi> costMatrix (n, vi(n, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
				//costMatrix[i][j] = (i == j ? 0 : inf);
				costMatrix[i][j] = 0;
				
	
	
	for(int i = 0; i < m; i++){
		int u, v; cin>>u>>v;
		costMatrix[u-1][v-1] = 1;
		costMatrix[v-1][u-1] = 1;
		
		
	}
	
	//vector<vi> pass = floyd(costMatrix, n);
	
	/*
	cout << "   ";
	for(int i = 0; i < n; i++) cout << i+1 << " ";
	cout << endl;
	
	for(int i = 0; i < n; i++){
		cout << i+1 << ": "; 
		
		for(int j = 0; j < n; j++){
			cout << pass[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	Matrix matrizRes (costMatrix);
	//Matrix b(pass);
    cout<<matrizRes<<endl;
	matrizRes = matrizRes ^ k;
	//cout << matrizRes;
	
	cout << matrizRes;
	
	//matrizRes ^ k;
	
	
	/*
	cout << "   ";
	for(int i = 0; i < n; i++) cout << i+1 << " ";
	cout << endl;
	
	for(int i = 0; i < n; i++){
		cout << i+1 << ": "; 
		
		for(int j = 0; j < n; j++){
			cout << pass[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	/*
	long long cont = 0;
	for(int i = 0; i < n; i++){
		if(pass[0][i] != 0 and pass[0][i] <= k) cont++;
	}
	
	long long mod = 1000000000+7;
	
	cout << cont % mod << endl;
	*/
	
	return 0;
}
