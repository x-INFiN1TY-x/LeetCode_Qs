class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> arr;
        string ele;
        while(iss >> ele)
        {
            ele+=' ';
            arr.push_back(ele);
        }
        arr[0].pop_back();
        reverse(arr.begin(), arr.end());
        s.clear();
        for(string i : arr)
        {
            s+=i;
        }
        return s;

    }
};