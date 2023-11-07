#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int)); // Membuat array dinamis

    if (arr == NULL) {
        fprintf(stderr, "Gagal mengalokasikan memori");
        return 1; // Menghentikan program dengan kode kesalahan
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("%d\n", sum); // Mencetak hasil jumlah

    free(arr); // Membebaskan memori yang dialokasikan

    return 0;
}
