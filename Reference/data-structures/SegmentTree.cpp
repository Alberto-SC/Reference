#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define int long long                                           // exclude-line 
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: A Segment Tree is a data structure that allows answering range queries 
 * over an array effectively, This includes finding an asossiative function of consecutive array elements ~
 * Time: build: O(n \log N)  query: O(\log N).
 * Status: Tested
 * Problems: 
 *  \begin{itemize}
 *      \item [Codeforces 220E - Little Elephant and Inversions]
 *      \item [Codeforces 459D - Pashmak and Parmida's problem]
 *      \item [Codeforces 840D - Destiny]
 *      \item [Codeforces 61E - Enemy is weak]
 *      \item [RPC 2020/08 problem B]
 *      \item [SPOJ MKTHNUM]
 *  \end{itemize}
 * Usage: 
 *      for(int i = 0;i<n;i++)update(i,i,vector[i]);
 *      STmin ST(N); fill like the recursive one
 *
 */

/*+ ---- Recursive segment tree with lazy propagation ---- */
vector<int> st;
vector<int> lazy;
void propagate(int v,int l ,int r){
    if(!lazy[v])return ;
	// For asigments replace += to = 
    st[v] += ((r-l)+1)*lazy[v];
    if(l!= r){
        lazy[v<<1] += lazy[v];
        lazy[v<<1|1]+= lazy[v];
    }
    lazy[v] = 0;
}
int n; /*+ n is global for use default values and send less parameters */
void update(int l,int r,int val,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return ;
    if(sl>= l && sr<=r){
        lazy[v] += val;
        propagate(v,sl,sr);
        return;
    }
    int m = (sl+sr)>>1;
    update(l,r,val,v<<1,sl,m);
    update(l,r,val,v<<1|1,m+1,sr);
    st[v] = st[v<<1]+st[v<<1|1];
}

int query(int l,int r,int v = 1,int sl = 0,int sr = n-1){
    propagate(v,sl,sr);
    if(r<sl || l>sr || sl>sr)return 0; 
    if(sl>= l && sr<=r)return st[v];
    int m = (sl+sr)>>1;
    return query(l,r,v<<1,sl,m)+query(l,r,v<<1|1,m+1,sr);
}

/*+ ---- Iterative segment tree much faster, setted to return min in a range ---- */

int inf = 1e9;
struct STmin{
    int n;
    vector<int> st;
    STmin(int n):n(n){
        st.resize(2*n,inf);
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = val;
		for (; x >>=1 ; st[x] = min(st[x<<1], st[x<<1|1]));
	}
	inline int query(int l, int r) {
		int ans = inf;
        if(r<l)return 0;
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1) ans = min(ans, st[l]);
			if (~r & 1) ans = min(ans, st[r]);
		}
		return ans;
	}
};

// Min and max in one same iterative segment tree
struct STMinMax{
    int n;
    vector<pair<int,int>> st;
    STMinMax(int n):n(n){
        st.resize(2*n,make_pair(inf,-inf));
    }
	inline void update(int x, int val) {
		x += n;
		st[x] = {val,val};
        while(x>>=1){
            st[x].first = min(st[x<<1].first, st[x<<1|1].first);
            st[x].second = max(st[x<<1].second, st[x<<1|1].second);
        }
	}

	inline pair<int,int> query(int l, int r) {
		pair<int,int> ans = {inf,-inf};
        if(r<l)return {0,0};
		for (l += n, r += n; l <= r; l = (l + 1) / 2, r = (r - 1) / 2) {
			if (l & 1){
                ans.first = min(ans.first, st[l].first);
                ans.second = max(ans.second, st[l].second);
            } 
			if (~r & 1){
                ans.first = min(ans.first, st[r].first);
                ans.second = max(ans.second, st[r].second);
            } 
		}
		return ans;
	}
};



#define lp (p << 1)
#define rp ((p << 1)|1)
#define SUM 0
#define MAX 1
 
template<typename S>
struct info{
    int l, r;
    S sum, max, lazy;
};
 
template<typename T, typename S>
struct segtree{
    info<S> *tree;
    T *a;
    int n, newed;
    segtree(int n, T* a=nullptr): a(a), n(n), newed(false){
        if(a == nullptr){
            this->a = new T[n+1];
            for(int i = 0; i <= n; ++i) this->a[i] = 0;
            newed = true;
        }
        tree = new info<S>[4*n+1];
        build(1, 1, n);
    }
    
    void pushup(int p){
        tree[p].sum = tree[lp].sum + tree[rp].sum;
        tree[p].max = max(tree[lp].max, tree[rp].max);
    }
    
    void pushdown(int p, int ln, int rn){
        if(tree[p].lazy){
            tree[lp].lazy += tree[p].lazy;
            tree[rp].lazy += tree[p].lazy;
            
            tree[lp].sum += (tree[p].lazy * ln);
            tree[rp].sum += (tree[p].lazy * rn);
            
            tree[lp].max += tree[p].lazy;
            tree[rp].max += tree[p].lazy;
            
            tree[p].lazy = 0;
        }           
    }
    
    void build(int p, int l, int r){
        tree[p].l = l;
        tree[p].r = r;
        tree[p].lazy = 0;
        if(l == r){
            tree[p].sum = a[l]; 
            
            tree[p].max = a[l];
            
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(lp, l, mid);
        build(rp, mid+1, r);
        pushup(p);
    } 
    
    void update(int p, int pos, const T& d){
        int L = tree[p].l;
        int R = tree[p].r;
        if(L == pos && R == pos){
            tree[p].sum += d;
            
            tree[p].max += d;   
            
            return;         
        }
        int mid = L + ((R - L) >> 1);
        if(pos <= mid){
            update(lp, pos, d);
        }else{
            update(rp, pos, d);
        }
        pushup(p);
    }
    
    void update(int pos, const T& d){
        update(1, pos, d);  
    }
    
    void update2(int p, int l, int r, const T& d){
        int L = tree[p].l;//L, R是线段树的区间
        int R = tree[p].r;
        //l, r是query的区间
        if(l <= L && r >= R){
            tree[p].lazy += d;
            tree[p].sum += ((S)(R - L + 1))*((S)d);
            
            tree[p].max += d;
            return;
        }
        int mid = L + ((R - L) >> 1);
        pushdown(p, mid - L + 1, R - mid);
        if(l <= mid){
            update2(lp, l, r, d);   
        }
        if(r > mid){
            update2(rp, l, r, d);   
        }
        pushup(p);
    }
    
    void update2(int l, int r, const T& d){
        update2(1, l, r, d);    
    }
    
    void query(int p, int l, int r, S& s, S& m){
        int L = tree[p].l;//L, R是线段树的区间
        int R = tree[p].r;
        if(L >= l && R <= r){
                s = tree[p].sum;
                m = tree[p].max;
            return;
        }   
        int mid = L + ((R - L) >> 1);
        pushdown(p, mid - L + 1, R - mid);
        s = 0; m = numeric_limits<S>::min();
        if(l <= mid){
            S s2 = 0, m2 = numeric_limits<S>::min();
            query(lp, l, r, s2, m2);
                s += s2;
 
                m = max(m, m2);
        }
        if(r > mid){
            S s2 = 0, m2 = numeric_limits<S>::min();
            query(rp, l, r, s2, m2);
                s += s2;
 
                m = max(m, m2);
        }
    }
    
    void query(int l, int r, S& s, S& m){
        query(1, l, r, s, m);   
    }
 
    int querybig(int p, int l, int r, S target){
        int L = tree[p].l;
        int R = tree[p].r;
        if(R < l || L > r || tree[p].max < target) return 0;
        if(L == R){
            return L;
        }
        int mid = L + ((R - L) >> 1);
        pushdown(p, mid - L + 1, R - mid);
        int res = 0;
        if(l <= mid){
            res = querybig(lp, l, r, target);
        }
        if(res) return res;
        return querybig(rp, l, r, target);
    }
 
    int querybig(int l, int r, S target){
        return querybig(1, l, r, target);
    }
    
    ~segtree(){
        delete[] tree;
        if(newed) delete[] a;
    }
};
