#include <bits/stdc++.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::ios::sync_with_stdio(0); 
        std::cin.tie(0);
        std::cout.tie(0);
            long long ans = INT_MIN, pre = 0 , suf = 0;

    int n = nums.size() ;

    for(int i=0;i<n;i++){
        if(pre==0)
        pre=1;

        if(suf==0)
        suf=1;

        if(pre*10<INT_MAX)
        pre=pre*nums[i];

        if(suf*10<INT_MAX)
        suf=suf*nums[n-i-1];
        ans=max(ans,max(pre,suf));
    }
    return ans;
}
    
};