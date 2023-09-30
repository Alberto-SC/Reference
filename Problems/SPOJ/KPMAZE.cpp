#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
typedef long long int lli;
const lli mod = 1000000000000007;
int n;
lli mod_pow(lli a,lli b){
    lli ans = 1;
    while(b){
        if(b&1) ans = ans*a;
        a = a*a;
        b>>=1;
    }
    return ans;
}
template<typename T>
struct Matrix{
    vector < vector <T> > A;
    int r,c;
    Matrix(int r,int c){
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c,0));
    }
    vector<T> &operator [](int i){
        assert(i<r);
        assert(i>=0);
        return A[i];
    }
    friend ostream& operator << (ostream &out,Matrix<T> &M){
        for (int i = 0; i < M.r; ++i) 
            for (int j = 0; j < M.c; ++j) 
                out << M[i][j] << " \n"[j == M.c-1];
        return out;
    }
    // void determinant(){
    //     long double det = 1;
    //     for (int i=0; i<n; ++i) {
    //         int k = i;
    //         for (int j=i+1; j<n; ++j)
    //             if (abs (A[j][i]) > abs (A[k][i]))
    //                 k = j; 
    //         if (abs (A[k][i]) < EPS) {
    //             det = 0;
    //             break;
    //         }
    //         swap (A[i], A[k]);
    //         if (i != k)
    //             det = -det;
    //         det *= A[i][i];
    //         for (int j=i+1; j<n; ++j)
    //             A[i][j] /= A[i][i];
    //         for (int j=0; j<n; ++j)
    //             if (j != i && abs (A[j][i]) > EPS)
    //                 for (int k=i+1; k<n; ++k)
    //                     A[j][k] -= A[i][k] * A[j][i];
    //     }
    //     cout<<(int)det;
    // }

    /*
        Works
    */
    int determinant(){
        lli res = 1;
        vector<bool> used(n);
        for (int i = 0; i < n; i++) {
            int p;
            for (p = 0; p < n; p++) {
                if (!used[p] && A[p][i])
                    break;
            }
            if (p >= n)
                return 0;

            res = (res * A[p][i]) % mod;
            used[p] = true;

            int z = mod_pow(A[p][i], mod - 2);
            for (int j = 0; j < n; j++)
                A[p][j] = static_cast<int>(1ll * A[p][j] * z % mod);

            for (int j = 0; j < n; j++) {
                if (j != p) {
                    z = A[j][i];
                    for (int k = 0; k < n; k++) {
                        A[j][k] -= static_cast<int>(1ll * z * A[p][k] % mod);
                        if (A[j][k] >= mod)
                            A[j][k] -= mod;
                        else if (A[j][k] < 0)
                            A[j][k] += mod;
                    }
                }
            }
        }
        return static_cast<int>(res);
    }
    int det() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] %= mod;

        lli res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (; A[j][i]; res = -res) {
                    long long t = A[i][i] / A[j][i];
                    for (int k = i; k < n; k++) {
                        A[i][k] = (A[i][k] - A[j][k] * t) % mod;
                        std::swap(A[j][k], A[i][k]);
                    }
                }
            }
            if (A[i][i] == 0)
                return 0;
            res = res * A[i][i] % mod;
        }
        if (res < 0)
            res += mod;
        return static_cast<int>(res);
    }
};
//Works only if is out of the struct 
int determinantOfMatrix(vector<vector<lli>> mat,int n)   {   
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
            det = (det*mod_pow(-1,index-i)%mod + mod)%mod;     
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
    return (det*mod_pow(total,mod-2)%mod+mod)%mod;   
}
int main(){
    int h,w,u,v,u2,v2,q;
    cin>>w>>h;
    Matrix<long long int> laplacian(h*w,w*h);
    n = (h*w)-1;
    for(int i = 0;i<h;i++){
        for(int j =0;j<w;j++){
            if(j-1>=0){
                laplacian[(i*w)+j][(i*w)+j] = laplacian[(i*w)+j][(i*w)+j]+1;
                laplacian[(i*w)+j][(i*w)+(j-1)] = -1; 
                laplacian[(i*w)+(j-1)][(i*w)+j] = -1; 
            }
            if(i-1>=0){
                laplacian[(i*w)+j][(i*w)+j] = laplacian[(i*w)+j][(i*w)+j]+1;
                laplacian[(i*w)+j][((i-1)*w)+j] = -1; 
                laplacian[((i-1)*w)+j][(i*w)+j] = -1; 
            }
            if(i+1<h){
                laplacian[(i*w)+j][(i*w)+j] = laplacian[(i*w)+j][(i*w)+j]+1;
                laplacian[(i*w)+j][((i+1)*w)+j] = -1; 
                laplacian[((i+1)*w)+j][(i*w)+j] = -1; 
            }
            if(j+1<w){
                laplacian[(i*w)+j][(i*w)+j] = laplacian[(i*w)+j][(i*w)+j]+1;
                laplacian[(i*w)+j][(i*w)+(j+1)] = -1; 
                laplacian[(i*w)+(j+1)][(i*w)+j] = -1; 
            }
        }
    }
    cin>>q;
    for(int i = 0;i<q;i++){
        cin>>u>>v>>u2>>v2;
        u--;
        v--;
        u2--;
        v2--;
        laplacian[(u*w)+v][(u2*w)+v2] = 0;
        laplacian[(u2*w)+v2][(u*w)+v] = 0;
        laplacian[(u*w)+v][(u*w)+v] = laplacian[(u*w)+v][(u*w)+v]-1;
        laplacian[(u2*w)+v2][(u2*w)+v2] = laplacian[(u2*w)+v2][(u2*w)+v2]-1;
    }
    cout<<laplacian<<endl;
    cout<<determinantOfMatrix(laplacian.A,n-1);
    return 0;
}