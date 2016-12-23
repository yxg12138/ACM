// #include <cstdio>
// #include <cstring>
// const int maxn = 20;

// const int dx[5] = {-1,0,0,1,0};
// const int dy[5] = {0,-1,0,0,1};

// int M,N;
// int tile[maxn][maxn];

// int opt[maxn][maxn];
// int flip[maxn][maxn];


// int get(int x,int y){
// 	int c = tile[x][y];
// 	for(int d=0; d<5; d++){
// 		int x2 = x+dx[d],y2 = y+dy[d];
// 		if(x2>=0 && x2<M && y2>=0 && y2<N)
// 			c += flip[x2][y2];
// 	}

// 	return c%2;
// }


// int calc(){
// 	for(int i=1; i<M; i++){
// 		for(int j=0; j<N; j++){
// 			if(get(i-1,j) != 0)
// 				flip[i][j] = 1;
// 		}
// 	}

// 	for(int j=0; j<N; j++){
// 		if(get(M-1,j) != 0)
// 			return -1;
// 	}

// 	int res = 0;
// 	for(int i=0; i<M; i++){
// 		for(int j=0; j<N; j++){
// 			res += flip[i][j];
// 		}
// 	}
// 	return res;
// }

// void solve(){
// 	int res = -1;
// 	for(int i=0; i<1<<N; i++){
// 		memset(flip,0,sizeof(flip));
// 		for(int j=0; j<N; j++)
// 			flip[0][N-j+1] = i>>j & 1;
// 		int num = calc();
// 		if(num >= 0 && (res<0 || res>num)) {
// 			res = num;
// 			memcpy(opt,flip,sizeof(flip));
// 		}
// 	}

// 	if(res < 0){
// 		printf("IMPOSSIBLE\n");
// 	}else{
// 		for(int i=0; i<M; i++){
// 			for(int j=0; j<N; j++){
// 				printf("%d%c",opt[i][j],j+1==N ? '\n' : ' ');
// 			}
// 		}
// 	}

// }


// int main(){
// 	scanf("%d%d",&M,&N);
// 	for(int i=0; i<M; i++){
// 		for(int j=0; j<N; j++){
// 			scanf("%d",&tile[i][j]);
// 		}
// 	}
// 	solve();
// }

#include <cstdio>
#include <cstring>

const int maxn = 5000+10;
int M,N;
int tile[maxn][maxn];

int flip[maxn][maxn];
int opt[maxn][maxn];

const int dx[4] = {0,-1,0,0};
const int dy[4] = {1,0,0,-1};
int get(int x,int y){
	int c = tile[x][y];
	for(int d=0; d<4; d++){
		int x2 = x+dx[d], y2 = y+dy[d];
		c += flip[x2][y2];
	}
	return c%2;
}


int calc(){
	for(int i=1; i<M; i++){
		for(int j=0; j<N; j++){
			if(get(i-1,j) != 0)
				flip[i][j] = 1;
		}
	}

	for(int j=0; j<N; j++)
		if(get(M-1,j) != 0)
			return -1;

	int res = 0;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++)
			res += flip[i][j];
	}
	return res;
}

void solve(){
	int res = -1;
	for(int i=0; i<1<<N; i++){
		memset(flip,0,sizeof(flip));
		for(int j=0; j<N; j++)
			flip[0][N-j+1] = i>>j & 1;
		int num = calc(); 
		if(num >= 0 && (res<0 || res>num))
		{
			res = num;
			memcpy(opt,flip,sizeof(flip));
		}
	}

	if(res < 0){
		printf("IMPOSSIBLE\n");
	}else{
		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++)
				printf("%d%c", opt[i][j],j+1==M ? '\n' : ' ');
		}
	}
}

int main(){
	scanf("%d%d",&M,&N);
	for(int i=0; i<M;i++){
		for(int j=0; j<N; j++){
			scanf("%d",&tile[i][j]);
		}
	}
	solve();

}