#include <string>
#include <unordered_map>

class Solution
{
    public:
        int numberOfSpecialChars(std::string word)
        {
            std::unordered_map<char, int> arr;
            int count = 0;
            for (int i = 0; i < word.size(); i++)
            {
                if (std::islower(word[i]))
                {
                    if (arr[word[i]] == INT_MIN)
                    {
                        count--;
                        arr[word[i]] = INT_MAX;
                    }
                    else if (arr[word[i]] == INT_MAX)
                        continue;
                    else
                        arr[word[i]]++;
                }
                if (std::isupper(word[i]))
                {
                    arr[word[i]]++;
                    if (arr[word[i] + 32] == INT_MAX || arr[word[i] + 32] == 0)
                    {
                        continue;
                    }
                    else if (arr[word[i] + 32] > 0 && arr[word[i]] == 1)
                    {
                        count++;
                        arr[word[i] + 32] = INT_MIN;
                    }
                }
            }
            return count;
        }
};