
class Solution {
public:

    int totalSteps(vector<int>& arr) {

      int n = arr.size();
      stack<pair<int,int>> st;
      int ans = -1;
       for(int i = n-1;i>=0;i--)
       {
           int cnt = 0;
           while(!st.empty() && st.top().first < arr[i])
           {
               cnt = max(cnt+1,st.top().second);
               st.pop();   
           }
           ans = max(ans,cnt);
           st.push({arr[i],cnt});
       }

       return ans;
    }
};