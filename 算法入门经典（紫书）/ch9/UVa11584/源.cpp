#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;

char str[maxn];
int f[maxn];

bool isPalind(int l, int r)
{
	while (l < r)
	{
		if (str[l] != str[r]) return false;
		++l, --r;
	}
	return true;
}


int main()
{
// 	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str + 1);
		int len = strlen(str + 1);
		memset(f, 0, sizeof(f));	
		for (int i = 1; i <= len; i++)
		{
			f[i] = len + 1;
			for (int j = 1; j <= i; j++)
			{
				if (isPalind(j, i))
				{
					f[i] = min(f[i], f[j - 1] + 1);
				}
			}
		}
		printf("%d\n", f[len]);
	}
}