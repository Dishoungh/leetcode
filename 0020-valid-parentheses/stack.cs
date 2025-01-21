using System;
using System.Collections;

public class Solution
{
    public bool IsValid(string s)
    {
        // Initialize stack
        Stack<char> st = new Stack<char>();

        for (int i = 0; i < s.Length; i++)
        {
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
            {
                st.Push(s[i]);
            }
            else
            {
                if (st.Count == 0) // Error case: Got a closing bracket when stack is empty
                {
                    return false;
                }
                else if ((s[i] == ')') && (st.Peek() == '('))
                {
                    st.Pop();
                }
                else if ((s[i] == '}') && (st.Peek() == '{'))
                {
                    st.Pop();
                }
                else if ((s[i] == ']') && (st.Peek() == '['))
                {
                    st.Pop();
                }
                else // Other invalid case
                {
                    return false;
                }
            }
        }

        return (st.Count == 0);
    }
}