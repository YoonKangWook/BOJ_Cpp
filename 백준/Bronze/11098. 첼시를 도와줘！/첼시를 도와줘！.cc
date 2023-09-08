#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, p = 1;
    
    cin >> n;

    vector<string> selectPlayer(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p;

        vector<int> price(p);
        vector<string> name(p);

        for (int j = 0; j < p; j++)
        {
            int playerPrice = 0;
            string playerName;

            cin >> playerPrice >> playerName;

            price[j] = playerPrice;
            name[j] = playerName;
        }

        int max_index = max_element(price.begin(), price.end()) - price.begin();
            
        selectPlayer[i] = name[max_index];

        price.clear();
        name.clear();
    }
    
    for (string name : selectPlayer)
    {
        cout << name << endl;
    }

    return 0;
}
