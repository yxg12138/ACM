#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<ctime>
#include<cassert>
using namespace std;
typedef long long ll;


void fill_random_int(vector<int>& v, int cnt)
{
	v.clear();
	for (int i = 0; i < cnt; i++)
		v.push_back(rand());
}

void test_sort(vector<int>& v)
{
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
	{
		printf("%d\n",v[i]);
		assert(v[i] <= v[i + 1]);
	}
}


int main()
{
	srand(time(NULL));
	vector<int> v;
	fill_random_int(v, 10);
	test_sort(v);
	
}