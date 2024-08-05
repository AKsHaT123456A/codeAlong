class Solution {
public:
    std::string kthDistinct(std::vector<std::string>& arr, int k) {
        std::unordered_map<std::string, int> mp;
        for (const std::string& a : arr) {
            mp[a]++;
        }
        int cnt = 0;
        for (const std::string& a : arr) {
            if (mp[a] == 1) {
                cnt++;
                if (cnt == k) {
                    return a;
                }else if(cnt>k)return arr[0];
            }
        }
        
        return ""; 
    }
};