class Solution {
public:
    bool isOverCharNine(char& num)
    {
        if (num <= '9') return false;
        return true;
    }
    
    void subtractSumInCarry(char& sum)
    {
         sum -= '1' + '9' - '0' - '0';       
    }
    
    void calculSumAndCarryInCarry(char& sum, int& carry)
    
    {
            if (isOverCharNine(sum) == false)
            {
                 carry = 0;
            }
            else
            {
                 carry = 1;
                 subtractSumInCarry(sum);
            }
     }

    string addStrings(const string& num1, const string& num2) 
    {
        string longerStr;
        string shorterStr;
        if (num1.size() >= num2.size()) { longerStr = move(num1); shorterStr = move(num2); }
        else { longerStr = move(num2); shorterStr = move(num1); }

        char sum;
        int carry = 0;
        string resultStr;

        int longStrPValue = longerStr.size() - 1;  // PValue means Position value (자릿수)
        int shortStrPValue = shorterStr.size() - 1;
        for (;longStrPValue >= 0; longStrPValue--, shortStrPValue--)
        {
            if (longStrPValue >= 0 && shortStrPValue >= 0)
            {
                sum = longerStr[longStrPValue] + shorterStr[shortStrPValue] - '0' + carry;
                calculSumAndCarryInCarry(sum, carry);
            }
            else if (longStrPValue >= 0 && shortStrPValue < 0)
            {
                sum = longerStr[longStrPValue] + carry;
                calculSumAndCarryInCarry(sum, carry);
            }

            resultStr += sum;
        }        
        if (carry == 1) resultStr += '1';
        reverse(resultStr.begin(), resultStr.end());
        return resultStr;
    }
};