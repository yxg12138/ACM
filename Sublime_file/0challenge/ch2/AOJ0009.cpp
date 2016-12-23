#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 2e4+10;

int prime[maxn];
bool is_prime[maxn];

void sieve(){
	int p = 0;
	fill(is_prime,is_prime+maxn,1);
	is_prime[0] = is_prime[1] = false;

	for(int i=2; i<=20000; i++){
		if(is_prime[i]){
			//prime[p++] = i;
			for(int j=2*i; j<=20000; j+=i){
				is_prime[j] = false;
			}
		}
	}

	//return p;
}
void init(){    //对素数打表  
    int i,j;  
    for(i=1000;i<=10000;i++){  
        for(j=2;j<i;j++)  
            if(i%j==0){  
                is_prime[i]=false;  
                break;  
            }  
        if(j==i) is_prime[i]=true;  
    }  
}  

int bfs(int first,int last){
	bool vis[maxn];
	queue<int> Q;
	int v,i,j,tmp,vtmp,cnt[maxn],t[4];
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));

	Q.push(first);
	vis[first] = true;

	while(!Q.empty()){
		v = Q.front(); Q.pop();

		t[0] = v/1000; t[1] = v%1000/100; t[2] = v%100/10; t[3] = v%10;
		//printf("%d %d %d %d",t[0],t[1],t[2],t[3]);
		for(j=0; j<4; j++){
			tmp = t[j];
			for(int i=0; i<10; i++){
				if(i!=tmp){
					t[j] = i;
					vtmp = t[0]*1000+t[1]*100+t[2]*10+t[3];
					if(!vis[vtmp] && is_prime[vtmp] && t[0]!=0){
						cnt[vtmp] = cnt[v] + 1;
						vis[vtmp] = true;
						Q.push(vtmp);
					}
					if(vtmp == last) return cnt[vtmp];
				}
			}
			t[j] = tmp;
		}

		if(v == last) return cnt[v];
	}

	return -1;
}

int main(){
	int n,a,b,ans;
	sieve();
	//init();
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		ans = bfs(a,b);
		if(ans == -1) printf("Impossible\n");
		else printf("%d\n",ans);
	}
}