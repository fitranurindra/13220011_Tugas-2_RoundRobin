// Nama     : Fitra Nurindra
// NIM      : 13220011
// Jurusan  : Teknik Elektro
// Tugas 2 Program Round Robin Menggunakan Bahasa C

#include<stdio.h>
 
int main()
{
      int i, n_proses, counter = 0, x, total = 0, w_kuantum;
      int w_tunggu = 0, w_proses = 0, w_datang[10], w_eksekusi[10], temp[10];             // Define dan Inisialisasi Variabel
      float avg_w_tunggu, avg_w_proses;
      printf("\nMasukkan Jumlah Proses: ");
      scanf("%d", &n_proses);                               // User menginput jumlah proses yang akan dilakukan
      x = n_proses;
      for(i = 0; i < n_proses; i++)                         
      {
            printf("\nProses P[%d]\n", i);
 
            printf("Waktu Kedatangan :\t");
 
            scanf("%d", &w_datang[i]);                      // User menginput waktu kedatangan untuk setiap proses
 
            printf("Waktu Eksekusi:\t\t");
 
            scanf("%d", &w_eksekusi[i]);                    // User menginput waktu eksekusi untuk setiap proses
 
            temp[i] = w_eksekusi[i];                        // Mengisi array temp dengan nilai waktu eksekusi
      }
 
      printf("\nMasukkan Waktu Kuantum: ");
      scanf("%d", &w_kuantum);                              // User menginput waktu kuantum yang digunakan
      printf("\nProses\tWaktu Kedatangan\tWaktu Eksekusi\tWaktu Selesai\tWaktu Proses\tWaktu Tunggu\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= w_kuantum && temp[i] > 0)         // Jika waktu eksekusinya kurang dari waktu kuantum
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)                            // Jika waktu eksekusinya lebih dari waktu kuantum
            {
                  temp[i] = temp[i] - w_kuantum;
                  total = total + w_kuantum;
            }
            if(temp[i] == 0 && counter == 1)                // Jika proses telah selesai seluruhnya
            {
                  x--;
                  printf("\nP[%d]\t%d\t\t\t%d\t\t%d\t\t %d\t\t%d", i, w_datang[i], w_eksekusi[i], total, total - w_datang[i], total - w_datang[i] - w_eksekusi[i]);
                  w_tunggu = w_tunggu + total - w_datang[i] - w_eksekusi[i];
                  w_proses = w_proses + total - w_datang[i];
                  counter = 0;
            }
            if(i == n_proses - 1)
            {
                  i = 0;
            }
            else if(w_datang[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      avg_w_tunggu = w_tunggu * 1.0 / n_proses;
      avg_w_proses = w_proses * 1.0 / n_proses;
      printf("\n\nRata-Rata Waktu Proses:\t%f", avg_w_proses);
      printf("\nRata-Rata Waktu Tunggu:\t%f\n", avg_w_tunggu);
      printf("\n--Tekan tombol apapun untuk keluar dari program!--\n");
      getch();
      return 0;
}
