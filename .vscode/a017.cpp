#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;
using std::stringstream;
// using postfix algorithm.

int weight_calculator(char c);

int main()
{

    stack<char> op;
    stack<int> result_stack;
    queue<string> postfix_queue;

    string input_str;
    string output_str;
    string token;

    while (getline(cin, input_str))
    {
        istringstream iss(input_str);
        while (iss >> token)
        {
            // 對 token 進行解析
            if (weight_calculator(token[0]) == -1) // not operator
            {
                postfix_queue.push(token);
            }
            else // is operator.
            {
                if (token[0] == '(')
                {
                    op.push(token[0]); // push '(' into the stack.
                }
                else if (token[0] == ')')
                {
                    while (op.top() != '(')
                    {
                        string tmp_str(1, op.top());
                        postfix_queue.push(tmp_str);
                        op.pop();
                    }
                    op.pop(); // remove the '('
                }
                else if (op.empty() || weight_calculator(token[0]) > weight_calculator(op.top()))
                {
                    // cout << "The" << input_str.at(i) << "is pushed into the stack!\n";
                    op.push(token[0]);
                }
                else if (weight_calculator(token[0]) <= weight_calculator(op.top()))
                {
                    while (!op.empty() && (weight_calculator(op.top()) >= weight_calculator(token[0])))
                    {
                        // cout << op.top() << " is added into postfix str" << endl;
                        string tmp_str(1, op.top());
                        postfix_queue.push(tmp_str);
                        op.pop();
                    }
                    op.push(token[0]);
                    // cout << "The" << input_str.at(i) << "is pushed into the stack!\n";
                }
            }
        }
        while (!op.empty())
        {
            string tmp_str(1, op.top());
            postfix_queue.push(tmp_str);
            op.pop();
        } // when the program runs here, the queue should be ready to analyze.

        while (!postfix_queue.empty())
        {
            // cout << postfix_queue.front() << " ";
            if (weight_calculator(postfix_queue.front()[0]) == -1) // not operator -> a number.
            {
                istringstream iss(postfix_queue.front());
                long long int value;
                iss >> value;
                result_stack.push(value); // push the value into the stack.
            }
            else // met operator.
            {
                int tmp_left, tmp_right;
                tmp_right = result_stack.top();
                result_stack.pop();
                tmp_left = result_stack.top();
                result_stack.pop();
                int result = 0;
                switch (postfix_queue.front()[0])
                {
                case '+':
                    result = tmp_left + tmp_right;
                    break;
                case '-':
                    result = tmp_left - tmp_right;
                    break;
                case '*':
                    result = tmp_left * tmp_right;
                    break;
                case '/':
                    result = tmp_left / tmp_right;
                    break;
                case '%':
                    result = tmp_left % tmp_right;
                    break;
                default:
                    result = 0;
                    break;
                }
                result_stack.push(result); // push the result back to the stack.
            }
            postfix_queue.pop();
        }
        cout << result_stack.top() << endl;
    }

    return 0;
}

int weight_calculator(char c)
{
    char priority[7] = {'+', '-', '*', '/', '%', '(', ')'};
    int weight[7] = {1, 1, 2, 2, 2, 0, 0};

    for (int i = 0; i < 7; i++)
    {
        if (c == priority[i])
        {
            return weight[i];
        }
    }
    return -1; // not found.
}