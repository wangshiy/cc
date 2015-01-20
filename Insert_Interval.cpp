/*
Problem:
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include<vector>
#include<iostream>

using namespace std;

struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
/*
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{            
	vector<Interval>::iterator it = intervals.begin();  
    while(it!= intervals.end())  
    {  
		if(newInterval.end<it->start)  
		{ 
			//cout << "i'm here" << endl;
			intervals.insert(it, newInterval);  
            return intervals;  
        }  
        else if(newInterval.start > it->end)  
        {  
			it++;  
            continue;  
        }  
        else  
        {  
			newInterval.start = min(newInterval.start, it->start);  
            newInterval.end = max(newInterval.end, it->end);  
            it =intervals.erase(it);                      
        }                 
	}  
    intervals.insert(intervals.end(), newInterval);            
    return intervals;            
}
*/
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
	vector<Interval>::iterator it=intervals.begin();
    int overlap = 0;
    while(it!=intervals.end()) 
	{
		if(newInterval.start > it->end) {}   // before newInterval, no overlap
        else if(newInterval.end < it->start)  // after newInterval, no overlap
        break;
        else 
		{  // overlap
			newInterval.start = min(newInterval.start,it->start);
            newInterval.end   = max(newInterval.end,it->end);
            overlap++;
        }
        it++;
	}
        
	if(overlap!=0)
    it = intervals.erase(it-overlap,it);
    intervals.insert(it,newInterval);
    return intervals;
}

int main()
{
	Interval a1(1,2), a2(3,5), a3(6,7), a4(8,10), a5(12,16);
	vector<Interval> exist;
	exist.push_back(a1);
	exist.push_back(a2);
	exist.push_back(a3);
	exist.push_back(a4);
	exist.push_back(a5);

	Interval somenew(-1,0);
	//vector<Interval> somenew;
	//somenew.push_back(b1);

	vector<Interval> result;
	result = insert(exist,somenew);

	vector<Interval>::iterator it = result.begin();
	while (it != result.end())
	{
		cout << "it->start: " << it->start << endl;
		cout << "it->end: " << it->end << endl;
		it++;
	}

	//vector<Interval>::iterator itit = result.end();
	//cout << "hi it ->start: " << itit->start << endl;


	return 0;
}