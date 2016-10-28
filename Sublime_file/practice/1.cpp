// 怎样判断一个图是否为二分图？
// 很简单，用染色法，即从其中一个顶点开始，将跟它邻接的点染成与
// 其不同的颜色，如果邻接的点有相同颜色的，则说明不是二分图，
// 每次用bfs遍历即可。
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 510;
int col[N],g[N][N];

bool bfs(int s,int n)
{
	queue<int> p;
	p.push(s);
	col[s] = 1;
	while(!p.empty())
	{
		int from = p.front();
		p.pop();
		for(int i=1; i<=n; i++)
		{
			if(g[from][i] && col[i]==-1)
			{
				p.push(i);
				col[i] = !col[from];
			}
			if(g[from][i] && col[from] == col[i])
				return false;
		}
	}
	return false;
}

int main()
{
	int n,m,a,b,i;
	memset(col,-1,sizeof(col));
	cin >> n >> m;
	for(i=0; i<m; i++)
	{
		cin >> a >> b;
		g[a][b] = g[b][a] = 1;
	}
	bool flag = false;
	for(i=1; i<=n; i++)
	{
		if(col[i]==-1 && !bfs(i,n))
		{
			flag = true;
			break;
		}

	}
	if(flag)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}