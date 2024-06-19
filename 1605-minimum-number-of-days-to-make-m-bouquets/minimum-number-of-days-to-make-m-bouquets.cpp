class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minDay=INT_MAX;
        int maxDay=INT_MIN;
        for(int&day:bloomDay){
            minDay=min(day,minDay);
            maxDay=max(day,maxDay);
        }
        
        int start=minDay;
        int end=maxDay;
        int ret=-1;
        while(start<=end){
            int day=(start+end)/2;
            int bouq2made=m,flowerQuant=k;
            for(int i=0;i<bloomDay.size();i++){
                 if(bloomDay[i]<=day){
                    flowerQuant--;
                    if(flowerQuant==0){
                        bouq2made--;
                        if(bouq2made==0)break;
                        flowerQuant=k;
                    }
                }else flowerQuant=k;
            }
             if(bouq2made==0){
                ret=day;
                end=day-1;
             }else{
                start=day+1;
             }
        }
        return ret;
    }
};