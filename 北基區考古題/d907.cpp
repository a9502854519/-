#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX_V 10
#define MAX_S 10

using namespace std;

int n, a, b, s;
int d[MAX_V][MAX_V][MAX_S+1];

void solve(){
	for(int k = 1; k <= s; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int m = 0; m < n; m++){
					if(d[m][j][0] > 0){
						d[i][j][k] += d[i][m][k-1];	
					}
				}

			}
		}
	}
	cout<<d[a-1][b-1][s]<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			bool ok = false;
			for(int k = 0; k <= s; k++){
				ok |= d[i][j][k];
			}
			if(!ok){
				printf("%d\n%d\n", i+1, j+1);
				return;
			}
		}
	}
	printf("0\n0\n");
}
int main(){
	cin>>n;
	char str[11];
	memset(d, 0, sizeof(d));
	for(int i = 0; i < n; i++){
		scanf("%s", str);
		for(int j = 0; str[j] != '\0'; j++){	
			d[i][j][0] = (int)(str[j] - '0');
		}
	}
	cin>>a>>b>>s;
	solve();
	return 0;
}
	

