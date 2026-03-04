#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        return 1;
    }

    int current_val;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    double lowest_consecutive_avg = DBL_MAX;
    int prev_val;

    for (int i = 0; i < n; i++) {
        scanf("%d", &current_val);

        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }

        if (i > 0) {
            double current_avg = (double)(prev_val + current_val) / 2.0;
            if (current_avg < lowest_consecutive_avg) {
                lowest_consecutive_avg = current_avg;
            }
        }
        prev_val = current_val;
    }

    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", lowest_consecutive_avg);

    return 0;
}
