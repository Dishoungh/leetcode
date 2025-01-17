public class Solution
{
    public string findCommonPrefix(string s1, string s2)
    {
        int s1_length = s1.Length;
        int s2_length = s2.Length;

        for (int i = 0; i < Math.Min(s1_length, s2_length); i++)
        {
            if (s1[i] != s2[i])
            {
                // Cut off base string (s1)
                return s1.Substring(0, i);
            }
        }

        // Default return
        if (s1_length <= s2_length)
        {
            return s1;
        }
        else
        {
            return s2;
        }
    }

    public string divide(string[] strs, int left, int right)
    {
        // Boundary check
        if (left == right)
        {
            return strs[left];
        }
        else
        {
            int middle = (left + right) / 2;
            string ls = divide(strs, left, middle);
            string rs = divide(strs, (middle + 1), right);
            return findCommonPrefix(ls, rs);
        }
    }

    public string LongestCommonPrefix(string[] strs)
    {
        if (strs.Length == 0)
        {
            return "";
        }
        else
        {
           return divide(strs, 0, strs.Length - 1);
        }
    }
}