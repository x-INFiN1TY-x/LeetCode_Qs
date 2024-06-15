class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        vector<pair<int,int>>vp;
        int n = profits.size();
        k = min(k,n);
        for(int i = 0; i < n; i++){
            vp.push_back({capital[i], profits[i]});
        }
        sort(vp.begin(), vp.end());
        int i = 0;
        priority_queue<int>pq;
        while(k--){
            while(i < n && vp[i].first <= w){
                pq.push(vp[i].second);
                i++;
            }
            if(pq.empty())return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};