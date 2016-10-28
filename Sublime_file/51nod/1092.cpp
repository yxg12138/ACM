// 1092 回文字符串
// 回文串是指aba、abba、cccbccc、aaaa这种左右对称的字符串。每个字符串
// 都可以通过向中间添加一些字符，使之变为回文字符串。
// 例如：abbc 添加2个字符可以变为 acbbca，也可以添加3个变为 abbcbba。
// 方案1只需要添加2个字符，是所有方案中添加字符数量最少的。
// Input
// 输入一个字符串Str，Str的长度 <= 1000。
// Output
// 输出最少添加多少个字符可以使之变为回文字串。


#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[1005],b[1005];

int Lcs(char* x,char* y)
{
	int n = strlen(x);
	int m = strlen(y);
	int dp[n+1][m+1];
	for(int i=0; i<n+1; i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			if(x[i-1] == y[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else if(dp[i][j-1] <= dp[i-1][j])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = dp[i][j-1];
		}


	return n-dp[n][m];
}

int main()
{
	scanf("%s",a);
	strcpy(b,a);
	reverse(b,b+strlen(b));
	printf("%d\n",Lcs(a,b));
}