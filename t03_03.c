#include <stdio.h>
#include <stdlib.h> // Untuk fungsi abs() jika diperlukan, tapi untuk min/max tidak terlalu relevan di sini.
#include <limits.h> // Untuk INT_MAX dan INT_MIN
#include <float.h>  // Untuk FLT_MAX dan FLT_MIN (tidak dipakai, tapi bagus untuk tahu)

int main() {
    int n;
    scanf("%d", &n); // Membaca jumlah baris masukan berikutnya (n)

    int current_num;
    int min_val = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_val = INT_MIN; // Inisialisasi dengan nilai minimum integer

    // Variabel untuk perhitungan rata-rata
    double min_avg_consecutive = 101.0; // Maksimum rata-rata bisa (100+100)/2 = 100.0, jadi 101.0 adalah nilai yang aman untuk inisialisasi mencari minimum.
    double max_avg_consecutive = -101.0; // Minimum rata-rata bisa (-100-100)/2 = -100.0, jadi -101.0 adalah nilai yang aman untuk inisialisasi mencari maksimum.
    
    int prev_num = 0; // Untuk menyimpan nilai sebelumnya, diinisialisasi untuk kondisi awal loop.

    for (int i = 0; i < n; i++) {
        scanf("%d", &current_num); // Membaca setiap bilangan bulat

        // Update nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Hitung rata-rata dua nilai berturut-turut (dimulai dari elemen kedua)
        if (i > 0) { // Pastikan sudah ada prev_num
            double current_avg = (double)(prev_num + current_num) / 2.0;

            // Update rata-rata terendah dari dua nilai berturut-turut
            if (current_avg < min_avg_consecutive) {
                min_avg_consecutive = current_avg;
            }
            // Update rata-rata tertinggi dari dua nilai berturut-turut
            if (current_avg > max_avg_consecutive) {
                max_avg_consecutive = current_avg;
            }
        }
        
        prev_num = current_num; // Simpan nilai saat ini untuk iterasi berikutnya
    }

    // Menampilkan output sesuai format
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", min_avg_consecutive);
    printf("%.2f\n", max_avg_consecutive);

    return 0;
}
