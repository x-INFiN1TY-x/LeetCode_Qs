class Solution {
public:
    static string kthDistinct(vector<string>& arr, int k) {
        const int n=arr.size();
        vector<string> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());

        for(string& s: arr){
            int i=lower_bound(sorted.begin(), sorted.end(), s)-sorted.begin();
            if (i==n-1 ||sorted[i]!=sorted[i+1]) k--;
            if (k==0) return s;
        }
        return "";  
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();