#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SETS 5
#define NUMS     7
#define MAX_NUM  69

int is_used(int arr[], int count, int num) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

void make_one_set(int set[]) {
    int count = 0;
    while (count < NUMS) {
        int num = rand() % MAX_NUM + 1;
        if (!is_used(set, count, num)) {
            set[count] = num;
            count++;
        }
    }

    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - 1 - i; j++) {
            if (set[j] > set[j + 1]) {
                int tmp = set[j];
                set[j] = set[j + 1];
                set[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    int n;
    int lotto[MAX_SETS][NUMS];

    srand((unsigned) time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SETS) {
        printf("只能購買 1 ~ 5 組喔！\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        make_one_set(lotto[i]);
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt\n");
        return 1;
    }

    time_t now = time(NULL);
    char date[64];
    strftime(date, sizeof(date), "%a %b %e %H:%M:%S %Y", localtime(&now));

    fprintf(fp, "======== lotto649 ========\n");
    fprintf(fp, "= %s =\n", date);

    for (int i = 0; i < MAX_SETS; i++) {
        fprintf(fp, "[%d]:", i + 1);
        for (int j = 0; j < NUMS; j++) {
            if (i < n) {
                fprintf(fp, " %02d", lotto[i][j]);
            } else {
                fprintf(fp, " --");
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "======== csie@CGU ========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
