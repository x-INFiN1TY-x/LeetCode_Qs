auto speedrun=[](){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long n = count(s.begin(),s.end(),c);
        return (n * (n + 1)) / 2;
    }
};
