#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n = 1;
    int young_index = 0, old_index = 0;

    cin >> n;

    vector<string> name(n);
    vector<int> day(n);
    vector<int> month(n);
    vector<int> year(n);

    for (int i = 0; i < n; i++)
    {
        cin >> name[i] >> day[i] >> month[i] >> year[i];
    }

    for (int i = 1; i < n; i++)
    {
        if (year[young_index] < year[i])
        {
            young_index = i;
        }
        else if(year[young_index] > year[i])
        {
        }
        else
        {
            int a = month[young_index] * 100 + day[young_index];
            int b = month[i] * 100 + day[i];

            if (a < b)
            {
                young_index = i;
            }
            else
            {  
            }
        }

        if (year[old_index] > year[i])
        {
            old_index = i;
        }
        else if (year[old_index] < year[i])
        {
        }
        else
        {
            int a = month[old_index] * 100 + day[old_index];
            int b = month[i] * 100 + day[i];

            if (a > b)
            {
                old_index = i;
            }
            else
            { 
            }
        }
    }

    cout << name[young_index] << endl;
    cout << name[old_index] << endl;

    return 0;
}