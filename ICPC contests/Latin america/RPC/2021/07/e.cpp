#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
const int mod = 37;

struct Matrix{
    vector<vector<int>> A;
    int r,c;
    Matrix(int n,int m){
        A.resize(n,vector<int> (m,0));
        r = n;
        c = m;
    } 
    Matrix(int n){
        A.resize(n,vector<int>(n,0));
        for(int i = 0;i<n;i++)A[i][i] = 1;
        r = c = n;
    }
    Matrix(int n,int m,int v){
        A.resize(n,vector<int>(m,v));
        r = n;
        c = m;
    }

    Matrix operator * (const Matrix &B){    
        Matrix C(r,B.c,0);
        for(int i=0 ; i<r ; i++)
            for(int j=0 ; j<B.c ; j++)
                for(int k=0 ; k<c ; k++)
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ))%mod;
                    
        return C;
    }

    void operator *=(const Matrix B){
        (*this) = (*this)*B;
    }
    Matrix operator ^(int p){
        Matrix id(c);
        Matrix res(r,c);
        for(int i = 0;i<r;i++)for(int j = 0;j<c;j++)res[i][j] =A[i][j];
        while(p){
            if(p&1) id*=res;
            res*=res;
            p>>=1;
        }
        return id;
    }

    vector<int>& operator [](int i){
        return A[i];
    }
    const vector<int>&  operator [](int i)const{
        return A[i];
    }
    friend ostream& operator <<(ostream &out ,const Matrix &M){
        for(int i = 0;i<M.r;i++)
            for(int j = 0;j<M.c;j++)
                out<<M[i][j]<<" \n"[j == M.c-1];
        return out; 
    }
};


signed main(){
	int t= 1,n;
    while(t--){
        cin>>n;
        string s;
        Matrix M(n,n);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>M[i][j];
            }
        }
        // cout<<M<<endl;
        getline(cin,s);
        getline(cin,s);
        int N = s.size();
        vector<Matrix> vec;
        int numVec = N/n;
        if(N%n)numVec++;
        for(int i =0;i<numVec;i++){
            Matrix v(n,1);
            for(int j = 0;j<n;j++){
                if(((i*n)+j)<N){    
                    if(s[(i*n)+j]==' ')
                        v[j][0] = 36; 
                    else if(s[(i*n)+j]<='Z' && s[(i*n)+j]>='A'){
                        v[j][0] = s[(i*n)+j]-'A';
                    }
                    else{
                        v[j][0] = (s[(i*n)+j]-'0')+26;
                    }
                }
                else{
                    v[j][0] = 36;
                }
            }
            vec.push_back(v);
        }
        for(int i = 0;i<vec.size();i++){
            Matrix res = M*vec[i];
            // cout<<res<<endl;
            for(int j = 0;j<n;j++){
                if(res[j][0]==36)cout<<" ";
                else if(res[j][0]<=25)cout<<char(res[j][0]+'A');
                else cout<<char((res[j][0]-26)+'0');
            }
        }
        cout<<endl;
    }
    return 0;
}  
