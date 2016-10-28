#include<stdio.h>  
#include<iostream>  
#include<map>  
#include<string.h>  
#include<string>  
using namespace std;

string s;
int k, cnt;
map<int, int>done;

struct tree
{
	string s;
	int ls, rs;
	bool operator < (const tree& rhs) const//Ҫ��mapһ��Ҫ�����������  
	{
		if (s != rhs.s) return s < rhs.s;
		else if (ls != rhs.ls) return ls < rhs.ls;
		else return rs < rhs.rs;
	}
};

map<tree, int>MAP;//����ID  
map<int, tree>NODE;//����ڵ���Ϣ  

int solve()//ֻɨ��һ�飬�ð���  
{
	string cur;
	while (s[k] >= 'a'&&s[k] <= 'z') cur.push_back(s[k++]);
	int id = ++cnt;//��cnt�йصĴ��붼�þ��ʣ�ǰ������Ҳ�뵽�ˣ���д�ĺ��á�  
	//�������ȸ���Ԥ��һ����ŵ���˼��  
	tree& t = NODE[id];//���ã�����  
	t.s = cur;
	t.ls = 0;
	t.rs = 0;
	if (s[k] == '(')
	{
		//д�ü��׶�����������ĸ���ַ���  
		k++;
		t.ls = solve(); k++;
		t.rs = solve(); k++;
	}
	if (MAP[t]) { cnt--; return MAP[t]; }//���MAP[t]��=0����ôcnt��Ϊid+1��cnt--����ȡ��Ԥ���ı�š�  
	else return MAP[t] = id;
}
//ԭ�������������������������ǰ����Ĵ�������һ��dfs�������������ġ�  
//��ʡ�Ĳ�ʡ��������ʡ����ʡ����ֻ��˵�Լ���ʱ�临�ӶȲ������аɡ�  
void print(int u)
{
	if (done[u]) printf("%d", u);
	else
	{
		done[u] = 1;
		cout << NODE[u].s;
		if (NODE[u].ls)
		{
			cout << "(";
			print(NODE[u].ls);
			cout << ",";
			print(NODE[u].rs);
			cout << ")";
		}
	}
}

int main()
{
// 	freopen("in", "r", stdin);
	int q;
	cin >> q;
	while (q--)
	{
		MAP.clear();
		done.clear();
		NODE.clear();
		cnt = k = 0;
		cin >> s;
		print(solve());//solve���ظ���ţ�print�Ӹ���ſ�ʼ�ݹ������  
		puts("");
	}
	return 0;
}