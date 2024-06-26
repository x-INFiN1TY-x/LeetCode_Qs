class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        bool check = false;
        unordered_map<char,int>map;
        for(auto ch: s){
            map[ch]++;
        }
        for(auto i: map){
            if(i.second % 2 == 0){
                ans += i.second;
            }else{
                ans += i.second-1;
                check = true;
            }
        }
        return (check)?ans+1:ans;
    }
};