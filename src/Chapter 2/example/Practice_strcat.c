#include<stdio.h>

int main()
{
    char *filename = __FILE__;
    char filename1[] = "Practice_strcat.c"; // type: char *

    // int *nums = {1, 2, 3}; // cannot init int array this way
    // int nums1[3] = {4, 5, 6};
    // printf("%d\n", *nums1);

    /* sizeof(nums1) return the whole size of the array,
       to get the array's length, must / size(single_elment) */

    // for (int i = 0; i < sizeof(nums1) / sizeof(nums1[0]); i++)

/*     for (int i = 0; i < sizeof(nums1) / sizeof(*nums1); i++)
    {
        printf("%d\n", nums1[i]);
    }
  */  

    // puts(filename);
    // puts(filename1);

    // both filename and filename1 are char*
    // both *filename and *filename1 are char(first item)
    printf("%c\n", *filename); // %s format specifies type char *
    printf("%c\n", *filename1);

    return 0;
}