#include<stdio.h>
#include<string.h>
// For char array: always allocate 1 more than string.length

void charArray();
void intArray();

int main()
{
    intArray();

    return 0;
}

void charArray() {

    char copy[8];
    char abc[8] = "775";
    char de[8] = "33";
    char fg[8] = "44";
    char g[8] = "\0";
    strcpy(copy, abc);
    int count = 1;

    printf("%p\n", &copy);
    printf("%p\n", &abc);
    printf("%s\n", de);
    printf("%s\n", fg);
    if(fg[2] == g[0]) {
        puts("helloworld");
    }

}

void intArray() {
    int a[3] = {312, 888, 999};
    int b[3] = {2, 3, 4};
    printf("%d\n", b[5]);
}
