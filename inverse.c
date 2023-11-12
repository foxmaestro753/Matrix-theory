#include <stdio.h>
#include <math.h>

void matrixmult(int n, double array1[][n], double array2[][n], double array3[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array3[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                array3[i][j] += (array1[i][k] * array2[k][j]);
            }
        }
    }
}

int main()
{
    int a;
    printf("Order: ");
    scanf("%d", &a);

    double matrix[a][a];
    double identity[a][a];
    double transform[a][a];
    double product1[a][a];
    double product2[a][a];
    double e;

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (i == j)
            {
                transform[i][j] = 1;
            }
            else
            {
                transform[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (i == j)
            {
                identity[i][j] = 1;
            }
            else
            {
                identity[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        if (matrix[i][i] == 0)
        {
            double sum = 0, t = 0;
            for (int q = 0; q < a; q++)
            {
                sum += pow(matrix[q][i], 2);
            }
            if (sum == 0)
            {
                continue;
            }
            for (int p = 0; p < a; p++)
            {
                if (matrix[p][i] != 0)
                {
                    for (int j = 0; j < a; j++)
                    {
                        double a, b;
                        a = matrix[p][j];
                        matrix[p][j] = matrix[i][j];
                        matrix[i][j] = a;
                        b = identity[p][j];
                        identity[p][j] = identity[i][j];
                        identity[i][j] = b;
                        t = 1;
                    }

                    if (t == 1)
                    {
                        break;
                    }
                }
            }
        }

        if (matrix[i][i] != 1)
        {
            e = matrix[i][i];
            for (int p = 0; p < a; p++)
            {
                matrix[i][p] = matrix[i][p] / e;
                identity[i][p] = identity[i][p] / e;
            }
        }

        for (int j = 0; j < a; j++)
        {
            if (j != i)
            {
                transform[j][i] = -matrix[j][i];
            }
        }

        matrixmult(a, transform, matrix, product1);
        matrixmult(a, transform, identity, product2);

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (i == j)
                {
                    transform[i][j] = 1;
                }
                else
                {
                    transform[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                matrix[i][j] = product1[i][j];
            }
        }

        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                identity[i][j] = product2[i][j];
            }
        }
    }

    double r = 1;

    for (int i = 0; i < a; i++)
    {
        if (matrix[i][i] == 1)
        {
            r *= 1;
        }
        else
        {
            r *= 0;
        }
    }

    if (r == 1)
    {
        printf("\nInverse Matrix : \n");
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < a; j++)
            {
                printf("%0.10lf ", identity[i][j]);
            }
            printf("\n");
        }
    }

    if (r == 0)
    {
        printf("Inverse of the given matrix does't exist");
    }
}