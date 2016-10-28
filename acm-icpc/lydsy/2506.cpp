/*
 * ��Ϊû���޸Ĳ��������ǽ�ѯ�����߻� 
 * ��ѯ��ת��Ϊ�ӿ�ͷ��һ�����ѯ�ʣ������Ҷ˵��������� 
 * һ��ʼ����Ϊ�գ��ȵ����δ���ѯ��ʱ����"���Ժ�ѯ�ʲ���Ӱ��"�ĵ�������У���Ӱ����� 
 * ��Ϊѯ�ʱ��Ź�������ֻ��ӵ㡢����ɾ�㣬�ӵ����ʱ�临�Ӷ�O(n)
 * ������������β������Ӱ�� 
 * ��������ΪT(������10^4)������ĳ��ѯ�� 
 * ��p <= \sqrt{T}ʱ�����ڲ�ͬ��p���Խ��з��࣬����pֵ��ͬ��ѯ�ʿ���һ���Ե�ɨ���н�� 
 * ��p > \sqrt{T}ʱ�����Է��ֲ�ͬ��Aiֵ������\sqrt{T}������ˣ�����ͳ�ƣ�����ɨ�� 
 * ��ʱ�临�Ӷ�ΪO(n + m logm \sqrt{T})
 */
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100001, maxm = 100001, maxv = 10001, maxsqp = 101;
int n, m, num[maxn], f1[maxsqp][maxsqp], f2[maxv], ans[maxm];
struct Node
{
	int r, f, p, k, id;
	bool operator < (const Node &x) const { return r < x.r; }
} Q[maxm << 1];
int main()
{
	int lim = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", num + i);
		lim = max(lim, num[i]);
	}
	for(int i = 0, l, r, p, k; i < m; ++i)
	{
		scanf("%d%d%d%d", &l, &r, &p, &k);
		Q[i << 1] = (Node){l - 1, -1, p, k, i};
		Q[(i << 1) + 1] = (Node){r, 1, p, k, i};
	}
	sort(Q, Q + (m << 1));
	for(int i = 0, mi = m << 1, now = 0; i < mi; ++i)
	{
		while(now < Q[i].r)
		{
			++now;
			for(int j = 1; j <= 100; ++j)
				++f1[j][num[now] % j];
			++f2[num[now]];
		}
		if(Q[i].p <= 100)
			ans[Q[i].id] += Q[i].f * f1[Q[i].p][Q[i].k];
		else
			for(int j = Q[i].k; j <= lim; j += Q[i].p)
				ans[Q[i].id] += Q[i].f * f2[j];
	}
	for(int i = 0; i < m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
