/*
 * k��ƿ��֮����㵹�����൱��շת��������Եõ�����Сֵ��Ϊk��ƿ��������������� 
 * �Ӵ�Сö���������� ����Ƿ�������k�������������... 
 */
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
map<int, int> cnt;
int n, k, x, i;
int main()
{
	scanf("%d%d", &n, &k);
	while(n--)
	{
		scanf("%d", &x);
		for(i = 1; i * i < x; ++i)
			if(x % i == 0) ++cnt[i], ++cnt[x / i];
		if(i * i == x) ++cnt[i];
	}
	map<int, int>::iterator it = cnt.end(), jt = cnt.begin();
	for(--it, --jt; it != jt; --it)
		if(it -> second >= k)
		{
			printf("%d\n", it -> first);
			break;
		}
	return 0;
}
