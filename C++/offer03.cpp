#include"stdfax.h"
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            if(m.find(i)!=m.end()){
                return i;
            }
            m[i]=1;
        }
        return 0;
    }
    
};