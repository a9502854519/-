#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define MAX_W 6
#define MAX_V 36

using namespace std;

int W, H, V;
int w[MAX_W][MAX_W];
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];


void add_edge(int u, int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
bool dfs(int v){
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){　　　//檢查跟v有暖昧關係的所有女生
		int u = G[v][i], w = match[u];　　　
		if(w < 0 || !used[w] && dfs(w)){　//如果她沒有男朋友，就送作堆
			match[v] = u;　　　　　　//如果她有男朋有了，就幫她的男朋友找一個新的女朋友，然後再送作堆　　
			match[u] = v;
			return true;
		}
	}
	return false;
}
int bipartite_matching(){
	int res = 0;
	memset(match, -1, sizeof(match));
	for(int v = 0; v < V; v++){
		if(match[v] < 0){	//如果有人還沒有女朋友...
			memset(used, 0, sizeof(used));
			if(dfs(v)){　　 //那就幫他找一個
				res++;　//配對成功，配對數加一
			}
		}
	}
	return res;
}
int x[] = {1, 0, 0, -1};
int y[] = {0, 1, -1, 0};

void solve(){
	for(int i = 0; i < H; i++){
		for(int j = (i & 1); j < W; j += 2){
			for(int k = 0; k < 4; k++){
				int a = i + y[k], b = j + x[k];
				if(a >= 0 && a <= H && b >= 0 && b <= W){
					if(w[i][j] == w[a][b]){
						add_edge(i*W+j, a*W+b);
					}
				}
			}
		}
	}
	V = W*H;
	printf("%d\n", bipartite_matching());
}

int  main(){
	cin>>H>>W;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin>>w[i][j];
//			printf("%d ", w[i][j]);
		}
//		cout<<endl;
	}
	solve();
	return 0;
}
