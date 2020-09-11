#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    // int i = distance(vec.begin(), max_element(vec.begin(), vec.end()));
    int i = max_element(vec.begin(), vec.end()) - vec.begin();
    cout << i << endl;

    return 0;
}