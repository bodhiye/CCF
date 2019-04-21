#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
#define N 5010
int n, m;
int a[N][N], b[N][N];
int read() {
	int A, B, Q, XI;
	scanf("%d%d%d%d%d%d", &n, &m, &A, &B, &Q, &XI);
	//a
	for (int i = 1; i<n; i++)
		for (int j = 1; j <= m; j++) {
			XI = (1ll * A*XI + B) % Q;
			a[i][j] = XI;
		}
	//b
	for (int i = 2; i <= n - 1; i++)
		for (int j = 1; j<m; j++) {
			XI = (1ll * A*XI + B) % Q;
			b[i][j] = XI;
		}
	return 0;
}
int ed;
int ed_x[N], ed_y[N];
int ed_w[N];
int getEdge(int x, int y) { //从(x,y)出发点连边
	ed = 0;
	if (x == 0) {    //起始或终点
		if (y == 0) { //s
			for (int i = 1; i<n; i++) {
				ed++;
				ed_x[ed] = i;
				ed_y[ed] = 1;
				ed_w[ed] = a[i][1];
			}
		}
	}
	else {  //格子节点
			//右
		ed++;
		if (y == m - 1) {//通向汇点t
			ed_x[ed] = 0; ed_y[ed] = 1; ed_w[ed] = a[x][m];
		}
		else {
			ed_x[ed] = x; ed_y[ed] = y + 1; ed_w[ed] = a[x][y + 1];
		}
		//左
		if (y>1) {
			ed++;
			ed_x[ed] = x; ed_y[ed] = y - 1; ed_w[ed] = a[x][y];
		}
		//下
		if (x<n - 1) {
			ed++;
			ed_x[ed] = x + 1; ed_y[ed] = y; ed_w[ed] = b[x + 1][y];
		}
		//上
		if (x>1) {
			ed++;
			ed_x[ed] = x - 1; ed_y[ed] = y; ed_w[ed] = b[x][y];
		}
	}
	return 0;
}
void showEd() {
	for (int i = 1; i <= ed; i++) {
		printf("(%d,%d) %d\n", ed_x[i], ed_y[i], ed_w[i]);
	}
}
bool done[N][N];
long long d[N][N];
struct NODE {
	int x, y;
	long long d;
	NODE(int x = 0, int y = 0, long long d = 0) :x(x), y(y), d(d) {}
	bool operator <(const NODE& rhs)const {
		return d>rhs.d;
	}
};
#define INF (9187201950435737471ll)
priority_queue<NODE> Q;
long long solve() {
	memset(d, 127, sizeof(d));
	d[0][0] = 0;
	memset(done, 0, sizeof(done));
	Q.push(NODE(0, 0, 0));
	while (!Q.empty()) {
		NODE nd = Q.top(); Q.pop();
		if (nd.x == 0 && nd.y == 1) return nd.d;
		if (done[nd.x][nd.y])continue;
		done[nd.x][nd.y] = true;
		d[nd.x][nd.y] = nd.d;
		getEdge(nd.x, nd.y);
		for (int i = 1; i <= ed; i++) {
			int x = ed_x[i];
			int y = ed_y[i];
			int w = ed_w[i];
			//printf("(%d,%d)->(%d,%d) %d\n",nd.x,nd.y,x,y,w);
			if (d[x][y]>d[nd.x][nd.y] + w) {
				d[x][y] = d[nd.x][nd.y] + w;
				Q.push(NODE(x, y, d[x][y]));
			}
		}
	}
	return 0;
}
int main() {
	read();
	/*for (int i=1;i<n;i++,putchar('\n'))
	for (int j=1;j<=m;j++)printf("%d ",a[i][j]);
	getEdge(0,0);
	showEd();*/
	cout << solve() << endl;
	return 0;
}
