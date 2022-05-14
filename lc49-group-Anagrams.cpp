class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> uMapStrAndVecstr;
    
    string tmpStr;
    for (auto str : strs)
    {
        tmpStr = str;
        sort(tmpStr.begin(), tmpStr.end());
        uMapStrAndVecstr[tmpStr].push_back(str);
    }
    for (auto vecstr : uMapStrAndVecstr)
    {
        res.emplace_back(vecstr.second);           
    }

    return res;
    }

};