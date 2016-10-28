/*
 * ��ÿ���СΪSize������[N/Size]�飬ÿ���ټ�¼һ������� 
 * ��������Ӳ���������Ĳ��ֿ��Լ�¼������������Ĳ���ֱ�ӱ����޸ģ������ʱ�临�Ӷ�O([N/Size]+SizelogSize)
 * ��������ѯ�ʣ�����Ĳ��ֿ���ֱ�������������ֲ����㣬����Ĳ��ֱ����������ʱ�临�Ӷ�O([N/Size]logSize+Size)
 * �����Size = \sqrt{N}����ʹ���Ӷ���� 
 */
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000010, maxsqn = 1010;
int n, val[maxn], cha[maxn], add[maxsqn], Size;
inline int No(int x) { return (x - 1) / Size + 1; }
void update(int l, int r, int v)
{
	int L, R, NoL = No(l), NoR = No(r);
	if(NoL == NoR)
	{
		for(int i = l; i <= r; ++i)
			val[i] += v;
		L = (NoL - 1) * Size + 1, R = min(NoL * Size, n);
		for(int i = L; i <= R; ++i)
			cha[i] = val[i];
		sort(cha + L, cha + R + 1);
	}
	else
	{
		L = (NoL - 1) * Size + 1, R = NoL * Size;
		for(int i = l; i <= R; ++i)
			val[i] += v;
		for(int i = L; i <= R; ++i)
			cha[i] = val[i];
		sort(cha + L, cha + R + 1);
		L = (NoR - 1) * Size + 1, R = min(NoR * Size, n);
		for(int i = L; i <= r; ++i)
			val[i] += v;
		for(int i = L; i <= R; ++i)
			cha[i] = val[i];
		sort(cha + L, cha + R + 1);
	}
	for(int i = NoL + 1, j = NoR; i < j; ++i)
		add[i] += v;
}
void query(int l, int r, int lim)
{
	int cnt = 0, NoL = No(l), NoR = No(r);
	if(NoL == NoR)
		for(int i = l; i <= r; ++i)
			cnt += val[i] + add[NoL] >= lim;
	else
	{
		for(int i = l, j = NoL * Size; i <= j; ++i)
			cnt += val[i] + add[NoL] >= lim;
		for(int i = (NoR - 1) * Size + 1; i <= r; ++i)
			cnt += val[i] + add[NoR] >= lim;
	}
	for(int i = NoL + 1, L, R; i < NoR; ++i)
	{
		L = (i - 1) * Size + 1;
		R = i * Size;
		cnt += Size - (lower_bound(cha + L, cha + R + 1, lim - add[i]) - cha - L);
	}
	printf("%d\n", cnt);
}
int main()
{
	int q, Num, l, r, v;
	char ch[5];
	scanf("%d%d", &n, &q);
	Size = (int)sqrt(n);
	Num = (n - 1) / Size + 1;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", val + i);
		cha[i] = val[i];
	}
	for(int i = 1, L, R; i <= Num; ++i)
	{
		L = (i - 1) * Size + 1;
		R = min(i * Size, n);
		sort(cha + L, cha + R + 1);
	}
	if(q) while(q--)
	{
		scanf("%s%d%d%d", ch, &l, &r, &v);
		if(ch[0] == 'M') update(l, r, v);
		else query(l, r, v);
	}
	return 0;
}
