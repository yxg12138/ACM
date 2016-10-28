#include <string>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;
struct node
{
	string s;
	int t;
}kk[50];


int main()
{
	kk[0].s = "Cleveland Cavaliers", kk[0].t = 1;
	kk[1].s = "Golden State Warriors", kk[1].t = 2;
	kk[2].s = "San Antonio Spurs", kk[2].t = 5;
	kk[3].s = "Miami Heat", kk[3].t = 3;
	kk[4].s = "Dallas Mavericks", kk[4].t = 1;
	kk[5].s = "L.A. Lakers", kk[5].t = 11;
	kk[6].s = "Boston Celtics", kk[6].t = 17;
	kk[7].s = "Houston Rockets", kk[7].t = 2;
	kk[22].s = "Chicago Bulls", kk[22].t = 6;
	kk[9].s = "Detroit Pistons", kk[9].t = 3;
	kk[10].s = "Philadelphia 76ers", kk[10].t = 2;
	kk[11].s = "Seattle Sonics", kk[11].t = 1;
	kk[12].s = "Washington Bullets", kk[12].t = 1;
	kk[13].s = "Portland Trail Blazers", kk[13].t = 1;
	kk[14].s = "New York Knicks", kk[14].t = 2;
	kk[15].s = "Milwaukee Bucks", kk[15].t = 1;
	kk[16].s = "St. Louis Hawks", kk[16].t = 1;
	kk[17].s = "Philadelphia Warriors", kk[17].t = 2;
	kk[18].s = "Syracuse Nats", kk[18].t = 1;
	kk[19].s = "Minneapolis Lakers", kk[19].t = 5;
	kk[20].s = "Rochester Royals", kk[20].t = 1;
	kk[21].s = "Baltimore Bullets", kk[21].t = 1;


	char str[50];
	int flag = 0;
	int n;
	scanf("%d", &n);

	getchar();
	int cnt = 0;
	while (n--)
	{
		
		gets(str);
		flag = 0;
		for (int i = 0; i < 22; i++)
			if (str == kk[i].s)
			{
				printf("Case #%d: %d\n", ++cnt, kk[i].t);
				flag = 1;
				break;
			}
		if (!flag)
			printf("Case #%d: 0\n", ++cnt);
	}
}