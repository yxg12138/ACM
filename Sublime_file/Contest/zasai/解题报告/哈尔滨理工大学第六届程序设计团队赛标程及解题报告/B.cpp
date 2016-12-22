#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
bool isleap(int y){
	if ((y%4==0 && y%100!=0) || y%400==0)	return true;
	return false;
}
int maxday(int y,int m){
	if (m==2){
		if (isleap(y))	return 29;
		else return 28;
	}else{
		if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)	return 31;
		else return 30;
	}

}
int main (int argc, char *argv[])
{
	int noc;int y,m,d;int s;
	scanf("%d",&noc);
	while (noc--){
		scanf("%d-%d-%d%d",&y,&m,&d,&s);
		int ad=s/86400.0;
		FOR(_,1,ad){
			d++;
			if (d>maxday(y,m)){
				d=1;
				m++;
			}
			if (m==13){
				m=1;
				y++;
			}
		}
		printf("%d-%.2d-%.2d\n",y,m,d);
	}
	return 0;
}
