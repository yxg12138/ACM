#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 5010;
int n;

struct node 
{
	int L, R, id;

	friend bool operator<(const node& a, const node&b){
		if (a.L != b.L) return a.L > b.L;
		return a.R > b.R;
	}
};

node arr1[maxn], arr2[maxn];
int ans[maxn][2];

bool check(node* arr, int pos)
{
	priority_queue<node> q;
	for (int i = 0; i < n; i++)
		q.push(arr[i]);
	int maxx = 0;
	while (!q.empty())
	{
		node tmp = q.top();
		q.pop();
		if (tmp.R < maxx) return false;
		if (tmp.L < maxx)
		{
			tmp.L = maxx;
			q.push(tmp);
			continue;
		}
		int cur = max(maxx, tmp.L);
		maxx = cur + 1;
		ans[tmp.id][pos] = cur;
	}
	return true;
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	while (~scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &arr1[i].L, &arr2[i].L, &arr1[i].R, &arr2[i].R);
			arr1[i].id = arr2[i].id = i;
		}

		if (check(arr1, 0) && check(arr2, 1))
		{
			for (int i = 0; i < n; i++)
			{
				printf("%d %d\n", ans[i][0], ans[i][1]);
			}
		}
		else
			printf("IMPOSSIBLE\n");
	}
}

