/*
 * ����Լ�������������ǣ���������������������ӵĸ�������ô������ԽС���ִ���Խ�����ԽС��Խ�п����Ƿ����� 
 * ��֦1����ǰ�õ��������ܳ���n 
 * ��֦2��������ǰ�����������ĳ˻�����������������ԽС���ִ���Խ�� 
 * ��֦3�������֦2��x�������ӵ���������ܶ࣬���Լ����Ų��ᳬ��10�� 
 */
#include <cstdio>
const int tot = 10, prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n, ans, cnt;
void dfs(int i, int last, int x, int sum)
{
	if(cnt < sum || cnt == sum && x < ans) cnt = sum, ans = x;
	if(i > tot) return;
	for(int j = 1; j <= last; ++j)
		if((long long)x * prime[i] <= n)
		{
			x *= prime[i];
			dfs(i + 1, j, x, sum * (j + 1));
		}
		else break;
}
int main()
{
	scanf("%d", &n);
	dfs(1, 23, 1, 1);
	printf("%d\n", ans);
	return 0;
}
