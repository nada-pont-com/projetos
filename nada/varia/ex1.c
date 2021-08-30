#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i <= 255; i++){
        char a  = i;
        printf("numb: %d, %c\n",a,a);
    }
    return 0;
}
