#include <iostream>
#include <sstream>
#include <stack>
using namespace std;
using std::stringstream;
// using postfix algorithm.

int weight_calculator(char c);

int main()
{

    stack<char> op;
    string input_str;
    stringstream postfix_str;
    string output_str;
    // clean the stringstream
    postfix_str.str("");
    postfix_str.clear();

    getline(cin, input_str); // read input one line.
    cout << "The size of input string is : " << input_str.length() << '\n';

    for (int i = 0; i < input_str.length(); i++)
    {
        if (input_str.at(i) == ' ')
        {
            continue;
        }
        else if (input_str.at(i) >= '0' && input_str.at(i) <= '9')
        {
            postfix_str << input_str.at(i);
            postfix_str << ' ';
            // cout << input_str.at(i) << " is added into postfix str" << endl;
        }
        else // not ' ' and not 0~9.
        {
            if (input_str.at(i) == '(')
            {
                // cout << "The ( is pushed into the stack!\n";
                op.push(input_str.at(i));
            }
            else if (input_str.at(i) == ')')
            {
                while (op.top() != '(')
                {
                    postfix_str << op.top();
                    op.pop();
                }
                op.pop(); // remove the '('
            }
            else if (op.empty() || weight_calculator(input_str.at(i)) > weight_calculator(op.top()))
            {
                // cout << "The" << input_str.at(i) << "is pushed into the stack!\n";
                op.push(input_str.at(i));
            }
            else if (weight_calculator(input_str.at(i)) <= weight_calculator(op.top()))
            {
                while (weight_calculator(op.top()) > weight_calculator(input_str.at(i)))
                {
                    // cout << op.top() << " is added into postfix str" << endl;
                    postfix_str << op.top();
                    op.pop();
                }
                op.push(input_str.at(i));
                // cout << "The" << input_str.at(i) << "is pushed into the stack!\n";
            }
        }
    }
    while (!op.empty())
    {
        postfix_str << op.top();
        op.pop();
    }
    while (postfix_str)
    {
        string tmp_str = "";
        postfix_str >> tmp_str;
        output_str = output_str + " " + tmp_str;
    }
    cout << "the output : " << output_str << endl;

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
