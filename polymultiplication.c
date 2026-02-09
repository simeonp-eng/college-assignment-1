#include <stdio.h>
struct poly
{
    int coeff;
    int exp;
};
int main()
{
    struct poly p1[20], p2[20], p3[50];
    int n1, n2, n3 = 0;
    int i, j, k;
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n1);
    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n1; i++)
        scanf("%d %d", &p1[i].coeff, &p1[i].exp);
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n2);
    printf("Enter coefficient and exponent:\n");
    for (i = 0; i < n2; i++)
        scanf("%d %d", &p2[i].coeff, &p2[i].exp);
    for (i = 0; i < 50; i++)
    {
        p3[i].coeff = 0;
        p3[i].exp = 0;
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            int newCoeff = p1[i].coeff * p2[j].coeff;
            int newExp = p1[i].exp + p2[j].exp;
            for (k = 0; k < n3; k++)
            {
                if (p3[k].exp == newExp)
                {
                    p3[k].coeff += newCoeff;
                    break;
                }
            }
            if (k == n3)
            {
                p3[n3].coeff = newCoeff;
                p3[n3].exp = newExp;
                n3++;
            }
        }
    }
    printf("\nResultant Polynomial:\n");
    for (i = 0; i < n3; i++)
    {
        if (i != 0 && p3[i].coeff > 0)
            printf("+");
        printf("%dx^%d ", p3[i].coeff, p3[i].exp);
    }
    return 0;
}