#include <bits/stdc++.h>
using namespace std;
#define printc(A)for(auto a:A)cout<<a.real()<<" ";
long double PI = acos(-1.0L);
using comp = complex<long double>;
typedef vector<comp> vec;
#define print(A)for(auto c:A)cout<<c<<" ";
#define printM(A)for(auto c:A){print(c);cout<<"\n";}
const int m = 100003;
int lesspow(int a){
    int ans = 1;
    while(ans<a){
        ans<<=1;
    }
    return ans;
}
int nearestPowerOfTwo(int n){
	int ans = 1;
	while(ans < n) ans <<= 1;
	return ans;
}
int mod(int a, int b){
	int r = a % b;
	if(r < 0) r += b;
	return r;
}
int reverseBits(int n, int size){
	int ans = 0;
	while(size--){
		ans = (ans << 1) | (n & 1);
		n >>= 1;
	}
	return ans;
}
int nBits(int n){
	int ans = 0;
	while(n){
		n >>= 1;
		ans++;
	}
	return ans;
}
void fft(vector<comp> & X, int inv){
	int n = X.size();
	int log2n = nBits(n) - 1;
	comp w1 = polar(1.0L, 2.0 * PI / n);
	vector<comp> w(n);
	comp r;
	w[0] = 1;
	for(int i = 1; i < n; i++){
		w[i] = w[i - 1] * w1;
	}
	for(int i = 0; i < n; i++){
		int pos = reverseBits(i, log2n);
		if(i < pos) swap(X[i], X[pos]);
	}
	int pot = n >> 1, len = 1;
	for(int i = 0; i < log2n; i++){
		for(int j = 0; j < len; j++){
			for(int k = 0; k < pot; k++){
				int first = j + 2 * len * k, second = first + len;
				r = w[mod(pot * j * inv, n)] * X[second];
				X[second] = X[first] - r;
				X[first] += r;
			}
		}
		pot >>= 1, len <<= 1;
	}
	if(inv == -1){
		for(int i = 0; i < n; i++){
			X[i] /= n;
		}
	}
}
void convolve(vector<long long> &P,vector<long long> &Q, vector<long long> &C){
    int n0 = P.size() + Q.size() -1;
    int n = lesspow(n0);
	  vector<comp> A(P.size());
	  vector<comp> B(Q.size());
	  for(int i = 0; i < A.size(); i++){
		  A[i] = P[i];
	  } 
	  for(int i = 0; i < B.size(); i++){
		  B[i] = Q[i];
	  }
	  A.resize(n);
	  B.resize(n);
	  fft(A, 1);
	  fft(B, 1);
	  for(int i = 0; i < n; i++){
		  A[i] *= B[i];
	  }
	  fft(A, -1);
	  C.resize(A.size());
	  for(int i = 0; i < C.size(); i++){
		  C[i] = ((long long)round(A[i].real())) % m;
	  }
}
void quitar(vector<long long> & X){
	int l = X.size();
	for(int i = l - 1; i >= 0; i--){
		if(X[i] == 0) X.pop_back();
		else break;
	}
	if(X.size() == 0) X.push_back(0);
}

void multiply(deque<vector<long long>> &polinomios){
  
  while (polinomios.size() > 1) {
    int len = polinomios.size() / 2;
    for (int i = 0; i < len; i += 2) {
        vector<long long> tmp;
        //print(tmp);
        convolve(polinomios[0], polinomios[1], tmp);
        polinomios.pop_front();
        polinomios.pop_front();
        polinomios.push_back(tmp);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  int n,k,qr;
  long long ai;
  cin>>n;
  vector<long long> A;
  deque<vector<long long>> pol(n);
  for (int i = 0; i < n; i++) {
      cin>>ai;
      pol[i] ={ai,1};
  }
  multiply(pol);
  cin>>k;

  quitar(pol[0]);
  //print(pol[0]);
  for(int i = 0;i<k;i++){
    cin>>qr;
    cout<<pol[0][pol[0].size() -qr-1]<<"\n";
  }
}


