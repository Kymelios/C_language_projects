#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPowerOfTwo(int n) {
    bool result;
    for(int i = 0; i < 31; i++)
    {
        if(pow(2, i) == n)
        {
            result = true;
            break;
        }
        result = false;
    }
    return result;
}

int main()
{
    if (isPowerOfTwo(32))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }    

    return 0;
}