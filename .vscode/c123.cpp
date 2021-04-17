#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    int num; 
    cin >> num; // numbers of the train carriage.
    stack<int>* middle = new stack<int>[num];
    
    queue<int>* right = new queue<int>[num];
    for (int i = 1 ; i <= num ; i++)
    {
        right->push(i); 
    }
    // cout << (right->front()) << endl;
    // right->pop();// pop is to remove the first element.

    int *left = new int[num];


    int index_of_carriage;
    while(true)
    {
        index_of_carriage = 0;
        cin >> left[index_of_carriage];
        if(left[0] == 0)
        {
            break;
        }
        else
        {
            for (int i = 1 ; i < num ; i++)
            {
                cin >> left[i];
            }
        }
    }

    
    

    return 0;
}