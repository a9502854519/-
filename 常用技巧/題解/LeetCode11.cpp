class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size()-1;
        int i = 0;
        int ans = 0;
        int local_max;
        
        while(i < j){
           local_max = min(height[i], height[j]) * (j - i);
           ans = max(local_max, ans);
           if(height[i] < height[j]) i++;
           else                      j--;
        }
        return ans;
    }
};