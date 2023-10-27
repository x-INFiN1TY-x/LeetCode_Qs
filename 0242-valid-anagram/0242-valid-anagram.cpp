class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            int n = s.length();
            int k = t.length();
            if (n != k) return false;

            int freq[27] = { 0 };
            for (int i = 0; i < n; i++)
            {
                freq[s[i] - 97]++;
                freq[t[i] - 97]--;
            }

            for (int i = 0; i < 27; i++)
            {
                if (freq[i] != 0)
                {
                    return false;
                }
            }
            return true;
        }
};