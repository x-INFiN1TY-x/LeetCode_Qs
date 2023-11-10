class Solution {
public:
    int mp[200002][2],n;
    vector<int> restoreArray(vector<vector<int>>& ap) {
        n=ap.size();
        vector <int> rt(n+1);
        int root=-1,fa=-1;
        for(int i=0;i<n;++i){
            ap[i][0]+=100001;
            ap[i][1]+=100001;
            if(mp[ap[i][0]][0]){
                mp[ap[i][0]][1]=ap[i][1];
            }
            else{
                mp[ap[i][0]][0]=ap[i][1];
            }
            if(mp[ap[i][1]][0]){
                mp[ap[i][1]][1]=ap[i][0];
            }
            else{
                mp[ap[i][1]][0]=ap[i][0];
            }
        }
        for(int i=0;i<n;++i){
            if(!mp[ap[i][0]][1]){
                root=ap[i][0];
                break;
            }
            if(!mp[ap[i][1]][1]){
                root=ap[i][1];
                break;
            }
        }
        rt[0]=root-100001;
        for(int i=0;i<n;++i){
            if(mp[root][0]!=fa){
                fa=root;
                root=mp[root][0];
            }
            else{
                fa=root;
                root=mp[root][1];
            }
            rt[i+1]=root-100001;
        }
        return rt;
    }
};