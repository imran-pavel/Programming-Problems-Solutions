#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int i, NCases, salary1, salary2, salary3;

    cin >> NCases;
    for(i=0; i<NCases; i++)
    {
        cin >> salary1 >> salary2 >> salary3;

        if(salary1 > salary2)
        {
            if(salary1 > salary3)
            {
                if(salary2 > salary3)
                {
                    cout << "Case " << i+1 << ": " << salary2 << endl;
                }
                else if(salary2 < salary3)
                {
                    cout << "Case " << i+1 << ": " << salary3 << endl;
                }
                else
                {
                    cout << "Case " << i+1 << ": " << salary2 << endl;
                }
            }
            else if(salary1 < salary3)
            {
                cout << "Case " << i+1 << ": " << salary1 << endl;
            }
            else
            {
                cout << "Case " << i+1 << ": " << salary1 << endl;
            }
        }
        else if(salary1 < salary2)
        {
            if(salary1 > salary3)
            {
                cout << "Case " << i+1 << ": " << salary1 << endl;
            }
            else if(salary1 < salary3)
            {
                if(salary2 > salary3)
                {
                    cout << "Case " << i+1 << ": " << salary3 << endl;
                }
                else if(salary2 < salary3)
                {
                    cout << "Case " << i+1 << ": " << salary2 << endl;
                }
                else
                {
                    cout << "Case " << i+1 << ": " << salary2 << endl;
                }
            }
            else
            {
                cout << "Case " << i+1 << ": " << salary1 << endl;
            }
        }
        else
        {
            cout << "Case " << i+1 << ": " << salary1 << endl;
        }
    }
    return 0;
}
