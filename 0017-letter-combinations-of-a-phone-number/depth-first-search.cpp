using namespace std;

class Solution 
{
    public:
        vector<string> letterCombinations(string digits)
        {
            vector<string> result;
            if (!digits.empty())
            {
                dfs(0, digits, "", result);
            }

            return result;
        }

    private:
        const vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        void dfs(int i, const string& digits, string&& tmp, vector<string>& res)
        {
            if (i == digits.length())
            {
                res.push_back(tmp);
                return;
            }
            else
            {
                for (const char letter : letters[digits[i] - '0'])
                {
                    tmp.push_back(letter);
                    dfs(i + 1, digits, move(tmp), res);
                    tmp.pop_back();
                }
            }
        }
};