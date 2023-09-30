#include <bits/stdc++.h>                                        // exclude-line
using namespace std;                                            // exclude-line
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);      // exclude-line
#define int long long                                           // exclude-line 
#define endl '\n'                                               // exclude-line

/**
 * Author: Alberto Silva
 * Date: 2019-10-30
 * Description: A Segment Tree that stores data only if is needed or asked ,
 * that alows to manage bigger "arrays" more than $10^{7}$
 * Time: O(\log N) per query.
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
 *      Node st(0,maximum_size);
 */

struct Node{
    int sum,greater,l,r,lazy;
    bool prop;
    vector<Node> sons;
    Node(int _l,int _r):l(_l),r(_r),lazy(0),greater(0),sum(0),prop(false){}
    void propagate(){
        if(sons.empty() && l!=r){
            int m = (l+r)>>1;
            sons.push_back(Node(l,m));
            sons.push_back(Node(m+1,r));
        }
        if(prop){
            sum = greater = lazy*((r-l)+1);
            if(l!=r){
                sons[0].prop = true;
                sons[1].prop = true;
                sons[1].lazy = lazy;
                sons[0].lazy = lazy;
            }
            prop = false;
        }
    }
    // Update in a range [a,b]
    void update(int a,int b ,int v){
        propagate();
        if(a>r || b<l)return ;
        if(l>=a && r<=b){
            lazy = v;
            prop = true;
            propagate();
            return;
        }
        int m = (l+r)>>1;
        sons[0].update(a,b,v);
        sons[1].update(a,b,v);
        sum = sons[0].sum+sons[1].sum;
        greater=max(sons[0].greater,sons[0].sum+sons[1].greater);
    }
    int query(int k){
        propagate();
        if(l == r){return greater>k?l-1:l;}
        sons[0].propagate();
        // sons[1].propagate();
        if(sons[0].greater>k)
            return sons[0].query(k);
        else 
            return sons[1].query(k-sons[0].sum);
    }

};

// exclude-from-here 
signed main(){
    int n,k,l,r,v;
    char t;
    cin>>n;
    Node st(1,n);
    while(1){
        cin>>t;
        if(t == 'Q'){
            cin>>k;
            cout<<st.query(k)<<endl;
        }
        else if(t == 'I'){
            cin>>l>>r>>v;
            st.update(l,r,v);
            // for(int i = 0;i<st.tree.size();i++)cout<<st.tree[i].lazy<<" "<<st.tree[i].sum<<endl;
        }
        else break;
        // cout<<st.tree[0].sum<<endl;
    }
    return 0;
}