#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	long long a,b,c,sum;
	while(cin>>a>>b)
	{
		if(a==0&&b==0)
			break;
		c=0,sum=0;
		for(int i=0; i<=9; i++)
		{
			if((a%10+b%10+c)>=10)
			{
				sum++;
				c=1;
			}
			else
				c=0;
			a /= 10,b /= 10;
		}
		if(sum==0)
			cout << "No carry operation.\n";
		else if(sum==1)
			cout << sum << " carry operation." << endl;
		else
			cout << sum << " carry operations." << endl;
	}
}