class Solution {
public:   
void mergeCharnumMax3(string &s, int& idx, string & res_s)
{
    for (int k = 0; k < 2; k++) // max_int_length_in_string_s_is_3
    {
        if (isdigit(s[idx+1]))
        {
             idx++;
             res_s = res_s + s[idx];
        }
        else break;
    }
}
string decodeString(string s) {
    stack<string> alphabetStack;
    stack<string> overlapCountStack;
    alphabetStack.push("");
    overlapCountStack.push("");

    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            alphabetStack.top() = alphabetStack.top() + s[i];
        }
        else if (isdigit(s[i]))
        {
            string tmpStr = {s[i]};
            mergeCharnumMax3(s,i,tmpStr);
            overlapCountStack.push(tmpStr);
        }
        else if (s[i] == '[')
        {
            alphabetStack.push("");
        }
        else if (s[i] == ']')
        {
            string tmpStr{ "" };
            string overlapCount = overlapCountStack.top();
            for (int j = 0; j < stoi(overlapCount); j++)
            {
                tmpStr = tmpStr + alphabetStack.top();
            }
            alphabetStack.pop();
            overlapCountStack.pop();
            alphabetStack.top() = alphabetStack.top() + tmpStr;
        }

    }
    return alphabetStack.top();
}

};