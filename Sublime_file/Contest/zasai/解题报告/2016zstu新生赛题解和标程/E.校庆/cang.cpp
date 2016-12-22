#include <stdio.h>
#include <stdlib.h>
int Day[2][13] = {
	{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365}, //平年前缀和 
	{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}, //闰年前缀和 
};

int judge(int y){ //判断闰年 
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}
int delta(int y, int m, int d){ //从公元1年1月1日至今几天
	return ((y-1)*365 + (y-1)/4 - (y-1)/100 + (y-1)/400) + Day[judge(y)][m-1] + d-1;
}

int main(){
	freopen("read.txt", "r", stdin);
	freopen("w.txt", "w", stdout); 
	int y, m, d;
	int T;
	scanf("%d", &T);
	while(T --){
		scanf("%d%d%d", &y, &m, &d);
		//printf("test = %d\n", delta(y, m, d));
		printf("%d\n", delta(2017, 10, 28) - delta(y, m, d));
	}
}