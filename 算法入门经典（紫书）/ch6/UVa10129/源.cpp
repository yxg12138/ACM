#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 30;
int vis[maxn], N, T, f[maxn], in[maxn], out[maxn];

void init()
{
	for (int i = 0; i < maxn; i++)
		f[i] = i;
}

int find(int x)
{
	int r = x;
	while (f[r] != r)
		r = f[r];

	int tmp;
	while (r != x)
	{
		tmp = f[x];
		f[x] = r;
		x = tmp;
	}

	return r;

}

void merge(int u, int v)
{
	int f1 = find(u), f2 = find(v);
	if (f1 != f2)
		f[f2] = f1;
}

int main()
{
// 	freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	while (T--)
	{
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));

		char str[1005];
		init();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%s", str);
			++out[str[0] - 'a'];
			++in[str[strlen(str) - 1] - 'a'];
			merge(str[0] - 'a', str[strlen(str) - 1] - 'a');
		}

		int cnt = 0;
		for (int i = 0; i < 26; i++)
		{
			if ((in[i] || out[i]) && f[i] == i)
				++cnt;
		}

		bool flag = true;
		if (cnt != 1) flag = false;

		int num1 = 0, num2 = 0;
		for (int i = 0; i < maxn; i++)
		{
			if (!flag) break;
			if (in[i] != out[i])
			{
				if (in[i] == out[i] + 1) ++num1;
				else if (in[i] + 1 == out[i]) ++num2;
				else{ flag = false; break; }
			}
		}
		if (num1 && num2 && num1 + num2 > 2) flag = false;
		
		if (flag){
			printf("Ordering is possible.\n");
		}
		else{
			printf("The door cannot be opened.\n");
		}
	}
}