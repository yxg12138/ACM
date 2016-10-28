#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 120000+10;
string s[maxn];

map<string,int> mp;


int main()
{

	int cnt = 0;
	while(cin>>s[cnt])
	{
		mp[s[cnt]] = 1;
		cnt++;
	}
	for(int i=0; i<cnt; i++)
	{
		for(int j=0; j<s[i].size(); j++)
		{
			string t1,t2;
			t1 = s[i].substr(0,j);
			t2 = s[i].substr(j);
			if(mp[t1]&&mp[t2])
			{
				cout << s[i] << endl;
				break;
			}
		}
	}
}