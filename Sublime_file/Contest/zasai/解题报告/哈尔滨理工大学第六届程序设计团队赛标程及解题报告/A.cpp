#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int main (int argc, char *argv[])
{
	int noc;cin>>noc;
	while (noc--){
		int n;cin>>n;
		int cnt=0;
		FOR(i,1,n){
			int temp;cin>>temp;
			if (temp==1)	cnt++;
		}
		printf("%.2f\n",(double)cnt/n);
	}
	return 0;
}
