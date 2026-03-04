#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int input_val;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    printf("Masukkan jumlah baris data (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input jumlah baris tidak valid. Harap masukkan bilangan bulat positif.\n");
        return 1;
    }

    printf("Masukkan %d bilangan bulat (rentang -100 sampai 100):\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &input_val) != 1) {
            printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
            return 1;
        }
        
        if (input_val < min_val) {
            min_val = input_val;
        }
        if (input_val > max_val) {
            max_val = input_val;
        }
    }

    printf("\nOutput:\n");
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0;
}
