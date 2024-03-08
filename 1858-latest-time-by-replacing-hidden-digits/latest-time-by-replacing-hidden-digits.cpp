class Solution
{
    public:
        string maximumTime(string time)
        {
            if (time[0] == '?' && time[1] == '?') time[0] = '2', time[1] = '3';
            else if (time[0] == '?' && time[1] > '3') time[0] = '1';
            else if (time[0] == '?' && time[1] <= '3') time[0] = '2';
            else if (time[1] == '?' && (time[0] == '0' || time[0] == '1')) time[1] = '9';
            else if (time[1] == '?' && time[0] == '2') time[1] = '3';

            if (time[3] == '?' && time[4] == '?') time[3] = '5', time[4] = '9';
            else if (time[3] == '?') time[3] = '5';
            else if (time[4] == '?') time[4] = '9';
            return time;
        }
};