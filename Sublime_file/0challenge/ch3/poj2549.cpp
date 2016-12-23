#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1<<30;
const int maxn = 1000+10;

int a[maxn];

int main(){
	int n;
	while(cin>>n && n){
		for(int i=0; i<n; i++) cin >> a[i];

		sort(a,a+n);
		n--;

		int ans = INF;

		for(int i=n; i>=0; i--){
			for(int j=n; j>=0; j--){
				if(i==j) continue;

				int sum = a[i]-a[j];

				int le = 0, ri = j-1;
				while(le<ri){
					if(a[le]+a[ri] == sum){
						ans = a[i];
						break;
					}

					if(a[le]+a[ri] > sum)
						ri--;
					else
						le++;
				}
				
				if(ans != INF) break;
			}
			if(ans != INF) break;
		}

		if(ans == INF) printf("no solution\n");
		else printf("%d\n",ans);
	}

}