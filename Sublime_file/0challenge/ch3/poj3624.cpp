#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 5e4+10;

int H[maxn];
vector<pair<int,int> > bucket;

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);

    const int bucket_size = sqrt(N*1.0);
    bucket.resize(bucket_size+1);

    for(int i=0; i<bucket_size+1; i++){
        bucket[i].first = INF;
        bucket[i].second = -INF;
    }

    for(int i=0; i<N; i++){
        scanf("%d",&H[i]);
        bucket[i/bucket_size].first = min(bucket[i/bucket_size].first,H[i]);
        bucket[i/bucket_size].second = max(bucket[i/bucket_size].second,H[i]);
    }

    for(int i=0; i<Q; i++){
        int A,B;
        scanf("%d%d",&A,&B);

        int min_height = INF;
        int max_height = -INF;
        int le = A-1,ri=B;

        while(le<ri && le%bucket_size!=0){
            int h = H[le++];
            min_height = min(min_height,h);
            max_height = max(max_height,h);
        }

        while(le<ri && ri%bucket_size!=0){
            int h = H[--ri];
            min_height = min(min_height,h);
            max_height = max(max_height,h);
        }

        while(le < ri){
            int b = le/bucket_size;
            min_height = min(min_height,bucket[b].first);
            max_height = max(max_height,bucket[b].second);
            le += bucket_size;
        }

        printf("%d\n",max_height-min_height);

    }

    return 0;
}
