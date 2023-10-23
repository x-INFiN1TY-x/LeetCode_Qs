class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ptr = 0;
        int ptr2 = 0;
        int ss = ransomNote.size();
        int ts = magazine.size();
        // Sort the strings
        sort(ransomNote.begin(), ransomNote.end());
        sort(magazine.begin(), magazine.end());


        while (ptr < ss && ptr2 < ts) {
            if (ransomNote[ptr] == magazine[ptr2]) {
                ptr++;
            }
            ptr2++;
        }
        
        return ptr == ss;
    }
};
