#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int current_num;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    double min_avg_consecutive = 101.0;
    double max_avg_consecutive = -101.0;
    
    int prev_num;

    if (n > 0) {
        scanf("%d", &prev_num);
        min_val = prev_num;
        max_val = prev_num;
    }

    for (int i = 1; i < n; i++) {
        scanf("%d", &current_num);

        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        double current_avg = (double)(prev_num + current_num) / 2.0;

        if (current_avg < min_avg_consecutive) {
            min_avg_consecutive = current_avg;
        }
        if (current_avg > max_avg_consecutive) {
            max_avg_consecutive = current_avg;
        }
        
        prev_num = current_num;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    
    if (n >= 2) {
        printf("%.2f\n", min_avg_consecutive);
        printf("%.2f\n", max_avg_consecutive);
    }

    return 0;
}
