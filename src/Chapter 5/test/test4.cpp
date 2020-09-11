#include <iostream>
#include <algorithm>
#include <string>
#include <My_Util_Cpp.h>

using namespace std;

int main()
{
    string filename(__FILE__);
    cout << filename << "\n";
    
    // the address of the following is different
    // printf("filename's address=%p\n", &filename);
    // printf("__FILE__'s address=%p\n", &__FILE__);
    // scanf("%d\n", &n);
    // cout << "n=" << n << "\n";
    return 0;
}