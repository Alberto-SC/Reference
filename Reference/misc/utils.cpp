#include <bits/stdc++.h>
#define FUNCTION(name,operator) inline void name(int &current, int candidate) {!(current operator candidate) ? current = candidate : false;}
#define io(v) cin>>v
#define toStr(str) #str
#define x first
#define y second

using namespace std;
default_random_engine generator;    cx  
uniform_real_distribution<double> distribution(0.0,1.0);


//--------------good rand-----------------
int gen_base(const int before, const int after) {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt_rand(seed);
    int base = uniform_int_distribution<int>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

#define accuracy chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(accuracy);
int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}


int sum() { return 0; }
template<typename T, typename... Args>
T sum(T a, Args... args) { return a + sum(args...); }


template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <typename T>
ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    for(size_t i = 0; i < v.size(); i++) {
        o << v[i];
        if(i != v.size() - 1) {
            o << ", ";
        }
    }
    o << "]";
    return o;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//FOR PAIRS
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
unordered_map<pair<int,int>,bool,HASH> grid;


int main(){
    // Read files
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    fclose(stdin);
	fclose(stdout);

    //Read until end of line with scanf
    scanf("%[^\n]",s);  
    // a little speed up to map 
    // mp.reserve(1024);
    map<int,int> mp;
    mp.reserve(1024); 
    mp.max_load_factor(0.25);

    // islessgreater is equivalent to (x<y)|| (x>y) since does not exist isequal, you can use this instead
    double x = 2.0,y = 1.0;
    cout<<islessgreater(x,a)<<endl;
    cout<<isgreaterequal(x,a)<<endl;
    
    // clock , can be replaced with time ./a.out in linux
    clock_t begin = clock();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout<<fixed<<setprecision(6)<<time_spent<<endl;

    // Bit operations
	__builtin_popcount(x);
    1 << __builtin_ctz(x);
    1<< (32-__builtin_ctz(x-1));
    // number of zeros in bit representation to the left
    __builtin_clz(x);

    //remove duplicates
    sort( v.begin(), v.end() );
    v.erase(unique( v.begin(), v.end()),v.end());
}

//________________for like python  so useless____________________//
template<typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T>{
	T v;
	number_iterator(T _v) : v(_v) {}
	operator T&(){return v;}
	T operator *() const {return v;}
};
template <typename T>
struct number_range {
	T b,e;
	number_range(T b, T e):b(b),e(e){}
	number_iterator<T> begin(){return b;}
	number_iterator<T> end(){return e;}
};
/* make_pair like functions for our range type */
template<typename T> number_range<T> range(T e) {return number_range<T>(0, e);}

//_______________ inclusive range______________
template<typename T> number_range<T> range(T b, T e) {return number_range<T>(b, e);}
//Now we can do something like:

for (auto i: range(1000))
    sum += i;
or
for (auto i: range(10, 20))
    cout << i << endl;


//C++17
template<typename... Args>
void readln(Args&... args){
    ((cin >> args), ...);
}

template<typename... Args>
void writeln(Args... args){
    ((cout << args << " "), ...);
}

int x;
double y;
readln(x, y); // enter 100 500.1234
writeln(x, "some string", y); // 100 some string 500.1234

//CLAMP///
//Returns x if it is in the interval [low, high] or, otherwise, the nearest value:

cout << clamp(7, 0,  10); //7
cout << clamp(7, 0,  5);  //5
cout << clamp(7, 10, 50); //10
//_________________SPLIT STRING_______________________//
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    input_string.erase(new_end, input_string.end());
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
//much more easy split 
getline(cin,s);
getline(cin, s);
istringstream in(s);
vector<string> words;
string w;
while(getline(in, w, ' ')){
    words.push_back(w);
}

// fast input
int nextInt() {
    int x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

/*----------------------Graph Moves----------------*/
const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

// Para hexagonos 
// con uno de los lados paralelo al eje y 
// En orden representa las direcciones noreste(ne), noroeste(nw),oeste(w),
// suroeste(sw),sureste(nw) y este(e);
int fxy[6][2] = {{-1,0},{-1,+1},{ 0,+1},{+1,0},{+1,-1},{0,-1}};

/*------------------------------------------------*/ 
/*-----------------------Bitmask------------------*/
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


// for a graph with one cycle A->B->C->D if you want to A*A = A*B and B*B = B*C do this->
#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
typedef long double ld;
using comp = complex<long double>;
int main(){
    comp a,b2,a2;
    ld ang1 = 2 * PI * 0/ 3;
    ld ang2 = (PI - 2 * PI * 0) / 3;
    a = comp(cosl(ang1), sinl(ang1));
    a2 = comp(cosl(ang2), sinl(ang2));
    ang1 = 2 * PI * 2 / 3;
    ang2 = (PI - 2 * PI * 2) / 3;
    b2 = comp(cosl(ang2),sinl(ang2));
    cout<<a<<endl;
    cout<<a2<<endl;
    cout<<b2<<endl;
    cout<<a*a2<<endl;
    cout<<a*b2<<endl;
    return 0;
}


// fast input output
int get(){
  char c;
  while(c=getchar(),(c<'0'||c>'9')&&(c!='-'));
  bool flag=(c=='-');
  if(flag)
    c=getchar();
  int x=0;
  while(c>='0'&&c<='9')
    {
      x=x*10+c-48;
      c=getchar();
    }
  return flag?-x:x;
}
 
void output(int x){
    if(x<0)
        {
        putchar('-');
        x=-x;
        }
    int len=0,data[10];
    while(x)
        {
        data[len++]=x%10;
        x/=10;
        }
    if(!len)
        data[len++]=0;
    while(len--)
        putchar(data[len]+48);
    putchar('\n');
}

// Make a png image to show graph 
// graph is an array of vectors vector<int> graph[n]
// you only need to install graphvis  with  sudo apt-get install graphviz and xdg to open automatically 
// this can be installed with sudo apt-get install -y xdg-utils then you only need to call show_graph in any program with a graph 
void show_graph(const bool undirected = true) {
    /*! Converts graph to dot format
     *\param undirected is whether graph is undirected or not */
	ofstream os{"graph.dot"};
	os << (undirected ? "graph" : "digraph");
	os << " G {" << endl;
	for(int u = 0; u < N; ++u) {

		for (const auto v : graph[u]) {
            os << "\t" << u << (undirected ? " -- " : " -> ") << v.first <<" [label= "<<v.second<<"]"<<endl;
            // else{
                // if (!undirected || u <= v) {
                    // os << "\t" << u << (undirected ? " -- " : " -> ") << v <<endl;
                // }
            // }
		}
	}
	os << "}" << endl;
    /* Displays dot using image viewer
    / This command is for Linux. You can change this command for a different OS or for a different image viewer.*/
	system("dot -Tpng graph.dot -o graph.png && xdg-open graph.png");
}



inline int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}
 
inline lli reverse_bits(lli x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}

inline uint32_t(uint32_t n){
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

// operations without overflow
Built-in Function: bool __builtin_mul_overflow (type1 a, type2 b, type3 *res)
Built-in Function: bool __builtin_smul_overflow (int a, int b, int *res)
Built-in Function: bool __builtin_smull_overflow (long int a, long int b, long int *res)
Built-in Function: bool __builtin_smulll_overflow (long long int a, long long int b, long long int *res)
Built-in Function: bool __builtin_umul_overflow (unsigned int a, unsigned int b, unsigned int *res)
Built-in Function: bool __builtin_umull_overflow (unsigned long int a, unsigned long int b, unsigned long int *res)
Built-in Function: bool __builtin_umulll_overflow (unsigned long long int a, unsigned long long int b, unsigned long long int *res)

Built-in Function: bool __builtin_sub_overflow (type1 a, type2 b, type3 *res)
Built-in Function: bool __builtin_ssub_overflow (int a, int b, int *res)
Built-in Function: bool __builtin_ssubl_overflow (long int a, long int b, long int *res)
Built-in Function: bool __builtin_ssubll_overflow (long long int a, long long int b, long long int *res)
Built-in Function: bool __builtin_usub_overflow (unsigned int a, unsigned int b, unsigned int *res)
Built-in Function: bool __builtin_usubl_overflow (unsigned long int a, unsigned long int b, unsigned long int *res)
Built-in Function: bool __builtin_usubll_overflow (unsigned long long int a, unsigned long long int b, unsigned long long int *res)


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template<typename T, typename Comp = std::less<T>>
using OrdTreeBase = __gnu_pbds::tree<T, __gnu_pbds::null_type, Comp,
                                     __gnu_pbds::rb_tree_tag,
                                     __gnu_pbds::tree_order_statistics_node_update>;


template<typename T, typename Comp = std::less<T>>
struct OrderedSet : public OrdTreeBase<T, Comp>
{
    using Base = OrdTreeBase<T, Comp>;
    
    OrderedSet(const auto &...pack)
        : Base(pack...) { }
    
    size_t count_less(const auto &key) const {
        return this->order_of_key(key);
    }
    
    size_t count_less_equal(const auto &key) const {
        return upper_bound_with_order(key).second;
    }
    
    size_t count_greater(const auto &key) const {
        return this->size() - count_less_equal(key);
    }
    
    size_t count_equal(const auto &key) const {
        return count_less_equal(key) - count_less(key);
    }
    
    template<typename Compare = Comp>
    std::pair<typename Base::const_iterator, size_t>
    lower_bound_with_order(const auto &key) const
    {
        auto prev = this->m_p_head;
        auto curr = this->m_p_head->m_p_parent;
        size_t order{};
        while (curr != 0)
            if (Compare()(curr->m_value, key)) {
                order += curr->m_metadata;
                if ((curr = curr->m_p_right))
                    order -= curr->m_metadata;
            } else {
                prev = curr;
                curr = curr->m_p_left;
            }
        return std::make_pair(prev, order);
    }
    
    template<typename Compare = Comp>
    std::pair<typename Base::const_iterator, size_t>
    upper_bound_with_order(const auto &key) const
    {
        auto prev = this->m_p_head;
        auto curr = this->m_p_head->m_p_parent;
        size_t order{};
        while (curr != 0)
            if (Compare()(key, curr->m_value)) {
                prev = curr;
                curr = curr->m_p_left;
            } else {
                order += curr->m_metadata;
                if ((curr = curr->m_p_right))
                    order -= curr->m_metadata;
            }
        return std::make_pair(prev, order);
    }
    
};