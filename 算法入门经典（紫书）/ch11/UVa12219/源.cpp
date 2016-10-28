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
	bool operator < (const tree& rhs) const//要用map一定要重载运算符。  
	{
		if (s != rhs.s) return s < rhs.s;
		else if (ls != rhs.ls) return ls < rhs.ls;
		else return rs < rhs.rs;
	}
};

map<tree, int>MAP;//保存ID  
map<int, tree>NODE;//保存节点信息  

int solve()//只扫描一遍，好棒。  
{
	string cur;
	while (s[k] >= 'a'&&s[k] <= 'z') cur.push_back(s[k++]);
	int id = ++cnt;//跟cnt有关的代码都好精彩，前两遍我也想到了，但写的好烂。  
	//这里是先给你预留一个编号的意思。  
	tree& t = NODE[id];//引用，好灵活。  
	t.s = cur;
	t.ls = 0;
	t.rs = 0;
	if (s[k] == '(')
	{
		//写得简单易懂，跳过非字母的字符。  
		k++;
		t.ls = solve(); k++;
		t.rs = solve(); k++;
	}
	if (MAP[t]) { cnt--; return MAP[t]; }//如果MAP[t]！=0，那么cnt必为id+1，cnt--即可取消预留的编号。  
	else return MAP[t] = id;
}
//原来还可以这样输出。。。不过前两遍的代码我是一遍dfs解决建树与输出的。  
//该省的不省。。不该省的乱省。。只能说自己对时间复杂度不够敏感吧。  
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
		print(solve());//solve返回根编号，print从根标号开始递归输出。  
		puts("");
	}
	return 0;
}