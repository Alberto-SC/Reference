#include <bits/stdc++.h>
using namespace std;
#define print(A) for(auto c:A)cout<<c<<" ";cout<<endl;
#define printM(A) for(auto c:A){print(c);}

#define printP(A)for(auto c:A)cout<<"("<<c.x<<","<<c.y<<")  ";cout<<endl;
#define printMP(A)for(auto c:A){printP(c);}
#define endl '\n'
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define ALL(A) A.begin(),A.end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end));\
i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define cerr(s) cerr << "\033[48;5;196m\033[38;5;15m" << s << "\033[0m"
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
typedef long long int lli;
    vector<int> spaces(500,0);
    vector<int> padding(500,0);
map<string,vector<string>> mp;
map<string,pair<int,int>> mpw;
map<string,int> mpc;
map<string,int> mptype;
map<string,pair<int,int>> sizes;

void calculate(string z){
    if(sizes.find(z)!= sizes.end())return;
    int type = mptype[z];
    int sizeh = 0,sizev = 0;
    // cout<<"TYPE "<<type<<endl;
    if(type==1){
        for(auto d:mp[z]){
            if(mpc.find(d)!= mpc.end()){
                    calculate(d);
                    sizeh += sizes[d].first;
                    sizev += sizes[d].second;
            }
            else{
                // cout<<mpw[d].first<<" "<<mpw[d].second<<endl;
                sizeh+=mpw[d].first;
                sizev = max(mpw[d].second,sizev);
            }
        }
        // cout<<"SPACES "<<spaces[mpc[z]]<<" PAdding "<<padding[mpc[z]]<<endl;
        if(mp[z].size()){

            sizeh += spaces[mpc[z]]*(mp[z].size()-1);
            sizeh += padding[mpc[z]]*2;
            sizev += padding[mpc[z]]*2;
        }
    }
    else{
        for(auto d:mp[z]){
            if(mpc.find(d)!= mpc.end()){
                    calculate(d);
                    sizeh += sizes[d].first;
                    sizev += sizes[d].second;
            }
            else{
                sizev+=mpw[d].second;
                sizeh = max(mpw[d].first,sizeh);
            }
        }
        // cout<<"SPACES "<<spaces[mpc[z]]<<" PAdding "<<padding[mpc[z]]<<endl;
        // cout<<"SIze "<<sizeh<<" "<<sizev<<endl;
        if(mp[z].size()){

            sizev += spaces[mpc[z]]*(mp[z].size()-1);
            sizev += padding[mpc[z]]*2;
            sizeh += padding[mpc[z]]*2;
        }
    }
    sizes[z]= {sizeh,sizev};
}

int main(){
    ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
    string instruction,name,a;
    set<set<string>> ss;

    int key = 0;
    set<string> st;
    cin.ignore();

    for(int i = 0;i<n;i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        ss>>instruction;
        if(ss>>a){
            if(instruction == "HorizontalContainer" || instruction == "VerticalContainer"){
                mpc[a] = key++;
                if(instruction == "HorizontalContainer")
                    mptype[a] = 1;
                else 
                    mptype[a] =2;
            }
            else {
                // cout<<a<<endl;
                int z = a.size(),po = 0,coma = 0;
                int x,y;
                string name;
                for(int j = 0;j<z;j++){
                    if(a[j] == '(')name = a.substr(0,j),po = j+1;
                    if(a[j] == ',')x = stoi(a.substr(po,j-po)),coma = j+1;
                    if(a[j] == ')')y = stoi(a.substr(coma,j-coma));
                }
                // cout<<name<<" "<<x<<" "<<y<<endl;
                mpw[name] ={x,y};
            }
        }
        else {
            string name,inst,name2;
            int sp;
            int point = 0,po = 0; 
            int z = instruction.size();
            for(int j = 0;j<z;j++){
                if(instruction[j] == '.')name = instruction.substr(0,j),point = j+1;
                if(instruction[j] == '(')inst = instruction.substr(point,j-point),po = j+1;
                if(instruction[j] == ')' && inst== "add")name2 = instruction.substr(po,j-po);
                else if(instruction[j] == ')' && inst!= "add")sp = stoi(instruction.substr(po,j));
            }
            // cout<<name<<" "<<inst<<" "<<name2<<" "<<sp<<endl;
            if(inst == "setPadding"){
                padding[mpc[name]] = sp;   
            }
            else if(inst == "setSpacing"){
                spaces[mpc[name]] = sp;
            }
            else {
                mp[name].push_back(name2);
            }
        }
    }

    for(auto c:mp){
        if(sizes.find(c.first)!= sizes.end())continue;
        int type = mptype[c.first];
        int sizeh = 0,sizev = 0;
        // cout<<"TYPE "<<type<<endl;
        if(type==1){
            for(auto d:c.second){
                if(mpc.find(d)!= mpc.end()){
                    calculate(d);
                    sizeh += sizes[d].first;
                    sizev += sizes[d].second;
                }
                else{

                    // cout<<mpw[d].first<<" "<<mpw[d].second<<endl;
                    sizeh+=mpw[d].first;
                    sizev = max(mpw[d].second,sizev);
                }
            }
            // cout<<"SPACES "<<spaces[mpc[c.first]]<<" PAdding "<<padding[mpc[c.first]]<<endl;
            if(c.second.size()){
                sizeh += spaces[mpc[c.first]]*(c.second.size()-1);
                sizeh += padding[mpc[c.first]]*2;
                sizev += padding[mpc[c.first]]*2;
            }
        }
        else{
            for(auto d:c.second){
                if(mpc.find(d)!= mpc.end()){
                    calculate(d);
                    sizeh += sizes[d].first;
                    sizev += sizes[d].second;
                }
                else{

                    sizev+=mpw[d].second;
                    sizeh = max(mpw[d].first,sizeh);
                }
            }
            // cout<<"SPACES "<<spaces[mpc[c.first]]<<" PAdding "<<padding[mpc[c.first]]<<endl;
            // cout<<"SIze "<<sizeh<<" "<<sizev<<endl;
            if(c.second.size()){

                sizev += spaces[mpc[c.first]]*(c.second.size()-1);
                sizev += padding[mpc[c.first]]*2;
                sizeh += padding[mpc[c.first]]*2;
            }
        }
        sizes[c.first]= {sizeh,sizev};
    }
    for(auto c:mpw){
        if(mpc.find(c.first)== mpc.end())
            sizes[c.first] = c.second;
    }
    for(auto c:sizes){
        cout<<c.first<<" "<<c.second.first<<" "<<c.second.second<<endl;
    }
    return 0;
}  