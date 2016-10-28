//2.2.3
#include <cstdio>
using namespace std;

const int maxn = 2000+10;
int N;
char S[maxn];


void solve(){
	int a = 0,b = N-1,cnt = 0;

	while(a<=b){
		bool left = false;
		for(int i=0; a+i<=b; i++){
			if(S[a+i] < S[b-i]){
				left = true;
				cnt++;
				break;
			}
			else if(S[a+i] > S[b-i]){
				left = false;
				cnt++;
				break;
			}
		}

		if(left) putchar(S[a++]);
		else putchar(S[b--]);
		if(cnt % 80 == 0)  
        puts("");
	}
	puts("");

}

int main(){
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		getchar();
		scanf("%c",&S[i]);
	}
	solve();
	
}
