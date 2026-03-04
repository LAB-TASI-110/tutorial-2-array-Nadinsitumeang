#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    int input_val;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    // Membaca jumlah baris data (n)
    scanf("%d", &n);

    // Membaca n bilangan bulat dan mencari nilai min/max
    for (int i = 0; i < n; i++) {
        scanf("%d", &input_val);
        
        if (input_val < min_val) {
            min_val = input_val;
        }
        if (input_val > max_val) {
            max_val = input_val;
        }
    }

    // Output nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0;
}
