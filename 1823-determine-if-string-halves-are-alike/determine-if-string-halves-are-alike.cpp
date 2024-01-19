class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.size() ,c=0,d=0;
        for(int i =0,j=len-1;i<len/2;i++,j--)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            c++;
            if(s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'||s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            d++;
        }
        return c==d;
    }
};