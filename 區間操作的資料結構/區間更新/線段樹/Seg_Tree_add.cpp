//查詢區間和的線段樹
//區間更新：共同加上某一個值。

#define MAX_N 16
int dat[2 * MAX_N - 1];
int add[2 * MAX_N - 1];//保存節點需要共同加上的值
int n;//the size of the segment tree

void init(int n_){
	n = 1;
	while(n < n_) n *= 2; //區間大小必須為2的次方
	memset(dat, 0, sizeof(dat));
	memset(add, 0, sizeof(add));
}
void update(int x, int v){ //單點更新
	int k = x + n - 1; //從最底部開始更新
	dat[k] += v;
	while(k > 0){
		k = (k - 1) / 2;
		dat[k] += v;
	}
}
void update(int a, int b, int k, int l, int r, int x){ //區間更新
	if(b <= l || a >= r) return; //沒有交集
	if(a <= l && b >= r){ //節點的區間完全被需要更新的區間涵蓋
		add[k] += x; //代表這個節點的區間需要共同加上的值
		return;
	}
	dat[k] += (min(b, r) - max(a, l)) * x;
	//因為這個節點沒有完全被涵蓋，所以直接把需要更新的值加進原來
	//的線段樹中。
	update(a, b, 2 * k + 1, l, (l + r) / 2, x);
	update(a, b, 2 * k + 2, (l + r) / 2, r, x);
}
void update(int a, int b, int x){//[a, b)
	update(a, b, 0, 0, n, x);
}
int query(int a, int b, int k, int l, int r){
	if(b <= l || a >= r) return 0;
	if(a <= l && b >= r){
		return dat[k] + add[k] * (r - l);
	}
	int v1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
	int v2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return v1 + v2 + add[k] * (min(b, r) - max(a, l));
}
int query(int a, int b){//[a, b)
	return query(a, b, 0, 0, n);
}
