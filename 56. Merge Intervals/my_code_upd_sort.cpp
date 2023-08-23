class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end()); // --> if i < j --> intervals[i][0] <=  intervals[j][0] --> проверку пересечения можно делать только по второй координате, а именно: 
                                                  // если левая граница больше правой == intervals[i][1] < intervals[j][0] -- пересечений нет, ибо начало следующего отрезка больше конца предыдущего.
                                                  // это следует из условия отсутсивия пересечения: intervals[i][1] < intervals[j][0] || intervals[j][1] < intervals[i][0] -- второе условие        
                                                  // невозможно ввиду sort(intervals), так как intervals[j][0] <= intervals[j][1] < intervals[i][0] -- противоречие с первым неравенством        

        vector<vector<int>> Covers;
        Covers.reserve(intervals.size());

        for(auto interval : intervals){

            if(Covers.empty() || ! /*CheckIntersection = */ (interval[0] <= Covers.back()[1])){
                Covers.push_back(move(interval));
            }else{ // CheckIntersection == true
                Covers.back()[1] = max(Covers.back()[1], interval[1]);
            }

        }

        Covers.shrink_to_fit();
        return Covers;

    }
};
