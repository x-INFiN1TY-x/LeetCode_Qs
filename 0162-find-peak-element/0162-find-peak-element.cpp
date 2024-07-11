class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int n=v.size()-1;

        if(v.size()==1) return 0;
        if(v[0]>v[1]) return 0;
        if(v[n]>v[n-1]) return n;

        int low=1, high=v.size()-2, ans=0;

        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid-1]<v[mid] && v[mid]>v[mid+1]){
                ans=mid;
                break;
            }
            if(v[mid-1]>v[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};