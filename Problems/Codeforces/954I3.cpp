#include <bits/stdc++.h>
using namespace std;
#define print(A)for(auto c:A)cout<<c<<" "; 
#define printc(A)for(auto c:A)cout<<c.r<<" "; 
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

const int N = 5e5;
const long double PI = acos(-1.0);

char s[N], t[N];
int p[10][N];
int sum[N], rev[N];
Complex v1[N], v2[N];

int find(int x, int id){
	return x == p[x][id] ? x : p[x][id] = find(p[x][id], id);
}

bool same(int x, int y, int id){
	return find(x, id) == find(y, id);
}

void unite(int x, int y, int id){
	int fx = find(x, id), fy = find(y, id);
	p[fy][id] = fx;
}

void Fast_Fourier_Transform(Complex *a, int n, int inverse){
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

int main(){
	int n, m, sz, ans;
	scanf("%s", s);
	n = strlen(s);
	scanf("%s", t);
	m = strlen(t);
	sz = 2;
	while (sz < n + m) sz <<= 1;
	for (int i = 0, j = 0; i < sz; i++){
		rev[i] = j;
		int k = sz;
		while (j & (k >>= 1)) j &= ~k;
		j |= k;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 6; j++){
			p[j][i] = j;
		}
	}
	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++){
			if (i == j) continue;
			for (int k = 0; k < sz; k++) v1[k] = v2[k] = Complex(0, 0);
			for (int k = 0; k < n; k++){
				if (s[k] == 'a' + i) v1[k] = Complex(1, 0);
			}
			for (int k = 0; k < m; k++){
				if (t[k] == 'a' + j) v2[m - k - 1] = Complex(1, 0);
			}
			Fast_Fourier_Transform(v1, sz, 1);
			Fast_Fourier_Transform(v2, sz, 1);
			for (int i = 0; i < sz; i++) v1[i] = v1[i] * v2[i];
			Fast_Fourier_Transform(v1, sz, -1);
            //cout<<sz<<endl;
			for (int k = 0; k < n; k++){
				if (v1[k].r > 0.1){
					if (!same(i, j, k)){
						unite(i, j, k);
						sum[k]++;
					}
				}
			}
		}
	}
	for (int i = m - 1; i < n; i++) printf("%d ", sum[i]);
	printf("\n");
	return 0;
}