/* 題目要求移除最小的區間，可以轉化成求最大的不重疊
 * 區間集合。按照區間結束時間做排序，盡可以地選取不
 * 重疊區間即可。可用數學歸納法證明最佳性。
 */
bool cmp_end(const Interval& a, const Interval& b){
    return a.end < b.end;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp_end);
        int count = 0;
        int last = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i].start < intervals[last].end){
                count++;
            }else 
                last = i;
        }
        return count;
    }
};