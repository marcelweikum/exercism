#include "matching_brackets.h"

#include <stack>

namespace matching_brackets
{

    bool check(const std::string sentence)
    {
        std::stack<char> stack;

        for (char c : sentence)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.push(c);
            }
            else if (c == ')' || c == ']' || c == '}')
            {
                if (stack.empty())
                    return false;

                char open = stack.top();
                if ((open == '(' && c == ')') ||
                    (open == '[' && c == ']') ||
                    (open == '{' && c == '}'))
                {
                    stack.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return stack.empty();
    }

} // namespace matching_brackets
