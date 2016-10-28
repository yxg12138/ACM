#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, L, s[100],cnt;

int dfs(int cur)
{
	if (cnt++ == n)
	{
		for (int i = 0; i < cur; i++){
			if (i&&i % 4 == 0 && i % 64 != 0) cout << " ";
			if (i&&i % 64 == 0) cout << endl;
			cout << (char)('A' + s[i]);
		}
		cout << endl;
		cout << cur << endl;
		return 0;
	}

	for (int i = 0; i < L; i++)
	{
		s[cur] = i;
		int ok = 1;
		for (int j = 1; 2 * j <= cur + 1; j++)
		{
			int equal = 1;
			for (int k = 0; k < j; k++)
			{
				if (s[cur - k] != s[cur-j-k])
				{
					equal = 0;
					break;
				}
			}
			if (equal) { ok = 0; break; }
		}
		if (ok)
		{
			if (!dfs(cur + 1))
				return 0;
		}

	}
	return 1;
}

int main()
{
	while (scanf("%d%d", &n, &L) && (n || L))
	{
		cnt = 0;
		memset(s, 0, sizeof(s));
		dfs(0);
	}

}