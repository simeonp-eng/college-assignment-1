#include <stdio.h>
int main()
{
    int A[50][3], B[50][3], C[50][3];
    int i = 1, j = 1, k = 1;
    int rows, cols, n1, n2;
    printf("Enter rows, columns and number of non-zero elements of Matrix A: ");
    scanf("%d %d %d", &rows, &cols, &n1);
    A[0][0] = rows;
    A[0][1] = cols;
    A[0][2] = n1;
    printf("Enter row, column and value for Matrix A:\n");
    for (i = 1; i <= n1; i++)
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    printf("Enter number of non-zero elements of Matrix B: ");
    scanf("%d", &n2);
    B[0][0] = rows;
    B[0][1] = cols;
    B[0][2] = n2;
    printf("Enter row, column and value for Matrix B:\n");
    for (j = 1; j <= n2; j++)
        scanf("%d %d %d", &B[j][0], &B[j][1], &B[j][2]);
    C[0][0] = rows;
    C[0][1] = cols;
    i = j = 1;
    while (i <= n1 && j <= n2)
    {
        if (A[i][0] < B[j][0] ||
           (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
        }
        else if (B[j][0] < A[i][0] ||
                (A[i][0] == B[j][0] && B[j][1] < A[i][1]))
        {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
        }
        else
        {
            int sum = A[i][2] + B[j][2];
            if (sum != 0)
            {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++;
            j++;
            continue;
        }
        k++;
    }
    while (i <= n1)
    {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }
    while (j <= n2)
    {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }
    C[0][2] = k - 1;
    printf("\nResultant Sparse Matrix after Addition:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= C[0][2]; i++)
        printf("%d\t%d\t%d\n", C[i][0], C[i][1], C[i][2]);

    return 0;
}