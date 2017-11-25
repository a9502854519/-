//查詢區間和的線段樹
//區間更新：將某個區間全部改成某一個值
#define MAX_N 16
#define INF 0x3f3f3f3f

int dat[2 * MAX_N - 1];
int reset[2 * MAX_N - 1]; //被「重置」後的值
int n;//the size of the segment tree

void init(int n_){
	n = 1;
	while(n < n_) n *= 2; //區間大小必須為2的次方
	memset(dat, 0, sizeof(dat));
	memset(reset, 0x3f, sizeof(reset)); //以INF代表「沒被重置」
}
void update(int x, int v){ //單點更新
	int k = x + n - 1; //從最底部開始更新
	dat[k] += v;
	while(k > 0){
		k = (k - 1) / 2;
		dat[k] += v;
	}
}
void update(int a, int b, int k, int l, int r, int x){
	if(b <= l || a >= r) return;
	if(a <= l && b >= r){ //若節點的區間完全被更新的區間涵蓋
		reset[k] = x;     //這個節點的區間被「重置」後的值
		return;
	}
	int lch = 2 * k + 1, rch = 2 * k + 2;
	if(reset[k] < INF){
		reset[lch] = reset[rch] = reset[k];
	}
	//這裡就是「延遲傳播」的意涵所在，在有需要的時
	//候，才把更新的值「往下傳播」
	update(a, b, lch, l, (l + r) / 2, x);
	update(a, b, rch, (l + r) / 2, r, x);
	
	if(reset[lch] == reset[rch]) reset[k] = reset[lch]; //如果兩個子節點的重置後的值一樣，則將該值往上傳播到父節點。
	else reset[k] = INF; //否則，當做什麼事都沒有發生
}
void update(int a, int b, int x){ //[a, b)
	update(a, b, 0, 0, n, x);
}
int query(int a, int b, int k, int l, int r){
	if(b <= l || a >= r) return 0;
	if(reset[k] < INF) return (min(b, r) - max(a, l)) * reset[k];
	//先確認是否有被重置
	if(a <= l && b >= r){
		return dat[k];
	}
	//如果沒有，再使用原來的線段樹。
	int v1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
	int v2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return v1 + v2;
}
int query(int a, int b){//[a, b)
	return query(a, b, 0, 0, n);
}
