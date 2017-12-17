/* 先枚舉a + b，將結果排序。再枚舉d - c，利用二分搜尋
 * a + b的枚舉結果即可。
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define INF -536870913
using namespace std;

int d[1000];
int n;

struct Data{
	int a;
	int b;
	bool operator < (const Data& other){
		return a + b < other.a + other.b;
	}
};

void solve(){
	vector<Data> v;
	vector<int>  s;
	//枚舉a+b
	sort(d, d + n);
	for(int i = 0; i < n;i++){
		for(int j = i + 1; j < n; j++){
			Data data;
			data.a = d[i], data.b = d[j];
			v.push_back(data);
			s.push_back(d[i] + d[j]);
		}
	}
	sort(v.begin(), v.end());
	sort(s.begin(), s.end());
	//枚舉d-c
	for(int i = n - 1; i >= 0; i--){
		for(int j = i - 1; j >= 0; j--){
			int t = d[i]-d[j];
			int m = lower_bound(s.begin(), s.end(), t) - s.begin();
			for(; m < s.size() && t == s[m]; m++){
				if(v[m].a != d[i] && v[m].b != d[i] && v[m].a != d[j] && v[m].b != d[j]){
					cout<<d[i]<<endl;
					return;
				}
			}
		}
	}
	cout<<"no solution\n";
}
	

int main(){
	
	while(cin>>n){
		int res = -INF;
		if(n == 0) break;
			for(int i = 0; i < n; i++) scanf("%d", &d[i]);
		solve();
	}
	return 0;
}