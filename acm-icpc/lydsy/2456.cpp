/*
 * ��Ϊ����������ִ�������һ�룬���Կ��԰�����������ͬ��������������ʣ�µ�һ�������� 
 */
#include <cstdio>
int n, x, ans, cnt;
char ch;
inline void getint(int &x)
{
	while((ch = getchar()) < '0' || ch > '9');
	x = ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9')
		x = (x << 3) + (x << 1) + ch - '0'; 
}
int main()
{
	getint(n);
	while(n--)
	{
		getint(x);
		if(!cnt) ans = x;
		ans == x ? ++cnt : --cnt;
	}
	printf("%d\n", ans);
	return 0;
}
