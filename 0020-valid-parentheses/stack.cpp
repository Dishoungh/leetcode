#include <stack>

class Solution
{
    public:
        bool isValid(string s)
        {
            // Initialize stack
            stack<char> st;

            for (int i = 0; i < s.length(); i++)
            {
                if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
                {
                    st.push(s[i]);
                }
                else
                {
                    if (st.empty()) // Error case: Got a closing bracket when stack is empty
                    {
                        return false;
                    }
                    else if ((s[i] == ')') && (st.top() == '('))
                    {
                        st.pop();
                    }
                    else if ((s[i] == '}') && (st.top() == '{'))
                    {
                        st.pop();
                    }
                    else if ((s[i] == ']') && (st.top() == '['))
                    {
                        st.pop();
                    }
                    else // Other invalid case
                    {
                        return false;
                    }
                }
            }

            return st.empty();
        }
};