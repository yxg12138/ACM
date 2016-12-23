#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int max_n = 1e5+10;
const int B = 1000; // 桶的大小

int N,M;
int A[max_n];
int I[max_n],J[max_n],K[max_n];

int nums[max_n];
vector<int> bucket[max_n/B];

void solve(){
	for(int i=0; i<N; i++){
		bucket[i/B].push_back(A[i]);
		nums[i] = A[i];
	}
	sort(nums,nums+N);
	for(int i=0; i<N/B; i++) sort(bucket[i].begin(),bucket[i].end());

	for(int i=0; i<M; i++){
		int l = I[i],r = J[i]+1,k = K[i];

		int lb = -1,ub = N-1;
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			int x = nums[mid];
			int tl = l,tr = r,c=0;
			while(tl<tr && tl%B!=0) if(A[tl++]<=x) c++;
			while(tl<tr && tr%B!=0) if(A[--tr]<=x) c++;
			while(tl<tr){
				int b = tl/B;
				c += upper_bound(bucket[b].begin(),bucket[b].end(),x)-bucket[b].begin();
				tl+=B;
			}
			if(c >= k)  ub = mid;
			else lb = mid;
		}
		printf("%d\n",nums[ub]);

	}

}


int main(){
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; i++){
		scanf("%d",&A[i]);
	}
	for(int i=0; i<M; i++){
		scanf("%d%d%d",&I[i],&J[i],&K[i]);
	}
	solve();
}

// 7 3
// 1 5 2 6 3 7 4
// 2 5 3
// 4 4 1
// 1 7 3
