#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;


struct Data{
	int score;
	int aid;
	bool operator < (Data& other){
		return score < other.score;
	}
};
struct Financial_Aid{
	int aid;
	int id;
	bool operator < (Financial_Aid& other){
		return aid < other.aid;
	}
};
int N, C, F;
Data data[100000];
Financial_Aid f_a[100000];

bool D(int x){
	int sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
	for(int i = 0; i < C; i++){
		if(f_a[i].id < x && count1 < N/2){
			sum1 += f_a[i].aid;
			count1++;
		}
		if(f_a[i].id > x && count2 < N/2){
			sum2 += f_a[i].aid;
			count2++;
		}
	}

}
int main(){
	cin>>N>>C>>F;
	for(int i = 0; i < C; i++){
		cin>>data[i].score>>data[i].aid;
	}
	sort(data, data + C);
	for(int i = 0; i < C; i++){
		f_a[i].aid = data[i].aid;
		f_a[i].id = i;
	}
	sort(f_a, f_a + C);
	
	int ub = C - (N/2) , lb = (N/2) - 1, mid;
	while(ub - lb > 1){
		mid = (ub + lb) / 2;
		if(D(mid)) lb = mid;
		else ub = mid;
	}
	printf("%d\n", (lb == (N/2)-1 ? -1 : data[lb].score));
	return 0;
}