#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
#include <cassert>
#include <cmath>
#include <map>
#include <sys/resource.h>
#include <unordered_map>
using namespace std;
typedef unsigned int uint;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<pair<int, int> > VPII;
typedef unordered_map<int, int> MM;

#define FOR(k,a,b) for(uint k(a); k < (b); ++k)
#define REP(k,a) for(uint k=0; k < (a); ++k)


struct NODE
{
	int parent;
	int visitedT;
	int lwT;
	bool articulationNode;
	bool dirCountParent;
	LL sp;
	VI childs;
};

int N, E, u, v, t;
VI favTeam;
VL ans;
VVI edges;
vector<NODE> dfstree;

void DFS(vector<bool>& visited, int parent, int id,MM& mo)
{
	NODE& act = dfstree[id];
	act.parent = parent;
	act.visitedT = t;
	act.lwT = t;
	act.articulationNode = false;
	act.dirCountParent = false;
	act.sp = 0;
	visited[id] = true;
	mo[favTeam[id]]++;
	++t;
	REP(i, edges[id].size())
	{
		const int& o = edges[id][i];
		if(o == parent)
			continue;;
		if (visited[o])
		{
			act.lwT = min(act.lwT, dfstree[o].visitedT);
		}
		else
		{
			act.childs.push_back(o);
			//insert child if needed
			DFS(visited, id, o, mo);
			if (act.visitedT <= dfstree[o].lwT)
			{
				if(parent != -1)
					act.articulationNode = true;
				//this direction is count
				dfstree[o].dirCountParent = true;
			}
			else
			{
				act.lwT = min(act.lwT, dfstree[o].lwT);
			}
		}
	}
	if (parent == -1 && act.childs.size()>=2)
	{
		act.articulationNode = true;
	}
}

void DFS2(int id, MM& mfc, MM& mall)//speed up with vector merge
{
	NODE& act = dfstree[id];
	MM tmp;
	LL sa = 0, sa2 = 0, ans1=0, ans2 = 0;
	REP(i, act.childs.size())
	{
		MM mtmp;
		DFS2(act.childs[i], mtmp, mall);
		//calculate if count
		//LL& an = ans[id];
		if (dfstree[act.childs[i]].dirCountParent && act.articulationNode)
		{
			sa += dfstree[act.childs[i]].sp;
			if(mfc.size()<mtmp.size())
			{
				for (MM::iterator mit = mfc.begin(); mit != mfc.end(); ++mit)
				{
					ans1 += mit->second * 1LL * mtmp[mit->first];
					mtmp[mit->first] += mit->second;
				}
				mfc.swap(mtmp);
			}
			else
			{
				for (MM::iterator mit = mtmp.begin(); mit != mtmp.end(); ++mit)
				{
					ans1 += mit->second * 1LL * mfc[mit->first];
					mfc[mit->first] += mit->second;
				}
			}
		}
		else
		{
			sa2 += dfstree[act.childs[i]].sp;
			if(tmp.size()<mtmp.size())
			{
				for (MM::iterator mit = tmp.begin(); mit != tmp.end(); ++mit)
				{
					ans2 += mit->second * 1LL * mtmp[mit->first];
					mtmp[mit->first] += mit->second;
				}
				tmp.swap(mtmp);
			}
			else
			{
				for (MM::iterator mit = mtmp.begin(); mit != mtmp.end(); ++mit)
				{
					ans2 += mit->second * 1LL * tmp[mit->first];
					tmp[mit->first] += mit->second;
				}
			}
		}
	}
	act.sp = sa + sa2 - 2*ans1 - 2*ans2 - 2 * tmp[favTeam[id]] - 2 * mfc[favTeam[id]] +  mall[favTeam[id]] - 1;
	ans1 = sa - ans1;

	ans1 += mall[favTeam[id]] - mfc[favTeam[id]] - 1;

	
	if(mfc.size()<tmp.size())
	{
		for (MM::iterator mit = mfc.begin(); mit != mfc.end(); ++mit)
		{
			act.sp -= tmp[mit->first]*2LL*mit->second;
			tmp[mit->first] += mit->second;
		}	
		mfc.swap(tmp);
	}
	else
	{
		for (MM::iterator mit = tmp.begin(); mit != tmp.end(); ++mit)
		{
			act.sp -= mfc[mit->first]*2LL*mit->second;
			mfc[mit->first] += mit->second;
		}
	}
	
	ans[id] = ans1;
	mfc[favTeam[id]]++;
	
}

int main(int argc, char** argv) {
#ifdef HOME
	freopen("in.txt", "rb", stdin);
	freopen("out.txt", "wb", stdout);
#endif
	const rlim_t kStackSize = 64 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;
 
    getrlimit(RLIMIT_STACK, &rl);
    rl.rlim_cur = kStackSize;
    result = setrlimit(RLIMIT_STACK, &rl);
	
	scanf("%d %d", &N, &E);
	favTeam.resize(N);
	edges.resize(N);
	ans.resize(N);
	REP(i, N)
		scanf("%d", &favTeam[i]);

	REP(i, E)
	{
		scanf("%d %d", &u, &v);
		--u, --v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<bool> visited(N);
	dfstree.resize(N);
	MM mi, mo, mo2;
	MM::iterator mit;
	t = 0;
	LL res = 0;
	REP(i, N) if(!visited[i])
	{
		mo.clear();
		mo2.clear();
		DFS(visited, -1, i, mo);
		for (mit = mo.begin(); mit != mo.end(); ++mit)
		{
			if (mi.count(mit->first))
			{
				res += mit->second * mi[mit->first];
			}
			mi[mit->first] += mit->second;
		}
		DFS2(i,mo2,mo);
	}
	REP(i, N)
	{
		ans[i] += res;
		printf("%lld\n", ans[i]);
	}
	return 0;
}