class Solution {
public:
    int minOperations(vector<string>& logs) {
        int countOperations=0;
        for(string i:logs){
            if(countOperations<0)countOperations=0;
            if(i=="../")countOperations--;
            else if(i=="./")continue;
            else countOperations++;
        }
        if(countOperations<=0)return 0;
        return countOperations;
    }
};