/*
题解：这道题所需要的巧克力的数量是s=(y/100*n)-x,
需要注意，如果最后求出的s不是整数，需要向上取整
并且如果原本的巧克力数目x已经够了的话，答案为0不为负数
最后，浮点型用推荐用精度高的double类型
*/
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double n,x,y;
	while(cin >> n >> x >> y)
    {
        double s=y/100.0*n;
        s=s-x;
        int c=s;//取出整数部分
        if (s>c)
            c++;
        if (c<=0)
            cout << 0 << endl;
        else
            cout << c << endl;
    }
    return 0;
}
