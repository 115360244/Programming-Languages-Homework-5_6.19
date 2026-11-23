#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROLLS 36000

int main(void)
{
    int face1;
    int face2;
    int sum;
    int frequency[13] = { 0 };
    int i;

    int expected[13] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1 };

    srand(time(0));

    for (i = 1; i <= ROLLS; i++)
    {
        face1 = 1 + rand() % 6;
        face2 = 1 + rand() % 6;
        sum = face1 + face2;
        frequency[sum]++;
    }

    printf("%s%12s%12s%12s\n", "點數總和", "出現次數", "實際比例", "理論比例");

    for (sum = 2; sum <= 12; sum++)
    {
        printf("%8d%12d%11.3f%%%11.3f%%\n",
            sum,
            frequency[sum],
            (double)frequency[sum] / ROLLS * 100,
            (double)expected[sum] / 36 * 100);
    }

    system("pause");
    return 0;
}