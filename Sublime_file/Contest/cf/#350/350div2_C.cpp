#include <cstdio>
#include <map>
using namespace std;
const int maxn = 200000+10;
map<int,int> s;
int lan[maxn];
int sub[maxn];


int main()
{
	int n,m,x;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&x);
		s[x]++;
	}
	scanf("%d",&m);
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&lan[i]);
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&sub[i]);
	}
	int kk = -1,gg = -1,flag = -1;
	for(int i=1; i<=m; i++)
	{
		if(kk < s[lan[i]] || (kk==s[lan[i]]&&gg<s[sub[i]]))
		{
			kk = s[lan[i]];
			gg = s[sub[i]];
			flag = i;
		}
	}
	printf("%d\n",flag);

}