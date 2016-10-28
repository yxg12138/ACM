#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 10, INF = 0x3f3f3f3f;
//fenwick tree
int bit_n, bit[maxn];
void add(int x, int val)
{
	for( ; x <= bit_n; x += x & -x)
		bit[x] += val;
}
int sum(int x)
{
	int ret = 0;
	for( ; x > 0; x -= x & -x)
		ret += bit[x];
	return ret;
}
//disjoint set union
int fa[maxn], vis[maxn];
long long size[maxn];
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y, long long delta = 0)// y into x's set
{
	int u = find(x), v = find(y);
	if(u != v)
	{
		fa[v] = u;
		size[u] += size[v] + delta;
		size[v] = 0;
	}
}
//sweep line
struct Line
{
	int id, x, y1, y2, type;
	bool operator < (const Line &t) const
	{
		return x < t.x || x == t.x && type < t.type;
	}
} e[maxn << 1];
int e_tot, pos[maxn << 1];
int y_tot, ypos[maxn << 1];
set<int> Sta, End, y_set;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		fa[i] = i;
		if(x1 == x2)
		{
			size[i] = y2 - y1;
			e[e_tot++] = (Line){i, x1, y1, y2, 1};
			ypos[y_tot++] = y1;
			ypos[y_tot++] = y2;
		}
		else
		{
			size[i] = x2 - x1;
			e[e_tot++] = (Line){i, x1, y1, 0, 0};
			e[e_tot++] = (Line){i, x2, y1, 0, 2};
			ypos[y_tot++] = y1;
		}
	}
	sort(ypos, ypos + y_tot);
	bit_n = y_tot = unique(ypos, ypos + y_tot) - ypos;
	for(int i = 0; i < e_tot; ++i)
	{
		e[i].y1 = lower_bound(ypos, ypos + y_tot, e[i].y1) - ypos + 1;
		if(e[i].type == 1)
			e[i].y2 = lower_bound(ypos, ypos + y_tot, e[i].y2) - ypos + 1;
	}
	sort(e, e + e_tot);
	Sta.insert(-INF), Sta.insert(INF);//����϶� 
	End.insert(-INF), End.insert(INF);//����¶� 
	y_set.insert(-INF), y_set.insert(INF);//��ǰ������ĵ� 
	for(int i = 0; i < e_tot; ++i)
		if(!e[i].type)//������ 
		{
			int &y1 = e[i].y1;
			y_set.insert(y1);//��ӽڵ� 
			pos[y1] = e[i].id;//��ӹ��� 
			add(y1, 1);
			int yy = *(--Sta.upper_bound(*End.lower_bound(y1)));//��Sta��С��End��>=y1�ĵ�y2�ĵ�yy��������y1�Ŀ�[yy,y2]�����yy 
			Sta.insert(y1);//����һ����, [y1, y1] 
			End.insert(y1);
			if(yy <= y1)//���ڰ������Ŀ飬��Ҫ���ѳ�����[yy, y3], [y4, y2] 
			{
				Sta.insert(*y_set.upper_bound(y1));//�㼯��>y1�ĵ�y4 (y4<=y2) 
				End.insert(*(--y_set.lower_bound(y1)));//�㼯��<y1�ĵ�y3 (y3>=yy) 
			}
		}
		else if(e[i].type == 1)//ͳ�ơ��ϲ� 
		{
			int &y1 = e[i].y1, &y2 = e[i].y2;
			if(y_set.lower_bound(y1) == y_set.upper_bound(y2))//�������߶�, ���ô���, ����������һ���� 
				continue;
			set<int>::iterator lpos = End.lower_bound(y1), rpos = End.lower_bound(y2);//�漰�Ŀ��������յ� [..., lpos], ..., [..., rpos] 
			if(y2 < *(--Sta.upper_bound(*rpos)))//���rpos���ڿ鲻���߶νӴ���ɾ�� 
				--rpos;
			int cnt = 1, u = find(pos[*rpos]), v, tmp, stop = *rpos;//�����һ�����Ǹ��� 
			vis[u] = i + 1;//����ʱ��� 
			for(set<int>::iterator it = lpos; *it != stop; it = End.upper_bound(tmp))//����ɾ�������Ѿ�ɾ����it, ������ȫ��ʧЧ 
			{
				tmp = *it;//�������� 
				v = find(pos[tmp]);//���ÿ�ĸ� 
				if(vis[v] != i + 1)//�Ƿ��Ѿ����� 
				{
					vis[v] = i + 1;
					++cnt;//�¿� 
				}
				merge(u, v);//�ϲ�u,v���ڿ� 
				End.erase(tmp);//�ϲ��ÿ����һ���� 
				Sta.erase(Sta.upper_bound(tmp));//�ϲ�[l1, r1], [l2, r2]ͨ��ɾ��r1��l2 
			}
			merge(u, e[i].id, cnt - sum(y2) + sum(y1 - 1));//�ϲ����ߣ����Ӵ� 
		}
		else//ɾ���ڵ� 
		{
			int &y1 = e[i].y1;
			y_set.erase(y1);//���� 
			pos[y1] = 0;//�������� 
			add(y1, -1);//ȡ������ 
			int lpos = *(--Sta.upper_bound(y1)), rpos = *End.lower_bound(y1);//�ҵ���Ӧ�Ŀ�[lpos, rpos] 
			if(lpos != y1 && rpos != y1)//�ڿ��ڣ������޸Ŀ� 
				continue;
			if(lpos != y1)//���¶˵� 
				End.insert(*(--y_set.lower_bound(y1)));
			if(rpos != y1)//���϶˵� 
				Sta.insert(*y_set.upper_bound(y1));
			if(lpos == y1)//ɾ�϶˵� 
				Sta.erase(y1);
			if(rpos == y1)//ɾ�¶˵� 
				End.erase(y1);
		}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		if(i == find(i) && ans < size[i])
			ans = size[i];
	printf("%I64d\n", ans);
	return 0;
}
