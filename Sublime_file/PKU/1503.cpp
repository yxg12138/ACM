#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
//高精度加法
string add(string str1,string str2)
{
	string str;
	int len1 = str1.length(),len2 = str2.length();
	if(len1<len2)
	{
		for(int i=1; i<=len2-len1; i++)
			str1 = "0" + str1;
	}
	else
	{
		for(int i=1; i<=len1-len2; i++)
			str2 = "0" + str2;
	}
	len1 = str1.length();
	int cf = 0;
	int temp;
	for(int i=len1-1; i>=0; i--)
	{
		temp = str1[i]-'0'+str2[i]-'0'+cf;
		cf = temp/10;
		temp %= 10;
		str = char(temp+'0')+str;
	}
	if(cf!=0) str = char(cf+'0')+str;
	return str;
}

int main()
{
	string sum="0",str1;
	while(cin>>str1)
	{
		if(str1 == "0")
			break;
		sum = add(sum,str1);
	}
	cout << sum << endl;

	return 0;
}