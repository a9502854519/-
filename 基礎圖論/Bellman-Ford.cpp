/* Bellman_Ford是針對「邊」去做鬆馳操作的。
 * 對所有的邊做鬆馳操作V-1次後，若沒有負環
 * 則計算一定會結束，證明大致上如下：
 * 一條從s出發，到某個點v的最短路，最多會有
 * |V| - 1條邊，第二層迴圈中，演算法對所有
 * 的邊做了鬆馳操作，就算每一次只成功了鬆馳
 * 了一條邊，最多也只需要|V| - 1次，就能鬆
 * 馳所有的邊了。
 */
struct edge{
	int from, to, cost
	edge(){}
	edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

edge E[MAX_E];

int d[MAX_E];
int V, E //頂點數和邊數

//從s出發到所有點的最短距離
//回傳true代表有負環，false代表沒有
bool Bellman_Ford(int s){
	for(int i = 0; i < V; i++) d[i] = INF;
	d[s] = 0;
	for(int i = 0; i < V; i++){
		for(int j = 0; j < E; j++){
			edge e = E[j];
			if(d[e.to] > d[e.from] + e.cost){
				d[e.to = d[e.from] + e.cost;
				if(i == V-1) return false;
			}
		}
	}
	return true;
}