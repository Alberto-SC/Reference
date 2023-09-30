#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
using comp = complex<long double>;
typedef long double ld;
typedef vector<comp> vec;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printc(A) for(comp c: A )cout<< c.real()<<" ";
#define printM(A)for(auto c: A){print(c)}
vector<int> p_function(const vector<int>& v){
    int n = v.size();
    vector<int> p(n);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && v[j] != v[i])
            j = p[j - 1];
        if(v[j] == v[i])
            j++;
        p[i] = j;   
    }
    return p;
}
int lesspow(int n){
    int p = 1;
    while(p<n)   p<<=1;
    return p;
}
void fft(vec& a, int inv){
	int n = a.size();
	for(int i = 1,j = 0;i<n-1;i++){
		for(int k = n>>1;(j^= k) <k; k>>= 1);
			if(i<j) swap(a[i],a[j]);
	}
	for(int k = 1;k<n;k<<=1){
		comp wk = polar(1.0,PI/k*inv);
		for(int i = 0;i<n;i+= k<<1){
			comp w(1);
			for(int j = 0;j<k;j++,w = w*wk){
				comp t = a[i+j+k]*w;
				a[i+j+k] = a[i+j]-t;
				a[i+j] += t;
			}
		}
	}
	if(inv == -1)
		for(int i = 0;i<n;i++)
			a[i]/=n;
}
void convolve(vec &A,vec &B){
    int n = A.size()+B.size()-1;
    int n0 = lesspow(n);
    A.resize(n0);
    B.resize(n0);
    fft(A,1);
    fft(B,1);
    for(int i = 0;i<n0;i++){
        A[i]*= B[i];
    }
    fft(A,-1);
    A.resize(n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> nums(26);
    string s;
    string t;
    for(auto &c:nums)cin>>c,c--;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    vector<int> color(26, 0);
    vector<vector<int>> cycles;
    for(int i = 0; i < 26; i++){
        if(color[i])
            continue;
        vector<int> cycle;
        int cc = cycles.size() + 1;
        int cur = i;
        while(color[cur] == 0)
        {
            cycle.push_back(cur);
            color[cur] = cc;
            cur = nums[cur];
        }
        cycles.push_back(cycle);
    }
    vector<int> ans(m - n + 1);
    vector<int> s1, t1;
    for(int i = 0; i < n; i++)
        s1.push_back(color[int(s[i] - 'a')]);
    for(int i = 0; i < m; i++)
        t1.push_back(color[int(t[i] - 'a')]);
    vector<int> st = s1;
    st.push_back(0);
    for(auto x : t1)
        st.push_back(x);
    vector<int> pf = p_function(st);
    for(int i = 0; i < m - n + 1; i++)
        if(pf[2 * n + i] == n)
            ans[i] = 1;
    map<char, comp> m1, m2;
    for(auto cur : cycles){
        int k = cur.size();
        for(int i = 0; i < k; i++){
            ld ang1 = 2 * PI * i / k;
            ld ang2 = (PI - 2 * PI * i) / k;
            m1[char('a' + cur[i])] = comp(cosl(ang1), sinl(ang1));
            m2[char('a' + cur[i])] = comp(cosl(ang2), sinl(ang2));
        }
    }
    
    // for(auto c:m1)cout<<c.first<<" "<<c.second<<endl;
    // for(auto c:m2)cout<<c.first<<" "<<c.second<<endl;

    ld ideal = 0;
    for(int i = 0; i < n; i++)
        ideal += (m1[s[i]] * m2[s[i]]).real();
    reverse(s.begin(), s.end());
    vec a(n);
    vec b(m);
    for(int i = 0; i < n; i++)                  
        a[i] = m1[s[i]];                
    for(int i = 0; i < m; i++)
        b[i] = m2[t[i]];
    int szc;
    convolve(a,b);
    for(int i = 0; i < m - n + 1; i++)
        if(fabsl(a[i + n - 1].real() - ideal) > 0.01)
            ans[i] = 0;
    

    for(int i = 0; i < m - n + 1; i++)
        cout<<ans[i];
    cout<<endl;
    return 0;
}