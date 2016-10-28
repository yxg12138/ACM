#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[105];
int d[105][105],n;

bool match(int i, int j)
{
	if ((s[i] == '('&&s[j] == ')') || (s[i] == '['&&s[j] == ']'))
		return true;
	return false;
}

// int match(char a, char b){
// 	if ((a == '('&&b == ')') || (a == '['&&b == ']'))return 1;
// 	return 0;
// }
void dp()
{
	for (int i = 0; i < n; i++)
	{
		d[i + 1][i] = 0;
		d[i][i] = 1;
	}


	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			d[i][j] = n;
			if (match(i, j)) d[i][j] = min(d[i][j], d[i + 1][j - 1]);
			for (int k = i; k < j; k++)
				d[i][j] = min(d[i][j], d[i][k] + d[k + 1][j]);
		}
	}

}

void print(int i,int j)
{
	if (i > j) return;
	if (i == j)
	{
		if (s[i] == '(' || s[j] == ')') printf("()");
		else printf("[]");
		return;
	}

	int ans = d[i][j];
	if (match(i,j) && ans == d[i + 1][j - 1])
	{
		printf("%c", s[i]); print(i + 1, j - 1); printf("%c", s[j]);
		return;
	}

	for (int k = i; k < j; k++)
	{
		if (ans == d[i][k] + d[k + 1][j])
		{
			print(i, k); print(k + 1, j);
			return;
		}
	}

}

int main()
{
	int T, flag = 0;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		memset(s, '\0', sizeof(s));
		memset(d, 0, sizeof(d));
		gets(s);
		gets(s);
		n = strlen(s);

		if (!n){
			if (flag++)printf("\n");
			printf("\n");
			continue;
		}


		dp();
		if (flag++)
			printf("\n");
		print(0, n - 1);
		printf("\n");

		
	}
}


