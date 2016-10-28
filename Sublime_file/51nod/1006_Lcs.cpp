//最长公共子序列
#include <iostream>
#include <cstring>
using namespace std;

char* LCS(const char* x,const char* y)
{
	int m = strlen(x);
	int n = strlen(y);

	int** dp = new int*[m+1];
	for (int i=0;i < m+1;i++)
	{
		dp[i] = new int[n+1];
		dp[i][0] = 0;
	}
	for (int i=0;i < n+1;i++)
	{
		dp[0][i] = 0;
	}
	for (int i=1;i < m+1;i++)
	{
		for (int j=1;j < n+1;j++)
		{
			if (x[i-1] == y[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else if(dp[i][j-1] >= dp[i-1][j])
				dp[i][j] = dp[i][j-1];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	int len = dp[m][n];
	char* result = new char[len+1];
	int cnt = len;
	while (m > 0 && n > 0)
	{
		if (dp[m][n] == dp[m-1][n-1]+1 && x[m-1] == y[n-1])
		{
			result[--cnt] = x[m-1];
			m--;
			n--;
		}
		else if(dp[m][n] == dp[m][n-1])
		{
			n--;
		}
		else m--;
	}
	result[len] = '\0';
	return result;
}

int main()
{
	char x[1005],y[1005];
	cin >> x >> y;
	cout << LCS(x,y) << endl;

	return 0;
}