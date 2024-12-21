#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL; // using 64-bit base hashing

static const ULL base = 131542391ULL;

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        int n = (int)nums.size();
        // Precompute powers of base
        vector<ULL> power(n+1, 1ULL);
        for(int i = 1; i <= n; i++){
            power[i] = power[i-1] * base;
        }

        // Build prefix hash
        vector<ULL> prefixHash(n+1, 0ULL);
        for(int i = 0; i < n; i++){
            prefixHash[i+1] = prefixHash[i] * base + (ULL)(nums[i]+1);
        }

        auto getHash = [&](int l, int r){
            // hash of subarray [l..r]
            ULL h = prefixHash[r+1] - prefixHash[l] * power[r - l + 1];
            return h;
        };

        long long count = 0;
        for(int i = 1; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                // check nums1 prefix of nums2
                // nums1 length = i, nums2 length = j - i
                if(i <= (j - i)) {
                    // subarray [0..i-1] equals [i..(2i-1)]
                    // ensure 2i <= j
                    if(2*i <= j) {
                        if(getHash(0, i-1) == getHash(i, 2*i -1)){
                            count++;
                            continue; // no need to check second condition
                        }
                    }
                }
                // check nums2 prefix of nums3
                // nums2 length = j - i, nums3 length = n - j
                if((j - i) <= (n - j)) {
                    // subarray [i..j-1] == [j..j+(j-i)-1]
                    // ensure j+(j-i)-1 < n => 2j - i <= n
                    if(2*j - i <= n) {
                        if(getHash(i, j-1) == getHash(j, j + (j - i) - 1)){
                            count++;
                        }
                    }
                }
            }
        }
        return (int)count;
    }
};