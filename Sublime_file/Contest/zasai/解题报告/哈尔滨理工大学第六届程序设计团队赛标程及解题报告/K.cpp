#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int cnta,cntb,cntc;
int ax,ay,bx,by,cx,cy;
char a[10][10];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,-1,-1,-1,0,1,1,1};
int vis[10][10];
bool lined[20][20][20][20];
int n,m;
vector<string> solution;
inline bool check(){
	FOR(i,1,n)FOR(j,1,m)if (vis[i][j]!=0) return false;
	return true;
}
inline void line(int x,int y,int tx,int ty,char c){
//	solution.push_back(to_string(x)+" "+to_string(y)+"  "+to_string(tx)+" "+to_string(ty));
	vis[tx][ty]--;
	lined[x][y][tx][ty]=lined[tx][ty][x][y]=true;
}
inline void unline(int x,int y,int tx,int ty,char c){
//	solution.pop_back();
	vis[tx][ty]++;
	lined[x][y][tx][ty]=lined[tx][ty][x][y]=false;
}
inline bool ok(int x,int y,int tx,int ty){
	if (vis[tx][ty]==0)	return false;
	if (lined[x][y][tx][ty])	return false;
	FOR(i,0,7){
		if (tx==x+dx[i] && ty==y+dy[i] && lined[x+dx[(i-1+8)%8]][y+dy[(i-1+8)%8]][x+dx[(i+1)%8]][y+dy[(i+1)%8]])
			return false;
	}
	return true;
}
bool gao(int x,int y,char c,int cnt){
	if (cnt<1)	return check();
	FOR(i,0,7){
		if (a[x+dx[i]][y+dy[i]]==c){
			if (ok(x,y,x+dx[i],y+dy[i])){
				line(x,y,x+dx[i],y+dy[i],c);
				if (gao(x+dx[i],y+dy[i],c,cnt-1)==false){
					unline(x,y,x+dx[i],y+dy[i],c);
				}else return true;
			}
		}else if (a[x+dx[i]][y+dy[i]]<='9' && a[x+dx[i]][y+dy[i]]>='2') {
			if (ok(x,y,x+dx[i],y+dy[i])){
				line(x,y,x+dx[i],y+dy[i],c);
				if (gao(x+dx[i],y+dy[i],c,cnt)==false){
					unline(x,y,x+dx[i],y+dy[i],c);
				}else return true;
			}
		}else if (a[x+dx[i]][y+dy[i]]==c-'a'+'A' && cnt==1){
			if (ok(x,y,x+dx[i],y+dy[i])){
				line(x,y,x+dx[i],y+dy[i],c);
				if (c=='a'){
					if (gao(bx,by,'b',cntb-1))	return true;
					else{unline(x,y,x+dx[i],y+dy[i],c);}
				}else if (c=='b'){
					if (gao(cx,cy,'c',cntc-1))	return true;
					else{unline(x,y,x+dx[i],y+dy[i],c);}
				}else if (c=='c'){
					if (check()==true)	return true;
					else {unline(x,y,x+dx[i],y+dy[i],c);}
				}
			}
		}
	}
	return false;
}
int main (int argc,char *argv[])
{
	std::ios::sync_with_stdio(false);
	int noc;cin>>noc;
	FOR(cs,1,noc){
		solution.clear();
		cin>>n>>m;
		cnta=cntb=cntc=0;
		ax=ay=bx=by=cx=cy=0;
		memset(vis,0,sizeof vis);
		memset(lined,false,sizeof lined);
		FOR(i,0,n+1)	FOR(j,0,m+1)	a[i][j]='x';
		FOR(i,1,n){
			FOR(j,1,m){
				string cmd;cin>>cmd;
				a[i][j]=cmd[0];
				if (a[i][j]=='A')	ax=i,ay=j;
				if (a[i][j]=='B')	bx=i,by=j;
				if (a[i][j]=='C')	cx=i,cy=j;
				if (a[i][j]=='a' || a[i][j]=='A')	cnta++;
				if (a[i][j]=='b' || a[i][j]=='B')	cntb++;
				if (a[i][j]=='c' || a[i][j]=='C')	cntc++;
				if (a[i][j]<='9' && a[i][j]>='2')	vis[i][j]=a[i][j]-'0';
				else if (a[i][j]!='x')	vis[i][j]=1;
			}
		}
		vis[ax][ay]=vis[bx][by]=vis[cx][cy]=0;
		if (gao(ax,ay,'a',cnta-1))	cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	//	for(auto it=solution.begin();it!=solution.end();++it)	cout<<*it<<endl;
	}
	return 0;
}
