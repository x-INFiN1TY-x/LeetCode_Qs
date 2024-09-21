class Solution {
public:

long long numberOfWays(string s) {
	long long total0 = 0, total1 = 0;
    
    for(char i: s){
        if(i == '0') total0++;
        if(i == '1') total1++;
    }
    
    long long ans = 0;
    
    // count of 0s and 1s till current position i.e. left of current position
    long long count0 = 0, count1 = 0;
    
    for(char i: s){
        // for all "0....0 1 0...0" type            
        if(i == '1'){
            ans += count0 * (total0 - count0);      //(no. of 0s left of 1) * (no. of 0s after 1)
            count1++;
        }
        
        // for all "1....1 0 1...1" type
        if(i == '0'){
            ans += count1 * (total1 - count1);      //(no. of 1s left of 0) * (no. of 1s after 0)
            count0++;
        }
    }
    
    return ans;
}};