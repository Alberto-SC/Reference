#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

/**
 * Author: Everule ,  gcd,lcm,*,/ functions by Alberto Silva
 * Date: 2022-10-18
 * Source: Codeforces
 * Description: A prime basis for a set of numbers , it defines an array basis such that every number can written 
 as $\Pi basis[i]^{f_{i}}$ for some f and all operations like *,/, gcd, lcm works same as if you have the real prime factorization.
 * Status: tested in [arc122_e]
 * Complexity:  $O(n^{2}\log{A} + n \logA \times (\log\logA)^{2}) $
 */


template<typename T>
struct PrimeBasis{
    void reduce_pair(T& x, T& y){
        bool to_swap = 0;
        if(x > y){
            to_swap ^= 1;
            swap(x, y);
        } 
        while(x > 1 && y % x == 0){
            y /= x;
            if(x > y){
                to_swap ^= 1;
                swap(x, y);
            }
        }
        if(to_swap) swap(x, y);
    }
    vector<T> basis;

    void solve_inner(int pos, T &val){
        while(basis[pos] % val == 0) basis[pos] /= val;
        vector<T> curr_basis = {basis[pos], val};
        int c_ptr = 1;
        while(c_ptr < curr_basis.size()){
            for(int i=0;i<c_ptr;i++){
                reduce_pair(curr_basis[i], curr_basis[c_ptr]);
                if(curr_basis[c_ptr] == 1) break;
                if(curr_basis[i] == 1) continue;
                T g = gcd(curr_basis[c_ptr], curr_basis[i]);
                if(g > 1){
                    curr_basis[c_ptr] /= g;
                    curr_basis[i] /= g;
                    curr_basis.push_back(g);
                }
            }
            ++c_ptr;
        }
        basis[pos] = curr_basis[0];
        val = curr_basis[1];
        for(int i=2;i<curr_basis.size();i++) if(curr_basis[i] > 1) basis.push_back(curr_basis[i]);
        if(basis[pos] == 1){
            swap(basis[pos], basis.back());
            basis.pop_back();
        }
    }
    void add_element(T val){
        for(int i=0;i<basis.size();i++){
            reduce_pair(val, basis[i]);
            if(basis[i] == 1){
                swap(basis[i], basis.back());
                basis.pop_back();
                continue;
            }
            if(val == 1) return;
            if(gcd(basis[i], val) > 1) solve_inner(i, val);
        }
        if(val > 1) basis.push_back(val);
    }
    void verify_basis(){
        for(int i=0;i<basis.size();i++){
            for(int j=i+1;j<basis.size();j++){
                assert(gcd(basis[i], basis[j]) == 1);
            }
        }
    }
    bool verify_element(T ele){
        for(auto &x : basis){
            while(ele % x == 0) ele /= x;
        }
        return (ele == 1);
    }
    auto factorization(T ele){
        vector<int> factors(basis.size());
        for(int i=0;i<basis.size();i++){
            while(ele % basis[i] == 0){
                factors[i]++;
                ele /= basis[i];
            }
        }
        return factors;
    }

    auto lcm(T a,T b){
        vector<int> lcm(basis.size());
        if(!verify_element(a))
            add_element(a);
        if(!verify_element(b))
            add_element(b);
        vector<int> fa = factorization(a);
        vector<int> fb = factorization(b);
        return lcm(fa,fb);
    }
    auto lcm(vector<int> fa,vector<int> fb){
        vector<int> lcm(basis.size());
        for(int i = 0;i<basis.size();i++){
            lcm[i] = max(fa[i],fb[i]);
        }
        return lcm;
    }

    auto gcd(T a,T b){
        vector<int> gcd(basis.size());
        if(!verify_element(a))
            add_element(a);
        if(!verify_element(b))
            add_element(b);
        vector<int> fa = factorization(a);
        vector<int> fb = factorization(b);
        for(int i = 0;i<basis.size();i++){
            gcd[i] = min(fa[i],fb[i]);
        }
        return gcd;
    }
};

// exclude-from-here

vector<int> facts[107];
signed main(){__
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    
    PrimeBasis<int> pb;
    for(int i = 0;i<n;i++)
        pb.add_element(nums[i]);

    int N = pb.basis.size();
    map<int,vector<int>> mp;    
    set<int> st; 

    for(int i = 0;i<n;i++){
        st.insert(i);
        facts[i] = pb.factorization(nums[i]);
    }

    vector<int> ans;
    bool flag = true;
    while(st.size()){
        int idx = -1;
        for(auto c:st){
            vector<int> a(N);
            for(auto d:st){
                if(c ==d)continue;
                a = pb.lcm(a,facts[d]);
            }
            vector<int> nwLcm = pb.lcm(facts[c],a);
            if(nwLcm != a){
                ans.push_back(c);
                idx = c;
                break;
            }
        }
        if(idx ==-1){
            flag = false;
            break;
        }
        st.erase(idx);        
    }

    reverse(ans.begin(),ans.end());
    vector<int> lcm(pb.basis.size());
    for(auto c:ans){
        auto nlcm = pb.lcm(lcm,pb.factorization(nums[c]));
        if(nlcm == lcm){
            flag = false;
            break;
        }
        lcm = nlcm;
    }
    if(flag){
        cout<<"Yes"<<endl;
        for(auto c:ans)cout<<nums[c]<<" ";
        cout<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}
