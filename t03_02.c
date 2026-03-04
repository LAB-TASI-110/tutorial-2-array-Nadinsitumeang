#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk FLT_MAX atau DBL_MAX
#include <math.h>   // Untuk fmin (opsional, bisa manual)

int main() {
    int n;
    // Membaca bilangan bulat positif n
    scanf("%d", &n);

    if (n <= 0) {
        // Handle kasus n tidak valid, meskipun prompt tidak secara eksplisit memintanya
        // Sesuai prompt yang menyatakan n adalah bilangan bulat positif.
        return 1; // Keluar dengan kode error
    }

    int current_val;
    int min_val = INT_MAX;
    int max_val = INT_MIN;

    // Untuk menghitung rata-rata terendah dari dua nilai berturut-turut
    // Inisialisasi dengan nilai yang sangat besar
    double lowest_consecutive_avg = DBL_MAX;
    int prev_val; // Untuk menyimpan nilai sebelumnya

    // Loop untuk membaca n baris masukan berikutnya
    for (int i = 0; i < n; i++) {
        scanf("%d", &current_val);

        // Update nilai minimum dan maksimum
        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }

        // Hitung rata-rata terendah dari dua nilai berturut-turut
        if (i > 0) { // Mulai dari elemen kedua untuk bisa membentuk pasangan
            double current_avg = (double)(prev_val + current_val) / 2.0;
            if (current_avg < lowest_consecutive_avg) {
                lowest_consecutive_avg = current_avg;
            }
        }
        prev_val = current_val; // Simpan nilai saat ini untuk iterasi berikutnya
    }

    // Menghasilkan keluaran
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    // Mencetak rata-rata dengan 2 digit presisi
    printf("%.2f\n", lowest_consecutive_avg);

    return 0; // Program berhasil dijalankan
}
