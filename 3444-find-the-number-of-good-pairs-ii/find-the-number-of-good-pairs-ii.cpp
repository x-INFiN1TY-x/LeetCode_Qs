#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
    public:
        long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    long long ans = 0;
    unordered_map<int,int> freq;
    for(auto n: nums2) freq[n]++;
    for(auto n: nums1){
        if(n%k != 0) continue;
        int sr = sqrt(n/k);
        for(int i = 1, t = n/k; i <= sr; ++i){
            if(t%i != 0) continue;
            ans += freq[i];
            if(i != t/i) ans += freq[t/i];
        }
    }
    return ans;
}
};