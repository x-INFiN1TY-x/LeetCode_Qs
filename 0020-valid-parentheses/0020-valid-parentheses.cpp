class Solution {
public:
    bool isValid(string s) {
        //similar soln to above
        if (s.size()&1 == 1){ return 0; }

        int i = 0;
        while (!s.empty()){
            if (i == s.size() - 1){ return 0; }

            if (s[i + 1] - s[i] == 2 || s[i + 1] - s[i] == 1){
                s.erase(s.begin() + i);
                s.erase(s.begin() + i);

                if (i != 0){ --i; }
            } else { ++i; }
        }
        return 1;
    }
};