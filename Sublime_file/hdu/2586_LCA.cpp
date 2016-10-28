#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

const int N = 40005;

int n,m,t;
vector<int> adj[N];
vector<int> wei[N];
int dist[N];
bool visit[N];

void init(int n)
{
	for(int i=0; i<=n; i++)
	{
		adj[i].clear();
		wei[i].clear();
	}
}

int dfs(int x,int y)
{
	int res=0;
	memset(visit,0,sizeof(visit));
	memset(dist,0,sizeof(dist));

	stack<int> st;
	st.push(x);
	visit[x] = true;
	while(!st.empty())
	{
		int tx = st.top();
		st.pop();

		if(tx==y) break;
		for(int i=0; i<adj[tx].size(); i++)
		{
			int ty = adj[tx][i];
			if(visit[ty]) continue;
			st.push(ty);
			visit[ty] = true;

			dist[ty] = dist[tx]+wei[tx][i];
		}
	}
	return dist[y];
}

int main()
{
	int a,b,w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		init(n);
		for(int i=0; i<n-1; i++)
		{
			scanf("%d%d%d",&a,&b,&w);
			adj[a].push_back(b);
			adj[b].push_back(a);
			wei[a].push_back(w);
			wei[b].push_back(w);
		}
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",dfs(a,b));
		}
		if(t!=0) printf("\n");
	}

}