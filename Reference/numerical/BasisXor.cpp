
/**
 * Author: Alberto Silva 
 * Source: Codeforces
 * Description: Structure to form a basis in Z2 that alows compute things 
 * around xor because xor is a sum in Z2 like the maxxor possible , minimum ,
 * number of diferent xor´s, kth possible xor 
 * Time: O(\log N)
 */
struct Basis {
    vector<int> a;
    void insert(int x) {
        for (auto &i: a) x = min(x, x ^ i);
        if (!x) return;
        for (auto &i: a) if ((i ^ x) < i) i ^= x;
        a.push_back(x);
        sort(a.begin(), a.end());
    }
    bool can(int x) {
        for (auto &i: a) x = min(x, x ^ i);
        return !x;
    }
    int maxxor(int x = 0) {
        for (auto &i: a) x = max(x, x ^ i);
        return x;
    } 
    int minxor(int x = 0) {
        for (auto &i: a) x = min(x, x ^ i);
        return x;
    }
    int kth(int k) { // 1st is 0
        int sz = (int)a.size();
        if (k > (1LL << sz)) return -1;
        k--; int ans = 0;
        for (int i = 0; i < sz; i++) if (k >> i & 1) ans ^= a[i];
        return ans;
    }
}t;

// Arbirtary size
const int sz = 500;
struct basisxor{
    bitset<sz> bs[sz];
    bitset<sz> index[sz];
    bitset<sz> zero;
    basisxor(){
        for(int i=0;i<sz;i++) bs[i]=zero;
    }
    bitset<sz> chk(bitset<sz> &b){
        bitset<sz> ans;
        int i;
        for(i = sz-1;i>=0;i--){
            if(b[i]== 0)continue;
            if(b.count()== 0)break;
            if(bs[i].count()==0)break;
            b^=bs[i];
            ans^=index[i];
        }
        if(b.count()==0) return ans;
        return zero;
    }

    bool add(bitset<sz> &b,int idx){
        int i;
        bitset<sz> x;
        x[idx]= 1;
        for(i = sz-1;i>=0;i--){
            if(b[i]== 0)continue;
            if(b.count()== 0)break;
            if(bs[i].count()==0)break;
            b^=bs[i];
            x^=index[i];
        }

        if(i ==-1)return false;
        bs[i] = b;
        index[i] = x;
        return true;
    }
    void print(){
        for(int i =sz-1;i>=0;i--){
            cout<<"I: "<<i<<" "<<bs[i]<<" idx: "<<endl;
        }
    }
};

int bin_pow(int a,int b){
    int x = 1;
    while(b){
        if(b&1) x*=a;
        a*=a;
        b>>=1;
    }
    return x;
}
// another
struct basisxor{
    int base[32];
    int sz = 0;
    basisxor(){
        for(int i = 0;i<32;i++)
            base[i] =0;
    }
    void add(int x){
        while(x != 0 && base[31-__builtin_clz(x)]!= 0){
            x^= base[31-__builtin_clz(x)];
        }
        if(!x)return;
        base[31-__builtin_clz(x)] = x;
        sz++;
    }

    int kth(int k){
        int total = bin_pow(2,sz);
        int val = 0;
        for(int i = 31;i>=0;i--){
            if(base[i] == 0)continue;
            if(k<total/2){
                if((val>>i)&1)
                    val^=base[i];
            }
            else{
                if(!((val>>i)&1))
                    val^=base[i];
                k-=total/2;
            }
            total>>=1;
        }
        return val;
    }
};