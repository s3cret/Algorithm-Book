#include <iostream>
// #include <string>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    stack<string> s;
    s.push("helloworld");
    cout << s.top() << endl;
    cout << s.size() << endl;
    string a = s.top();
    s.pop();
    cout << a << endl;
    cout << s.empty() << endl;
    cout << s.size() << endl;


    return 0;
}