#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;

char dir[8];
int dist[8];
int xo,yo,n;
char chess;

int dis(int x,int y){
	return max(abs(x-xo),abs(y-yo));
}

int pre(int x,int y){
	int sx = abs(x-xo),sy = abs(y-yo);
	if(y==yo && x>xo) return 0;
	else if(x==xo && y>yo) return 1;
	else if(y==yo && x<xo) return 2;
	else if(x==xo && y<yo) return 3;
	else if(sx==sy && x>xo && y>yo) return 4;
	else if(sx==sy && x>xo&& y<yo) return 5;
	else if(sx==sy && x<xo && y>yo) return 6;
	else if(sx==sy && x<xo && y<yo) return 7;

	return -1;
}

int main(){
	for(int i=0; i<8; i++){
		dist[i] = INF;
		dir[i] = '?';
	}

	cin >> n >> xo >> yo;
	int x,y;
	while(n--){
		cin >> chess >> x >> y;
		int i = pre(x,y);
		if(i >= 0){
			int len = dis(x,y);
			if(dir[i]=='?' || dist[i]>len){
				dist[i] = len;
				dir[i] = chess;
			}
		}
	}

	int flag = 0;
	for(int i=0; i<4; i++){
		if(dir[i]=='Q' || dir[i]=='R') flag = 1;
	}
	for(int i=4; i<8; i++){
		if(dir[i]=='Q' || dir[i]=='B') flag = 1;
	}

	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
}