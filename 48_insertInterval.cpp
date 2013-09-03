vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {            
	vector<Interval>::iterator it = intervals.begin();  
	while(it!= intervals.end())  
	{  
		if(newInterval.end<it->start)  
		{  
			intervals.insert(it, newInterval);  
			return intervals;  
		}  
		if(newInterval.start > it->end)  
		{  
			it++;  
			continue;  
		}  
		
		newInterval.start = min(newInterval.start, it->start);  
		newInterval.end = max(newInterval.end, it->end);  
		it =intervals.erase(it);                      
		
	}  
	intervals.insert(intervals.end(), newInterval);            
	return intervals;            
}  