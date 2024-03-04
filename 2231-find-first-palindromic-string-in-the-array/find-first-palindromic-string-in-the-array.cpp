#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static string firstPalindrome(vector<string>& words) {
        for( string& s: words){
            bool isPal=1;
            for(int l=0, r=s.size()-1; l<r; l++, r--){
                if (s[l]!=s[r]){
                    isPal=0;
                    break;
                }
            }
            if(isPal) return s;
        }
        return "";
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();