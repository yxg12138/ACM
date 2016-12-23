	#include <cstdio>
	#include <cstring>
	#include <algorithm>
	using namespace std;

	const int maxn = 1e5+10;

	int n,q;
	int num[maxn],sum[maxn],node[maxn<<2];

	void pushup(int rt){
		node[rt] = max(node[rt<<1],node[rt<<1|1]);
	}

	void build(int rt,int l,int r){
		if(l == r){
			node[rt] = num[l];
			return;
		}

		int m = (l+r)>>1;
		build(rt<<1,l,m);
		build(rt<<1|1,m+1,r);
		pushup(rt);
	}

	int find_num(int key,int l,int r){
		int m;
		while(l<=r){
			m = (l+r)/2;
			if(sum[m] > key){
				r = m-1;
			}else if(sum[m] < key){
				l = m+1;
			}else break;
		}

		if(sum[m-1] >= key){
			return m-1;
		}else if(sum[m] >= key){
			return m;
		}else{
			return m+1;
		}
	}

	int query(int a,int b,int rt,int l,int r){
		if(a<=l && r<=b){
			return node[rt];
		}

		int m = (l+r)/2;
		int ans = 0;
		if(a<=m) ans = query(a,b,rt<<1,l,m);
		if(m<b) ans = max(ans,query(a,b,rt<<1|1,m+1,r));
		return ans;
	}


	int main(){
		while(scanf("%d",&n), n){
			memset(num,0,sizeof(num));
			memset(node,0,sizeof(node));
			memset(sum,0,sizeof(num));
			scanf("%d",&q);
			int tag,chack,cnt=1,a,b;
			scanf("%d",&chack);
			num[cnt] = 1;
			sum[0] = 0;
			for(int i=1; i<n; i++){
				scanf("%d",&tag);
				if(chack == tag){
					num[cnt]++;
				}else{
					sum[cnt] = sum[cnt-1]+num[cnt];

					chack = tag;	
					cnt++;
					num[cnt] = 1;
				}
			}

			sum[cnt] = sum[cnt-1] + num[cnt];
			build(1,1,cnt);

			for(int i=0; i<q; i++){
				scanf("%d%d",&a,&b);
				int x = find_num(a,1,cnt);
				int y = find_num(b,1,cnt);
				int ans = sum[x] - a + 1;
				if(x == y){
					printf("%d\n", b-a+1);
					continue;
				}

				if(x+1<=y-1){
					ans = max(ans,query(x+1,y-1,1,1,cnt));
				}

				ans = max(ans,num[y]-sum[y]+b);
				printf("%d\n",ans);
			}
		}

	}