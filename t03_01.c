#include <stdio.h>
#include <limits.h> // Untuk INT_MAX dan INT_MIN

int main() {
    int n;
    int input_val;
    int min_val = INT_MAX; // Inisialisasi dengan nilai maksimum integer
    int max_val = INT_MIN; // Inisialisasi dengan nilai minimum integer

    // Membaca baris pertama sebagai jumlah 'n' baris masukan berikutnya
    // Jika ada contoh input 8 di awal untuk n, maka input_val pertama akan membaca 8, bukan n.
    // Asumsi: Baris pertama adalah N, baris kedua juga N (jumlah input yang sebenarnya), dan sisanya adalah data.
    // Berdasarkan contoh input: "8" (untuk n) dan "8" (untuk nilai pertama), saya akan mengasumsikan
    // bahwa N baris input tidak termasuk N itu sendiri. Jadi, total N+1 baris dibaca.
    // Jika baris pertama adalah N, dan contoh input yang diberikan adalah:
    // 8 (ini N)
    // 8 (ini input ke-1)
    // -3 (ini input ke-2)
    // ...
    // -7 (ini input ke-8)
    // Maka N yang dimaksud di sini adalah 8, dan akan ada 8 input berikutnya.

    printf("Masukkan jumlah baris data (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input jumlah baris tidak valid. Harap masukkan bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }

    printf("Masukkan %d bilangan bulat (rentang -100 sampai 100):\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &input_val) != 1) {
            printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
            return 1; // Keluar dengan kode error
        }
        
        // Asumsi: Meskipun rentang diberikan (-100 sampai 100), tidak ada validasi eksplisit diminta
        // Namun, saya akan tetap memprosesnya sesuai spesifikasi min/max umum.
        // Jika diminta validasi rentang, kode berikut bisa ditambahkan:
        /*
        if (input_val < -100 || input_val > 100) {
            printf("Input di luar rentang -100 hingga 100. Mengabaikan nilai ini.\n");
            // Atau bisa juga return 1 untuk error
            continue; 
        }
        */

        if (input_val < min_val) {
            min_val = input_val;
        }
        if (input_val > max_val) {
            max_val = input_val;
        }
    }

    printf("\nOutput:\n");
    printf("%d\n", min_val); // Output nilai terkecil
    printf("%d\n", max_val); // Output nilai terbesar

    return 0; // Program berakhir dengan sukses
}
