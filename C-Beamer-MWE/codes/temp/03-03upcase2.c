#include <stdio.h>
int main()
{
    char  ch = 'b';
    ch = 'b' - ('a' - 'A') ;
    printf("%c, %d\n", ch, ch);

    return 0;
}
