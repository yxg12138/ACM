#include<cstring>  
#include<iostream>  
#include<cstdio>  
#include<cmath>  
using namespace std;
const int maxn = 110;
int vis[maxn], G[maxn][maxn], N, T,in[maxn], out[maxn];

void dfs(int u)
{
	for (int i = 0; i < maxn; i++)
	{
		if (G[u][i] && !vis[i])
		{
			vis[i] = true;
			dfs(i);	
		}
	}
}


int main()
{
// 	freopen("in.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		memset(G, 0, sizeof(G));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));

		char str[1005];
		scanf("%d", &N);

		for (int i = 0; i < N; i++)
		{
			scanf("%s", str);
			++G[str[0] - 'a'][str[strlen(str) - 1] - 'a'];
			++in[str[0] - 'a'];
			++out[str[strlen(str) - 1] - 'a'];
		}

		bool flag = true;

		int num1 = 0, num2 = 0;

		for (int i = 0; i < maxn; i++)
		{
			if (!flag) break;
			if (in[i] != out[i])
			{
				if (in[i] == out[i] + 1) ++num1;
				else if (in[i] + 1 == out[i]) ++num2;
				else { flag = false; break; }
			}
		}
	

		if (num1 && num2 && num1 + num2>2) flag = false;

		if (flag)
		{
			memset(vis, 0, sizeof(vis));
			for (int i = 0; i < maxn; i++)
			{
				if (in[i]) { 
					vis[i] = true; 
					dfs(i); 
					break;
				}
			}

			bool flag2 = true;
			for (int i = 0; i < maxn; i++)
			{
				if (in[i] && !vis[i]) { flag2 = false; break; }
				if (out[i] && !vis[i]) { flag2 = false; break; }
			}
			if (flag2) printf("Ordering is possible.\n");
			else printf("The door cannot be opened.\n");

		}
		else{
			printf("The door cannot be opened.\n");
		}
	}
		
}