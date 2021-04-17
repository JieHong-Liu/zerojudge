#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    int num,leave_sure=0; 
    while(!leave_sure)
    {
        cin >> num; // numbers of the train carriage.
        if(num == 0)
        {
            break;
        }
        stack<int>* middle = new stack<int>[num];
        queue<int>* right = new queue<int>[num];
        for (int i = 1 ; i <= num ; i++)
        {
            right->push(i); 
        }
        // cout << (right->front()) << endl;
        // right->pop();// pop is to remove the first element.

        int *left = new int[num];
        int leave = 0;
        while(!leave)
        {   
            // initialize the queue and stack.
            while(!right->empty())
            {
                right->pop();
            }
            for (int i = 1 ; i <= num ; i++)
            {
                right->push(i); 
            }
            while(!middle->empty())
            {
                middle->pop();
            }
            int yes = 1;
            
            for (int i = 0 ; i < num ; i++)
            {
                cin >> left[i];
                if(left[0] == 0)
                {
                    leave = 1;
                    break;
                }
                if(middle->empty() == false && left[i] == middle->top() )
                {
                    middle->pop();
                }
                else // means that the value is not in the middle station.
                {
                    while(right->empty() == false && left[i] != right->front() )
                    {
                        middle->push(right->front());
                        // put the front element of the right into the middle stack.
                        right->pop(); // then remove it.
                    }
                    if(right->empty() == true) // can't found in the right and the middle.
                    {
                        yes = 0;
                        break;
                    }
                    if(left[i] == right->front()) // found the right carriage.
                    {
                        right->pop();
                    }
                }
            }
            if(left[0] != 0)
            {
                if(yes == 1)
                {
                    cout << "Yes" << endl;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
            else
            {
                break;
            }
        }
    }
    

    
    

    return 0;
}