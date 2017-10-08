struct edge{
	int to, cost;
	edge() {}
	edge(int t, int c) : to(t), cost(c) {}
};
vector<edge> G[MAX_V];  //鄰接表
int mincost[MAX_V];     //從S集合出發到每個頂點的最小權值
bool used[MAX_V];       //是否已經在S集合中了
int V;                  //頂點數

typedef pair<int, int> P;

int prim(){
	fill(mincost, mincost + V, INF);
	memset(used, false, sizeof(used));
	priority_queue< P, vector<P>, greater<P> > que;
	mincost[0] = 0;
	que.push(P(0, 0)); //加入Ｑ集合中
	int res = 0;
	
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(mincost[v] < p.first) continue;
		
		used[v] = true;
		res += p.first;
		
		for(int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];
			if(!used[e.to] && mincost[e.to] > e.cost){
				mincost[e.to] = e.cost;
				que.push(P(e.cost, e.to));
			}
		}
	}
	return res;
}
