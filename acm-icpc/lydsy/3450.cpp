/*
 * ��ǰ�洮�ĳ�����len����ǰ��Ϊo�ĸ���Ϊpi
 * ��pi�ĸ��ʣ�len = len + 1���Դ𰸵���������Ϊ (len + 1) ^ 2 - len ^ 2 = 2 * len + 1
 * ��(1 - pi)�ĸ��ʣ�len = 0���Դ𰸵���������Ϊ 0
 */
#include <cstdio>
const int maxlen = 300001;
int n;
char s[maxlen];
double pi, len, ans;
int main()
{
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; ++i)
	{
		pi = s[i] == 'x' ? 0.0 : (s[i] == 'o' ? 1.0 : 0.5);
		ans += len * pi * 2 + pi;
		len = len * pi + pi;
	}
	printf("%.4lf\n", ans);
	return 0;
}
