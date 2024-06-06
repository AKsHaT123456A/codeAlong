class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int si = hand.size();
        if (si % groupSize != 0) return false;
        
        map<int, int> count;
        for (auto i : hand) {
            count[i]++;
        }
                for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > 0) {
                int start = it->first;
                int numOfGroups = it->second;
                for (int i = 0; i < groupSize; ++i) {
                    if (count[start + i] < numOfGroups) {
                        return false;
                    }
                    count[start + i] -= numOfGroups;
                }
            }
        }
        
        return true;
    }
};
