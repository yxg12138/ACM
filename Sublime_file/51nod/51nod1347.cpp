// 1347 旋转字符串
// 基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
// S[0...n-1]是一个长度为n的字符串，定义旋转函数Left(S)=S[1…n-1]+S[0].比如S=”abcd”,Left(S)=”bcda”.一个串是对串当且仅当这个串长度为偶数，前半段和后半段一样。比如”abcabc”是对串,”aabbcc”则不是。
// 现在问题是给定一个字符串，判断他是否可以由一个对串旋转任意次得到。

// Input
// 第1行：给出一个字符串（字符串非空串，只包含小写字母，长度不超过1000000）
// Output
// 对于每个测试用例，输出结果占一行，如果能，输出YES，否则输出NO

#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	int len = s.size();
	if(len%2!=0)
	{
		cout << "NO" << endl;
		return 0;
	}
	int mid = len/2;
	int flag = 1;
	for(int i=0;i < mid;i++)
	{
		if(s[i]!=s[i+mid])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}