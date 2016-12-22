#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--){
		int a,b;
		scanf("%o%o",&a,&b);

		if(a >= b)
			printf("%o\n",a-b);
		else
			printf("-%o\n",b-a);
	}

}