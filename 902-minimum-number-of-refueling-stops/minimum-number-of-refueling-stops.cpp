#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int kms, vector<vector<int>>& stations) {
        if(kms >= target) return 0;
        if(stations.empty() || kms < stations[0][0]) return -1;
        
        int i = 0, stops = 0;
        priority_queue<int> mheap;
        
        while(kms < target) {
            while(i < stations.size() && stations[i][0] <= kms) {
                mheap.push(stations[i][1]);
                i++;
            }
            
            if(mheap.empty()) return -1;  // If no stations are reachable and we need fuel
            
            kms += mheap.top();
            mheap.pop();
            stops++;
        }
        
        return stops;
    }
};
