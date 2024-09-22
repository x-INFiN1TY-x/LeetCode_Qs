class Solution {
public:
    int kthFactor(int n, int k) {
        int count =0;
        int i;
        for(i=1;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                if(n/i == i)
                    count++;
                else
                    count+=2;
            }
        }
        if(count < k)
            return -1;
        int c = 0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i == 0)
            {
                c++;
                if(c == k || count+1 == k + c)
                {
                    if(k > count/2)
                        return n/i;
                    else
                        return i;
                }
            }
        }
        return -1;
    }
};