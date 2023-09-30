#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long double ld;

struct point{
	ld x,y;
};
  
struct event {
    ld angle;
    bool enter;
};
vector<point> p;

signed main(){__
    int n;
    ld x,y,r;
    cin>>r>>n;
    p.resize(n);
    for(int i = 0;i<n;i++){
        cin>>x>>y;
        p[i] ={x,y};
    }  

	int ans = 1;
    for(int j=0;j<n;j++){
        vector<event> events; 
        for(int i = 0; i<n;i++){
            if(i == j)
                continue;
            int dx = p[i].x - p[j].x;
            int dy = p[i].y - p[j].y;
            int ds = dx*dx + dy*dy;
            if (ds > 4 * r * r) 
                continue;
            ld A = sqrt(ds) / (2.0 * r);
            ld B = acos(A);
            ld C = atan2(dy, dx);
            events.push_back({C - B, true});
            events.push_back({C + B, false});
        }        
       
        sort(events.begin(), events.end(), [](const event &left, const event &right) {
            if (fabs(left.angle - right.angle) < 1e-6) {
                return left.enter > right.enter;
            }
            if (left.angle < right.angle) {
                return true;
            }
            return false;
        });

        int cont = 1;
        for (const event &ev : events) {
            if (ev.enter) {
                cont++;
                ans = max(ans, cont);
            } else {
                cont--;
            }
        }
		cout<<endl;
    }    
    cout<<ans<<endl; 
    return 0;
}