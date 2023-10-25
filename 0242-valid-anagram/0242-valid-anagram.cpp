class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            int n = s.length();
            int k = t.length();
            if (n != k) return false;

            int freq[256] = { 0 };
            for (int i = 0; i < n; i++)
            {
                freq[s[i]]++;
            }
            for (int i = 0; i < k; i++)
            {
                freq[t[i]]--;
            }
            for (int i = 0; i < 256; i++)
            {
                if (freq[i] != 0)
                {
                    return false;
                }
            }
            return true;
            return true;
        }
};