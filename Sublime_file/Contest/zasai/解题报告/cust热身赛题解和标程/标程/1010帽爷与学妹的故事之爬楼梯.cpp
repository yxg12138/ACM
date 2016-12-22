/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *题意:两个人爬楼梯，一开始设定n为最高层（也就是向上走不会超过第n层）            
 *	   然后中间有个条件，在每一次猜拳，两个人中其中一个如果赢了的话就
 *	   看心情想走几步就几步，而另一个人如果赢了只能一步一步向上走。
 *	   然后从0时刻开始输出每一个时刻他们所在的位置（开始位置在都在0（这个忘说了
 *	   ，抱歉））。
 *题解:这是一个传说中的模拟题，你要做的也就是把这个实际问题的过程模拟出来。
 *	   那么只要处理好每个时刻是哪个人赢了(0-1串上判断),开两个变量统计好每个人
 *	   每个时刻所在的位置就行，然后每一个时刻都把两个人的位置按格式输出，
 *	   答案还有一个坑点，也就是这个游戏没有最终的输赢，也就是会一直猜拳
 *	   猜到最后（串长代表游戏的时长），而且到达第n层如果赢了，也不会向上走，会
 *	   一直停在第n层。
 *
 *	   祝大家AC愉快！
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//程序是C的写法，程序中所涉及的函数请自行百度学习一下
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int N=1005;
int n;
char str[N];
int k[N*10];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int kase=1;
	while(scanf("%d",&n) == 1)//这样也可以判断是否到达文件尾
	{
		scanf("%s",str);
		int s = strlen(str);//strlen()函数读取"字符串"数组的长度
		for(int i = 0; i < s ; i++)
			scanf("%d",k + i);
		int a = 0,b = 0;
		printf("Case #%d:\n",kase++);
		printf("0 0\n");
		for(int i = 0; i < s; i++)
		{
			if(str[i] == '0') a += k[i];
			else b++;
			printf("%d %d\n",min(a,n),min(b,n));//min()函数是取两者的较小值,例如min(3,4)=3
		}
		if(a >= n || b >= n) puts("Yes");//puts()函数是向控制台输出一个字符串
		else puts("No");
		printf("\n");
	}
    return 0;
}
