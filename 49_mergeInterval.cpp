/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
bool aa (Interval i1, Interval i2){  
	return i1.start < i2.start;
	
}
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		sort(intervals.begin(), intervals.end(),aa);
		if (intervals.size()==0){
			return intervals;
		}
		vector<Interval>::iterator it = intervals.begin();
		
		while ((it+1) != intervals.end()){
			if (it->end < (it+1)->start){
				++it;
				continue;
			}
			it->end = max (it->end,(it+1)->end);
			intervals.erase(it+1);
		}
		return intervals;
	}
};