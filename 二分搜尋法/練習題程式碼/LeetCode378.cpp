class Solution {
public:
	vector<int> v;
	bool C(int x, int k){
		return upper_bound(v.begin(), v.end(), x) - v.begin() >= k;
	}
    int kthSmallest(vector<vector<int>>& matrix, int k) {
	    int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;//[lo, hi)
		while(hi > lo) {
			int mid = lo + (hi - lo) / 2;
			
			int count = 0,  j = matrix[0].size() - 1;
			for(int i = 0; i < matrix.size(); i++) {
				while(j >= 0 && matrix[i][j] > mid) j--;
				count += (j + 1);
			}
			
			if(count < k) lo = mid + 1;
			else hi = mid;
		}
		return hi;
    }
};
