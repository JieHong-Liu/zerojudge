#include <iostream>
#include <string>
using namespace std;
int string_compare(string s1, string s2);
int main()
{
    int n;
    cin >> n;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cout << string_compare(s[0], s[1]);

    return 0;
}

int string_compare(string s1, string s2)
{
    if (s1[0] != '-' && s2[0] != '-') // IF NON NEGATIVE
    {
        if (s1.length() > s2.length())
        {
            return 1;
        }
        else if (s1.length() < s2.length())
        {
            return -1;
        }
        else // SAME LENGTH
        {
            for (int i = 0; i < s1.length(); i++)
            {
                if (s1[i] > s2[i])
                {
                    return 1;
                }
                else if (s1[i] < s2[i])
                {
                    return -1;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    else if (s1[0] == '-' && s2[0] != '-')
    {
        return -1;
    }
    else if (s1[0] != '-' && s2[0] == '-')
    {
        return 1;
    }
    else // both are negative
    {
    }
    return 0;
}