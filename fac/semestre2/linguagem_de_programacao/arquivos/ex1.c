#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivo = fopen("texto.txt", "w");
    if (arquivo != NULL)
    {
        int l = 0, c = 0;
        printf("digite o numero de linhas da matriz: ");
        scanf("%d", &l);
        printf("digite o numero de colunas da matriz: ");
        scanf("%d", &c);
        fprintf(arquivo, "%d %d\n", l, c);
        for (int i = 0; i < l; i++)
        {
            for (int i2 = 0; i2 < c; i2++)
            {
                int n = 0;
                printf("digite o numero da linha %d, coluna %d: ", i, i2);
                scanf("%d", &n);
                fprintf(arquivo, "%d", n);
                if (i2 != c - 1)
                    fprintf(arquivo, "    ");
            }
            if (i != l - 1)
                fprintf(arquivo, "\n");
        }
        fclose(arquivo);

        FILE *arquivo = fopen("texto.txt", "r");
        if (arquivo != NULL)
        {
            fscanf(arquivo, "%d", &l);
            fscanf(arquivo, "%d", &c);
            int matriz[l][c];
            int i = 0, i2 = 0;
            while (!(feof(arquivo)))
            {
                printf("%d",feof(arquivo));
                fscanf(arquivo, "%d", &matriz[i][i2]);
                i++;
                if (i == c)
                {
                    i = 0;
                    i2++;
                }
            }
            fclose(arquivo);
            FILE *arquivo = fopen("texto2.txt", "w");
            for (int i = 0; i < c; i++)
            {
                for (int i2 = 0; i2 < l; i2++)
                {
                    fprintf(arquivo, "%d", matriz[i][i2]);
                    if (i2 != l - 1)
                        fprintf(arquivo, "    ");
                }
                if (i != c - 1)
                    fprintf(arquivo, "\n");
            }
        }
        else
        {
            printf("deu ruim 2!");
        }
    }
    else
    {
        printf("deu ruim!");
    }
}