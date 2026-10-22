/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main() {
    FILE *fp;
    int a[] = {0, 1, 2}; // []宣告陣列
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};
    
    // 1. 寫入模式開啟檔案
    fp = fopen("a.bin", "wb");
    if (fp == NULL) {
        printf("無法開啟檔案進行寫入\n");
        return 1;
    }
    
    fwrite(a, sizeof(a), 1, fp);
    fwrite(b, sizeof(b), 1, fp);
    fwrite(c, sizeof(c), 1, fp);
    
    // 寫完後必須先關閉檔案
    fclose(fp); 
    
    int ra[3];
    char rb[4] = {0}; // 初始化字串陣列，確保結尾有 \0
    float rc[3];
    
    // 2. 讀取模式重新開啟檔案
    fp = fopen("a.bin", "rb");
    if (fp == NULL) {
        printf("無法開啟檔案進行讀取\n");
        return 1;
    }
    
    fread(ra, sizeof(ra), 1, fp);
    fread(rb, sizeof(rb), 1, fp);
    fread(rc, sizeof(rc), 1, fp);
    
    // 讀取完後關閉檔案
    fclose(fp);
    
    // 3. 印出結果（int 陣列必須用 %d，而不是 %f）
    for(int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");
    
    printf("%s\n", rb);
    
    for(int i = 0; i < 3; i++) {
        printf("%f ", rc[i]);
    }
    printf("\n");

    return 0;
}
