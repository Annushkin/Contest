#include <iostream>
#include <string>
#include <vector>
#include <cctype>

int main()
{
    std::string str;
    std::vector<int> stack;
    int x = 0;
    int y = 0;
    bool flag = true;

    std::getline(std::cin, str);

    for (int i = 0; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            x *= 10;
            x += (str[i] - '0');
            flag = true;
        }
        else
        {
            if (str[i] != ' ')
            {
                if (str[i] == '-' and isdigit(str[i + 1])) {
                        y = -1;
                }
                else {
                    int num2 = stack.back();
                    stack.pop_back();
                    int num1 = stack.back();
                    stack.pop_back();

                    if (str[i] == '+') {
                        stack.push_back(num1 + num2);
                        flag = false;
                    }
                    else if (str[i] == '*') {
                        stack.push_back(num1 * num2);
                        flag = false;
                    }
                    else if (str[i] == '/') {
                        stack.push_back(num1 / num2);
                        flag = false;
                    }
                    else if (str[i] == '-' and !isdigit(str[i + 1])){
                        stack.push_back(num1 - num2);
                        flag = false;
                    }
                }
            }
            else if (str[i] == ' ' && flag)
            {
                if (y == -1) {
                    stack.push_back(x * y);
                    x = 0;
                    y = 0;
                }
                else if (y != -1) {
                    stack.push_back(x);
                    x = 0;
                }
            }
        }
    }

    std::cout << stack.back() << '\n';
}
