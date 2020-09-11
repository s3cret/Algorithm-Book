#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string read_data()
{
    string tmp;
    char c;
    while ((c = getchar()) && c != ',' && c != '\n')
    {
        tmp += c;
    }
    return tmp;
}

int main()
{
    cout << read_data() << endl;

    return 0;
}
