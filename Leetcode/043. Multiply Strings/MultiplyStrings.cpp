// Leetcode 43. Multiply Strings
// https://leetcode.com/problems/multiply-strings/description/
// Runtime: 13ms

class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        
        int result_size = num1.size() + num2.size();
        char *result = (char*)malloc(sizeof(char) * result_size);
        
        for (int i = 0; i < result_size; i++)
            result[i] = 'A';

        int carry = 0;
        int offset = 0;
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            carry = 0; // reset
            int n2 = num2.at(i) - 48;
            int k = 0;

            for (int j = num1.size() - 1; j >= 0; j--)
            {
                int n1 = num1.at(j) - 48;
                int prod = n1 * n2;
                int current_num = (prod + carry) % 10;
                carry = (prod + carry) / 10;

                int num_in_result = 0;
                if (result[result_size - offset - k - 1] == 'A')
                {
                    num_in_result = 0;
                }
                else
                {
                    num_in_result = (int)(result[result_size - offset - k - 1] - 48);
                }

                int final_num = current_num + num_in_result;
                if (final_num > 9)
                {
                    carry++;
                    final_num = final_num % 10;
                }

                result[result_size - offset - k - 1] = (char)(final_num + 48);
                k++;
            }

            if (carry > 0)
            {
                if (result[result_size - offset - k - 1] == 'A')
                {
                    result[result_size - offset - k - 1] = (char)(carry + 48);
                }
                else
                {
                    result[result_size - offset - k - 1] = (char)(result[result_size - offset - k - 1] + carry);
                }
            }
            offset++;
        }

        string resultStr;

        for (int i = 0; i < result_size; i++)
        {
            if (result[i] != 'A')
            {
                resultStr.push_back(result[i]);
            }
        }

        return resultStr;
    }
};
