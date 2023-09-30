#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" "; 
#define printc(A)for(auto c:A)cout<<c.r<<" "; 
const long double PI = acos(-1.0);
using comp = complex<long double>;
vector<int> padre[200000];
vector<int> h[200000];
const int N = 5e5;
char s[N], t[N];
int sum[N], rev[N];
struct Complex{
	double r, i;
	Complex(double r = 0, double i = 0): r(r), i(i){}
	inline Complex operator +(const Complex& rhs){
		return Complex(r + rhs.r, i + rhs.i);
	}
	inline Complex operator -(const Complex& rhs){
		return Complex(r - rhs.r, i - rhs.i);
	}
	inline Complex operator *(const Complex& rhs){
		return Complex(r * rhs.r - i * rhs.i, i * rhs.r + r * rhs.i);
	}
	inline Complex operator /=(const int& rhs){
		r /= rhs;
		return *this;
	}
}; 
typedef vector<Complex> vec;

int raiz(int u ,int pos){
    if(padre[pos][u] == u)return u;
    return padre[pos][u]= raiz(padre[pos][u],pos);
}

bool conexos(int u,int v,int pos){
    if(padre[pos][u] == padre[pos][v])return true;
    return false;
}

void union_find(int u,int v,int pos){
    u = raiz(u,pos);
    v = raiz(v,pos);
    if(u == v)return ;
    if(h[pos][u] < h[pos][v]) padre[pos][u] = v; 
    else{
        padre[pos][v] = u;
        if(h[pos][u]  == h[pos][v])++h[pos][u];
    }
}

lesspow(int a){
    int ans = 1;
    while(ans<a)ans<<=1;
    return ans;
}

// int nearestPowerOfTwo(int n){
// 	int ans = 1;
// 	while(ans < n) ans <<= 1;
// 	return ans;
// }
// int mod(int a, int b){
// 	int r = a % b;
// 	if(r < 0) r += b;
// 	return r;
// }
// int reverseBits(int n, int size){
// 	int ans = 0;
// 	while(size--){
// 		ans = (ans << 1) | (n & 1);
// 		n >>= 1;
// 	}
// 	return ans;
// }
// int nBits(int n){
// 	int ans = 0;
// 	while(n){
// 		n >>= 1;
// 		ans++;
// 	}
// 	return ans;
// }

// void fft(vector<comp> & X, int inv){
// 	int n = X.size();
// 	int log2n = nBits(n) - 1;
// 	comp w1 = polar(1.0L, 2.0 * PI / n);
// 	vector<comp> w(n);
// 	comp r;
// 	w[0] = 1;
// 	for(int i = 1; i < n; i++){
// 		w[i] = w[i - 1] * w1;
// 	}
// 	for(int i = 0; i < n; i++){
// 		int pos = reverseBits(i, log2n);
// 		if(i < pos) swap(X[i], X[pos]);
// 	}
// 	int pot = n >> 1, len = 1;
// 	for(int i = 0; i < log2n; i++){
// 		for(int j = 0; j < len; j++){
// 			for(int k = 0; k < pot; k++){
// 				int first = j + 2 * len * k, second = first + len;
// 				r = w[mod(pot * j * inv, n)] * X[second];
// 				X[second] = X[first] - r;
// 				X[first] += r;
// 			}
// 		}
// 		pot >>= 1, len <<= 1;
// 	}
// 	if(inv == -1){
// 		for(int i = 0; i < n; i++){
// 			X[i] /= n;
// 		}
// 	}
// }

// fft(vec &a,int inv){
//     int n = a.size();
//     for(int i = 1,j = 0;i<n-1;i++){
// 		for(int k = n>>1;(j^= k) <k; k>>= 1);
// 			if(i<j) swap(a[i],a[j]);
// 	}
// 	for(int k = 1;k<n;k<<=1){
// 		comp wk = polar(1.0,PI/k*inv);
// 		for(int i = 0;i<n;i+= k<<1){
// 			comp w(1);
// 			for(int j = 0;j<k;j++,w = w*wk){
// 				comp t = a[i+j+k]*w;
// 				a[i+j+k] = a[i+j]-t;
// 				a[i+j] += t;
// 			}
// 		}
// 	}
// 	if(inv == -1)
// 		for(int i = 0;i<n;i++)
// 			a[i]/=n;

// }

//___________________LA FFT CHIDA LA UNICA CON LA QUE SALIO EL PUTO PROBLEMA__________________//
void fft(vec &a, int n, int inverse){
	for (int i = 0; i < n; i++){
		if (rev[i] > i) swap(a[i], a[rev[i]]);
	}
	for (int h = 2; h <= n; h <<= 1){
		double ang = inverse * 2 * PI / h;
		Complex wn(cos(ang), sin(ang));
		for (int j = 0; j < n; j += h){
			Complex w(1, 0);
			for (int k = j; k < j + h / 2; k++){
				Complex u = a[k];
				Complex t = w * a[k + h / 2];
				a[k] = u + t;
				a[k + h / 2] = u - t;
				w = w * wn;
			}
		}
	}
	if (inverse == -1){
		for (int i = 0; i < n; i++) a[i] /= n;
	} 
}
//______________________OTRA FFT CON LA QUE SI SALE________________________//
// void fft(vector<cd> &a,int invert){
// 	int n=a.size();
// 	for(int i=1,j=0;i<n;i++){
// 		int z=(n>>1);
// 		for(;(j&z);z=(z>>1)){
// 			j=(j^z);
// 		}
// 		j=(j^z);
// 		if(i<j)
// 		swap(a[i],a[j]);
// 	}
// 	for(int len=2;len<=n;len=(len<<1)){
// 		double ang=(2*PI/len)*((invert?-1:1));
// 		cd wlen(cos(ang),sin(ang));
// 		for(int i=0;i<n;i+=len){
// 			cd w(1);
// 			for(int j=0;j<len/2;j++){
// 				cd u=a[i+j],v=a[i+j+len/2]*w;
// 				a[i+j]=u+v;
// 				a[i+j+len/2]=u-v;
// 				w*=wlen;
// 			}
// 		}
// 	}
// 	if(invert){
// 		for(int i=0;i<n;i++){
// 			a[i]/=n;
// 		}
// 	}
// }
void convolve(vec &A , vec &B){
    int n0 = A.size()+B.size()-1;
    int n = lesspow(n0);
    A.resize(n);
    B.resize(n);
    fft(A,n,1);
    fft(B,n,1);
    for(int i = 0;i<n;i++){
        A[i]= A[i]*B[i];
    }
    fft(A,n,-1);
    A.resize(n0);
}

int main(){
    scanf("%s", s);
	int na = strlen(s);
	scanf("%s", t);
	int nb = strlen(t);
    vector<int> ans(na-nb+1);
    for(int i = 0;i<(na-nb)+1;i++){
        int N = 30;
        padre[i].resize(30);
        h[i].resize(30,1);
        while(N--)padre[i][N] = N;
    }
    int nfft = lesspow(na+nb);
    for (int i = 0, j = 0; i < nfft; i++){
		rev[i] = j;
		int k = nfft;
		while (j & (k >>= 1)) j &= ~k;
		j |= k;
	}
    for(int i = 0;i<6;i++){
        for(int j = 0;j<6;j++){
            vec CA(na);
            vec CB(nb);
            if(i == j)continue;
            for(int k = 0 ; k < na ; k++)
                if(s[k]-'a' == i)
                    CA[k] =Complex(1,0);
            for(int k = 0 ; k < nb ; k++)
                if(t[k]-'a' == j)
                    CB[nb-k-1] =Complex(1,0);
             //printc(CA)cout<<endl;
             //printc(CB)cout<<endl;
            convolve(CA,CB);
             //printc(CA)cout<<endl<<endl<<endl;
            for(int L = nb-1; L <=  CA.size()-nb;L++){
                int pos = L-(nb-1);
                if(round(CA[L].r) == 0) continue;
                if(conexos(i,j,pos))continue;
                else{ 
                    union_find(i,j,pos);
                    ans[pos]++;      
                }
            }
        }
    }
    // cout<<na<<" "<<nb<<" "<<ans.size()<<endl;
    print(ans);
    cout<<endl;

    return 0;
}