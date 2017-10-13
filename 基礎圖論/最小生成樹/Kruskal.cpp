struct edge{
	int u, v, cost;
	edge() {}
	edge(int u, int v, int c) : u(u), v(v), cost(c) {}
};
bool comp(const edge& e1, const edge& e2){
	return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal(){
	sort(es, es+E, comp);
	init_union_find(V);    //集合初始化
	int res = 0;
	for(int i = 0; i < E; i++){
		edge e = es[i];
		if(!same(e.u, e.v)){//如果兩個點分屬不同的集合，則將其合併
			unite(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
