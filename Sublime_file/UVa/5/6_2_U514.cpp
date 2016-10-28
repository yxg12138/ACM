#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1000+10;

int n,target[maxn];

int main()
{
	while(scanf("%d",&n) == 1 && n)
	{
		while(scanf("%d",&target[1]),target[1])
		{
			stack<int> s;
			while(!s.empty()) s.pop();
			int a=1,b=1,f=0;
			for(int i=2; i<=n; i++)
			{
				scanf("%d",&target[i]);
			}
			if(f) break;
			int ok = 1;
			while(b<=n)
			{
				if(a==target[b]) 
				{
					a++,b++;
				}
				else if(!s.empty()&&s.top()==target[b])
				{
					b++;
					s.pop();
				}
				else if(a<=n)
				{
					s.push(a);
				}
				else
				{
					ok=0;
					break;
				}
			}
			printf("%s\n",ok?"Yes":"No");
		}
	}
}