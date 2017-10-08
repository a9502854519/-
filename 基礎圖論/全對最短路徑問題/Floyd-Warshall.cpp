int d[MAX_V][MAX_V];
int V;

void floyd_warshall(){
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				d[i][j] = max(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}