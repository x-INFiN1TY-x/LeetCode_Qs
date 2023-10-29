class Solution {
public:
    int binarySearchTar(vector<int>& nums, int begin, int end, int target){ // recursive function
        int middle = (begin + end) / 2;
        if(nums[middle] == target){ // base case
            return middle;
        }else if(nums[middle] < target){ // recurse top half
            if(end > middle){ // check so we dont go out of range
                if(nums[middle + 1] > target){return middle + 1;}
            }
            return binarySearchTar(nums, middle + 1, end, target);
        }else{ // recurse bottom half
            if(middle - 1 >= 0){ // check so we dont go out of range
                if(nums[middle - 1] < target){return middle ;}
            }
            return binarySearchTar(nums, begin, middle - 1, target);
        }
    }
        
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); // makes tests run faster, look it up elsewhere
        cin.tie(nullptr);
        if(target >= nums[nums.size()-1]){ // check if target > greatest value
            if(target == nums[nums.size()-1]){
                return nums.size()-1;
            }
            return nums.size();
        }
        if(target <= nums[0]){ // check if target lower than smallest
            return 0;
        }
        return binarySearchTar(nums, 0, nums.size()-1, target);
    }
};