#include <stdio.h>
int main()
{
    int S[50][3], T[50][3];
    int rows, cols, nonZero;
    int i, j, k = 1;
    printf("Enter number of rows, columns and non-zero elements: ");
    scanf("%d %d %d", &rows, &cols, &nonZero);
    S[0][0] = rows;
    S[0][1] = cols;
    S[0][2] = nonZero;
    printf("Enter row, column and value for each non-zero element:\n");
    for (i = 1; i <= nonZero; i++)
    {
        scanf("%d %d %d", &S[i][0], &S[i][1], &S[i][2]);
    }
    T[0][0] = S[0][1];
    T[0][1] = S[0][0];
    T[0][2] = S[0][2];
    for (i = 0; i < cols; i++)
    {
        for (j = 1; j <= nonZero; j++)
        {
            if (S[j][1] == i)
            {
                T[k][0] = S[j][1];
                T[k][1] = S[j][0];
                T[k][2] = S[j][2];
                k++;
            }
        }
    }
    printf("\nTranspose Sparse Matrix:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= nonZero; i++)
    {
        printf("%d\t%d\t%d\n", T[i][0], T[i][1], T[i][2]);
    }
    return 0;
}