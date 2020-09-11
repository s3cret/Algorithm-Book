#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }

    cout << vec.size() << endl;

    vec.erase(vec.begin(), vec.begin() + 1);

    cout << vec.size() << endl;

    return 0;
}