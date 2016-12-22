#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
typedef long long LL;
const LL mod = 1000000000+7;
LL f[2000000+233];
int main (int argc, char *argv[])
{
	std::ios::sync_with_stdio(false);
	f[0]=f[1]=1;
	FOR(i,2,2000000){
		f[i]=i*f[i-1]+(i-1)*f[i-2];
		f[i]%=mod;
	}
	int noc;cin>>noc;
	while (noc--){
		int n;cin>>n;cout<<f[n-1]<<endl;
	}
	return 0;
}
