#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> s;
	int n,x,y;
	cin >> n;
	int ans = n;
	while(n--)
	{
		cin >> x >> y;
		if(y == 1)
			s.push(x);
		else 
		{
			while(!s.empty())
				if(x>s.top()) { s.pop(),ans--;}
				else { ans--;break;}
		}
	}
	cout << ans << endl;

	return 0;
}