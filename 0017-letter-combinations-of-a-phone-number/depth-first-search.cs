public class Solution
{
    public void dfs(int idx, string digits, string[] map, StringBuilder tmp, IList<string> res)
    {
        if (idx == digits.Length)
        {
            res.Add(tmp.ToString());
            return;
        }
        else
        {
            var mapIndex = digits[idx] - '0';
            var letters = map[mapIndex];
            for (int i = 0; i < letters.Length; i++)
            {
                //Append character to combination
                tmp.Append(letters[i]);

                // Recursively call Depth First Search
                dfs(idx + 1, digits, map, tmp, res);

                // Remove last character from combination for backtracking
                tmp.Remove(tmp.Length - 1, 1);
            }
        }
    }

    public IList<string> LetterCombinations(string digits)
    {
        IList<string> result = new List<string>();
        var letters = new string[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        var builder = new StringBuilder();

        if (digits.Length != 0)
        {
            dfs(0, digits, letters, builder, result);
        }

        return result;
    }
}