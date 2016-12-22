#include <cstdio>
#include <cstring>
#include <algorithm>
#define fi first
#define se second
#define t_mid (l + r >> 1)
#define ls (o << 1)
#define rs (o << 1 | 1)
#define lson ls, l, t_mid
#define rson rs, t_mid+1, r
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
const int N = 200000 + 5;
const int M = 100000 + 5;
const int INF = 0x3f3f3f3f;

inline int clz(int x){return __builtin_clz(x);}
inline int clz(LL x){return __builtin_clzll(x);}
inline int lg2(int x){return !x ? -1 : 31-clz(x);}
inline int lg2(LL x){return !x ? -1 : 63-clz(x);}

LL atk[N], sum_atk[N];
int pos[M];
int n, m, q, ans;
int st1[N][20], st2[N][20];
int L[N], R[N];
PII c[N << 2]; 
PII build(int o, int l, int r){
	if(l == r) return c[o] = PII(L[l] - l + 1, L[l]);
	return c[o] = max(build(lson), build(rson));
}
void query(int o, int l, int r, int ql, int qr){
	if(qr - l + 1 <= ans) return ;//+1
	if(ql <= l && r <= qr){
		if(c[o].fi <= ans) return ;
		if(c[o].se<=qr) ans = max(ans, c[o].fi);
		if(l == r){
			if(c[o].se >= qr) return ;
			ans = c[o].fi;
			return ;
		}
	}
	if(ql<=t_mid) query (lson,ql,qr);
	if(qr>t_mid) query (rson,ql,qr);
}
int rmq1(int l, int r) {
	int f = lg2(r-l+1);
	return max(st1[l][f], st1[r-(1<<f)+1][f]);
}
int rmq2(int l, int r) {
	int f = lg2(r-l+1);
	return min(st2[l][f], st2[r-(1<<f)+1][f]);
}
void work(int ql, int qr){
	int tmp;
	tmp = rmq1(1, ql);
	//printf("max_r = %d\n", tmp);
	if(tmp >= qr){
		ans = qr - ql + 1; //+1
		return ;
	}else if(tmp < ql){
		;
	}else {
		ans = max(ans, tmp - ql + 1); //+1
	}
	tmp = rmq2(qr, n);
	//printf("min_l = %d\n", tmp);
	if(tmp <= ql){
		ans = qr - ql + 1; // +1 
		return ;
	}else if(tmp > qr){
		;
	}else{
		ans = max(ans, qr - tmp + 1); //+1 
	}
	query(1, 1, n, ql, qr);
}
int main(){
	freopen("a.in", "r", stdin);
	freopen("w.out", "w", stdout);
	int T, ql, qr;
	scanf("%d", &T);
	while(T --){
		//printf ("CASE=%d\n", T);
		scanf("%d%d%d", &n, &m, &q);
		for(int i = 1; i <= n; i ++){
			scanf("%lld", &atk[i]);
			sum_atk[i] = sum_atk[i-1] + atk[i];
		}
		
		memset(L, -1, sizeof(L));
		memset(R, INF, sizeof(R)); 
		
		for(int i = 0; i < m; i ++) scanf("%d", &pos[i]);
		for(int i = 0, ap; i < m; i ++){
			scanf("%d", &ap);
			if(ap < atk[pos[i]]) continue;
			L[pos[i]] = max(L[pos[i]], (int)(upper_bound(sum_atk+pos[i], sum_atk+n+1, ap+sum_atk[pos[i]-1]) - sum_atk - 1));
			R[L[pos[i]]] = min(R[L[pos[i]]], pos[i]);
			R[pos[i]] = min(R[pos[i]], (int)(lower_bound(sum_atk, sum_atk+pos[i]+1, sum_atk[pos[i]] - ap) - sum_atk + 1));
			L[R[pos[i]]] = max(L[R[pos[i]]], pos[i]);
		}
		//printf("L = \n"); for(int i = 1; i <= n; i ++) printf("%d ", L[i]); printf("\n");
		//printf("R = \n"); for(int i = 1; i <= n; i ++) printf("%d ", R[i]); printf("\n");
		//st1
		for(int i = 1; i <= n; i ++) st1[i][0] = L[i];		
		for(int j = 1; 1<<j <= n; j ++)
			for(int i = 1; i+(1<<j)-1 <= n; i ++)
				st1[i][j] = max(st1[i][j-1], st1[i+(1<<j-1)][j-1]);
		//st2	
		for(int i = 1; i <= n; i ++) st2[i][0] = R[i];
		for(int j = 1; 1<<j <= n; j ++)
			for(int i = 1; i+(1<<j)-1 <= n; i ++)
				st2[i][j] = min(st2[i][j-1], st2[i+(1<<j-1)][j-1]);
				
		build(1, 1, n);
		
		int tmp = 0;
		while(q --){
			ans = 0;
			scanf("%d%d", &ql, &qr);
			ql ^= tmp, qr ^= tmp; 
			//if (ql>qr) puts ("error");
			if (ql>qr) swap(ql, qr);
			work(ql, qr);
			tmp=ans;
			printf("%d\n", tmp=ans);
		}
	}
	showtime;
}
