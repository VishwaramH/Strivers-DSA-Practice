#include <stdio.h>

int main()
{
    int n, q;
    int hash[27] = {0};
    scanf("%d", &n);
    char val[n];
    scanf("%s", &val);
    for (int i = 0; i < n; i++)
    {
        hash[val[i] - 'a'] += 1;
    }
    printf("Enter query length\n");
    scanf("%d", &q);
    int res[q];
    for (int j = 0; j < q; j++)
    {
        char inp;
        scanf(" %c", &inp);
        res[j] = hash[inp - 'a'];
    }

    for (int k = 0; k < sizeof(res) / sizeof(res[0]); k++)
    {
        printf("%d ", res[k]);
    }
    return 0;
}