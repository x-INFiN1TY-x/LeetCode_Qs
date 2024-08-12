class Solution {
public:
    bool closeStrings(string wq, string we) {
        if(wq.size()!=we.size())
        return false;
        
        set<char> a(wq.begin(),wq.end()),b(we.begin(),we.end());
        if(a!=b) return false;

        unordered_map<char,int> aa,bb;
        for(int i =0 ; i < we.size() ; i ++)
        {
            aa[wq[i]]++;
            bb[we[i]]++;
        }
        vector<int> arr;
        for(auto i : aa)
        {
            arr.push_back(i.second);
        }
    
        vector<int> arr2;
        for(auto i : bb)
        {
            arr2.push_back(i.second);
        }
        sort(arr2.begin(),arr2.end());
        sort(arr.begin(),arr.end());
        if(arr2==arr) return true;
        return false;
    }
};