#include <cstdio>
#include <cstring>

const int maxn = 5000+10;

int n;
int dir[maxn];
int f[maxn];
char s[maxn];


int calc(int k){
	memset(f,0,sizeof(f));
	int res = 0, sum = 0;
	for(int i=0; i+k<=n; i++){
		if((dir[i]+sum)%2 != 0){
			res++;
			f[i] = 1;
		}
		sum += f[i];
		if(i-k+1 >= 0)
			sum -= f[i-k+1];
	}

	for(int i=n-k+1; i<n; i++){
		if((dir[i]+sum)%2 != 0){
			return -1;
		}
		if(i-k+1>=0)
			sum -= f[i-k+1];
	}
	return res;
}



void solve(){
	int K = 1,M = n;
	for(int k=1; k<=n; k++){
		int m = calc(k);
		if(m >=0 && M > m){
			K = k;
			M = m;
		}
	}
	printf("%d %d\n",K,M);
}


int main(){

	scanf("%d%s",&n,s);
	for(int i=0; i<strlen(s); i++){
		if(s[i] == 'B')
			dir[i] = 1;
		else
			dir[i] = 0;
	}
	solve();
}
