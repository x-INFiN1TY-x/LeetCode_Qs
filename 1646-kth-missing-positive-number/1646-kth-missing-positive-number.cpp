class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {

        for (auto& x : A) 
            if (x <= k)  k++;
            else break;
        
        return k;
    }
};