class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            stringstream line(s);
            string word;
            while (!line.eof())
            {
                line >> word;
            }
            if (!word.empty())
                return word.size();
            else
                return 0;
        }
};