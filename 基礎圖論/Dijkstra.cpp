/* 若圖中沒有負邊，則可以使用Dijkstra演算法。
 * Dijkstra是針對「點」做鬆馳操作的。
 * 每一次從圖中找從s出發可以到達的最近的點，
 * 對與該點連接的所有的點做鬆馳操作。我們的
 * 假設是：在while迴圈一開始的時候，當我們從
 * 堆中取出一個點時，它的路徑長度值必為最短。
 * 證明大致上如下：
 *
 * 每次從堆中取出一個點，進行鬆馳操作，然
 * 後把它加入一個集合S中(這在演算法裡看不到，
 * 這裡只是為了方便，才有這種設定)。
 * 接著假設我們從堆中取出一個點u，它是「第一
 * 個」路徑長不是最短的點(換句話說，S集合中的
 * 點的路徑長都是最短的，無庸置疑)。則必存在
 * 一個點y(注意：y不是S集合的點)，通過y到u，
 * 可以成為u的最短路徑。則有以下的關係：
 * 起點到y的路徑長+y到u的路徑長 < 起點到u的路徑長
 * 用數學符號描述就是：
 * d[y] + w(y, u) < d[u]
 * 移項一下可得：
 * d[y] < d[u] - w(y, u)
 * d[y] < d[u]
 * 靠北，我們從堆取出來的點，他的路徑長不是
 * 要最短嗎？為什麼冒出來一個點y，它的路徑
 * 長反而還更短？矛盾嘛。證明完啦。
 * 要注意的是，上式要成立的關鍵為w(y, u) > 0。
 * 若w(y, u) < 0則不成立，這也是為什麼Dijkstra
 * 不能用在有負邊的情況。
 */






//#include<utility>
//#include<algorithm>
//#include<queue>
struct edge{
	int to, cost;
	edge() {}
	edge(int to, int cost) : to(to), cost(cost) {}
};

typedef pair<int, int> P; //first最短距離，second是頂點編號

int V;
vector<edge> G[MAX_V];
int d[MAX_V];
//從s出發
void dijkstra(int s){
	//通過指定greater<P> 參數，要求堆由小到大彈出值
	priority_queue< P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
	d[s] = 0;
	que.push(P(0, s));
	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v] < p.first) continue; //代表資料已經過時了，沒必要對它計算
		for(int i = 0; i < G[v].size(); i++){
			edeg e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}