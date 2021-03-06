#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<utility>
#define INF 1E9
#define MAX_R 8
#define MAX_C 8
#define NUM(i, j) i * C + j
#define ROW(v) v / C
#define COL(v) v % C

using namespace std;
typedef pair<int, int> P;

int R, C;
char d[MAX_R][MAX_C+1];
int level[MAX_R][MAX_C];

int x[] = {1, -1, 0, 0, 0};
int y[] = {0, 0, 1, -1, 0};

bool check(int a, int b, int t1, int t2){
	bool ok = true;
	if(b + t1 >= 0 && b + t1 < C && d[a][b + t1] == 'X') ok = false;
	if(b + t2 >= 0 && b + t2 < C && d[a][b + t2] == 'X') ok = false;
	return ok;	
}
bool relax(int& u, int t){
	if(u < 0 || u > t + 1){
		u = t + 1;
		return true;
	}
	return false;
}
int bfs(int s){
	memset(level, -1, sizeof(level));
	queue<P> que;

	que.push(P(s, 0));
	level[ROW(s)][COL(s)] = 0;

	while(!que.empty()){
		P p = que.front(); que.pop();
		int v = p.first, t = p.second;
		int i = ROW(v), j = COL(v);
		
		if(i == 0) return v;

		for(int k = 0; k < 5; k++){
			int a = i + x[k], b = j + y[k];
			if(a >= 0 && a < R && b >= 0 && b < C
			    && (d[a][b] == 'X' || d[a][b] == '.' || d[a][b] == 'O')){//確認是否可以走
				bool ok = false;
				if(a & 1) ok = check(a, b, -t, -t-1);
				else 		ok = check(a, b, t, t + 1);
				if(ok && (v == NUM(a, b) || relax(level[a][b], t))) que.push(P(NUM(a, b), t + 1));	
			}
		}
	}	
}
void solve(){
	int s = -1;
	for(int i = 0; i < R && s < 0; i++){
		for(int j = 0; j < C && s < 0; j++){
			if(d[i][j] == 'O') s = NUM(i, j);
		}
	}
	int v = bfs(s);
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			printf("%2d ", level[i][j]);
		}
		printf("\n");
	}
	printf("%d\n", level[ROW(v)][COL(v)]);
}
int main(){
	scanf("%d %d\n", &R, &C);
	for(int i = 0; i < R; i++){
		scanf("%[^\n]%*c", d[i]);
	}
	solve();
	return 0;
}
