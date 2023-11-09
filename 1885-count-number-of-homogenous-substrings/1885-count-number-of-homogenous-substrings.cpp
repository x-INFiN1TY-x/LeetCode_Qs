int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();
class Solution 
{
public:
    int countHomogenous(string s) 
    {
        //brute force
        // long long int count=0;
        // long long int size=1;
        // for(int i=1;i<s.size();i++)
        // {
        //     if(s[i]==s[i-1])
        //        size++;
        //     else
        //     {
        //         cout<<size<<"#"<<endl;
        //         count=count+(size*(size+1))/2;
        //         size=1;
        //     }  
        // }
        // if(size>=1 && size<s.size())
        //    count+=(size*(size+1))/2;
        // if(size==s.size())
        //    count=(size*(size+1))/2;
        // return count%1000000007;
        

        //two pointer approach
        long long int j=0;
        long long int i=0;
        long long int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[j])
            {
                int size=i-j;
                count+=(size*(size+1)/2);
                j=i;
            } 
        }
        if(i!=j)
        {
            int size=s.size()-j;
            count+=(size*(size+1)/2);
        }
        if(count==0)
        {
             count=(s.size()*(s.size()+1)/2);
        }
        cout<<count<<endl;
        return count%1000000007;
    }
};