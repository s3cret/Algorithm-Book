#include <stdio.h> 
  
// This function swaps values referred by  
// x and y, 
void swap(int &x, int &y) 
{ 
    int temp = x; 
    x = y; 
    y = temp; 
} 
  
int main() 
{ 
    int x, y; 
    scanf("%d", &x); 
    scanf("%d", &y); 
    swap(x, y); 
    printf("\nAfter Swapping: x = %d, y = %d", x, y); 
    return 0; 
} 