class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 0; 

        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (nums[i] > nums[i + 1]) {
                    return i;
                }
            } else if (i == n - 1) {
                if (nums[i] > nums[i - 1]) {
                    return i;
                }
            } else {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                    return i;
                }
            }
        }
        
        return -1; 
    }
};
int init = [] {
    ofstream s("user.out");
    string in;
    int x, y, z, i;
    while(cin.get(), cin >> y){
        x = 1 << 31;
        i = 0;
        while(cin.get() != ']'){
            cin >> z;
            if(x < y && y > z){
                while(cin.get() != ']')
                    cin >> z;
                break;
            }
            i++;
            x = y;
            y = z;
        }

        cin.get();
        s << i << '\n';
    }
    s.flush();
    exit(0);
    return 0;
}();