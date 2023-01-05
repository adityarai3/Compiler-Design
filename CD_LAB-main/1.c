// SYMBOL TABLE MANANGEMENT


#include <stdio.h>
#include <string.h>
int main()
{
    char a[20];
    scanf("%s", a);
    int l = strlen(a);
    int i, c = 0, j;
    printf("SYMBOL\t   TYPE\t   ADDRESS\n");
    for (i = 0; i < l; i++)
    {
        if (a[i] >= 48 && a[i] <= 57)
        {
            if (a[i + 1] >= 48 && a[i + 1] <= 57)
            {
                printf("%c%c\tCONSTANT\t%d", a[i], a[i + 1], &a[i]);
                printf("\n");
                i += 1;
                continue;
            }
            else
            {
                printf("%c\tCONSTANT\t%d", a[i], &a[i]);
                printf("\n");
            }
        }
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '=')
        {
            printf("%c\tOPERATOR\t%d", a[i], &a[i]);
        }
        else if (a[i] > 57)
            printf("%c\tIDENTIFIER\t%d", a[i], &a[i]);
        printf("\n");
    }
}