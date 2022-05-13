class Solution {
public:
    bool isAlphabet(string& s, int& num)
    {
        if ((s[num] < 'A' || s[num] > 'z') || (s[num] > 'Z' && s[num] < 'a')) return false;
        return true;
    }

    bool isNum(string& s, int& num)
    {
        if (s[num] < '0' || s[num] > '9') return false;
        return true;
    }
    
    bool isPalindrome(string s) {
        int LIdx = 0;
        int RIdx = s.size() - 1;
        
        while (LIdx <= RIdx)
        {
            if (!isAlphabet(s, LIdx) && !isNum(s, LIdx)) LIdx++;
            else if (!isAlphabet(s, RIdx) && !isNum(s, RIdx)) RIdx--;
            else
            {   
                if (s[LIdx] != s[RIdx])
                {
                    if (isAlphabet(s, LIdx) && isAlphabet(s, RIdx))
                    {
                        if (tolower(s[LIdx]) != s[RIdx] &&
                            toupper(s[LIdx]) != s[RIdx]) return false;
                    }
                    else return false;
                }
                LIdx++;
                RIdx--;
                
            }
        }
        return true;
    }
};