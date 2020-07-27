#include<iostream>
#include<conio.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct{
	int kode;
	char nama[20];
	int stock;
	char tanggal[20];
}

brg;
	brg barang[5];
	brg lok[5];
	brg temp;
	int n,i,b, cari, ada;

// Fungsi Utama
int main() {
	
	// Menu Pembuka
	programMulai: // Label programMulai
	system("cls");
	cout<<"\n";
	cout<<"\t=======================================\n";
	cout<<"\t|       APLIKASI MANAJEMEN DATA       |\n";
	cout<<"\t|          STOCK BARANG TOKO          |\n";
	cout<<"\t|           by:  Kelompok 1           |\n";
	cout<<"\t=======================================\n";
	cout<<"\tIbnu Ahmad Fauzi          (19104410028)\n";
	cout<<"\tAyu Triananda Nur Safitri (19104410041)\n";
	cout<<"\tIges Imas Tarini          (19104410044)\n";
	cout<<"\tAfiga Iza Alfariz         (19104410064)\n";
	cout<<"\t=======================================\n";
	cout<<"\t|     Ingin melanjutkan program ?     |\n";
	cout<<"\t|       ( Y ) Iya | ( T ) Tidak       |\n";
	cout<<"\t=======================================\n";
	cout<<"\tMasukan jawaban (Y/T) : ";
	char pilihan; // Deklarasi variabel pilihan
	cin>>pilihan; // Input pilihan Y atau T
	
	// Menu jika memilih Y
	if(pilihan == 'Y' || pilihan == 'y') {
		goto pilihMenu;
	}
	
	// Menu apabila memilih T
	else if(pilihan == 'T' || pilihan == 't') {
		goto programSelesai; // Menuju ke label programSelesai
	}
	
	// Menu apabila bukan memilih Y atau T
	else {
		system("cls");
		cout<<"\n";
		cout<<"\t=======================================\n";
		cout<<"\t|       Pilihan Tidak Terdaftar       |\n";
		cout<<"\t| Silahkan Masukan Ulang Pilihan Anda |\n";
		cout<<"\t=======================================\n";
		cout<<"\t";
		getch();
		goto programMulai; // Menuju ke label programMulai
	}
	
	// Menu Program
	pilihMenu: // Label pilihMenu
	system("cls");
	cout<<"\n";
	cout<<"\t================= Menu =================\n";
	cout<<"\t----------------------------------------\n";
	cout<<"\t 1. Input Barang Barang\n";
	cout<<"\t 2. Keluar\n";
	cout<<"\t----------------------------------------\n";
	cout<<"\tMasukan pilihan (1/2) : ";
	int pilihanProgram;
	cin>>pilihanProgram;
	
	// Deklarasi Array
	int kodebarang[0];
	
	// Jika memilih tambah barang
	if(pilihanProgram == 1) {
		system("cls");
		cout<<"\n";
		cout<<"\tMasukan Jumlah Barang : ";
		cin>>n;
		for(i=0;i<n;i++){
			cout<<endl;
			cout<<"\t"<<"Barang ke "<<i+1<<endl;
			cout<<"\t"<<"Input Kode Barang                 : ";cin>>barang[i].kode;
			cout<<"\t"<<"Input Nama Barang                 : ";cin>>gets(barang[i].nama);
			cout<<"\t"<<"Input Stock Barang                : ";cin>>barang[i].stock;
			cout<<"\t"<<"Input Tanggal Barang (DD/MM/YYYY) : ";cin>>gets(barang[i].tanggal);
			cout<<endl;
		}
		goto pilihMenu2; // Menuju label pilihMenu2
	}
	
	// Jika memilih keluar
	else if(pilihanProgram == 2) {
		goto programSelesai; // Menuju lebal programSelesai
	}
	
	// Jika pilihan bukan 1/2/3/4/5
	else {
		system("cls");
		cout<<"Tidak ada input\n";
		getch();
		goto pilihMenu;
	}
	
	// Menu Program 2
	pilihMenu2:
	system("cls");
	cout<<"\n";
	cout<<"\t================= Menu =================\n";
	cout<<"\t----------------------------------------\n";
	cout<<"\t 1. Lihat Barang\n";
	cout<<"\t 2. Cari Barang\n";
	cout<<"\t 3. Keluar\n";
	cout<<"\t----------------------------------------\n";
	cout<<"\tMasukan pilihan (1/2/3) : ";
	int pilihanProgram2;
	cin>>pilihanProgram2;
	
	// Jika memilih lihat barang
	if(pilihanProgram2 == 1) {
		system("cls");
		for(i=0;i<n;i++){
	        for(b=0;b<n-1;b++){
				if(barang[b].kode > barang[b+1].kode){
				temp.kode=barang[b].kode;
				barang[b].kode=barang[b+1].kode;
				barang[b+1].kode=temp.kode;
				strcpy(temp.nama,barang[b].nama);
				strcpy(barang[b].nama,barang[b+1].nama);
				strcpy(barang[b+1].nama,temp.nama);
				temp.stock=barang[b].stock;
				barang[b].stock=barang[b+1].stock;
				barang[b+1].stock=temp.stock;
				strcpy(temp.tanggal,barang[b].tanggal);
				strcpy(barang[b].tanggal,barang[b+1].tanggal);
				strcpy(barang[b+1].tanggal,temp.tanggal);
				}
			}
		}
		cout<<"\t===================== Data Barang Toko =====================\n";
		cout<<"\t------------------------------------------------------------\n\n";
		cout<<"\t------------------------------------------------------------\n";
		cout<<"\tFormat Tampilan List :\n";
        cout<<"\t(Kode Barang - Nama Barang - Jumlah Stock - Tanggal Masuk)\n";
        cout<<"\t------------------------------------------------------------\n\n";
        cout<<"\t------------------------------------------------------------\n";
		for(b=0;b<n;b++){
			cout<<"\t"<<"=> "<<barang[b].kode<<" - "<<barang[b].nama<<" - "<<barang[b].stock<<" - "<<barang[b].tanggal<<endl;
		}
		cout<<"\t------------------------------------------------------------\n\n";
		getch();
		goto pilihMenu2;
	}
	
	// Jika memilih cari barang
	if(pilihanProgram2 == 2) {
		system("cls");
		cout<<"\tMasukan Kode Barang Untuk Mencari : ";
        cin>>cari;
        system("cls");
        ada = 0;
        for(b=0;b<n;b++)
            {
            if(barang[b].kode==cari)
                {
                    ada=1;
					cout<<"\t===================== Hasil Searching ======================\n";
					cout<<"\t------------------------------------------------------------\n\n";
					cout<<"\t------------------------------------------------------------\n";
					cout<<"\tFormat Tampilan List :\n";
    			    cout<<"\t(Kode Barang - Nama Barang - Jumlah Stock - Tanggal Masuk)\n\n";
                    cout<<"\t"<<barang[b].kode<<" - "<<barang[b].nama<<" - "<<barang[b].stock<<" - "<<barang[b].tanggal<<endl;
                }
            }
                    cout<<"\t============================================================"<<endl;
                    system("PAUSE");
                    getch();
                    goto pilihMenu2;

        if (ada == 0)
            {
                cout<<"Data Tidak ditemukan"<<endl;
                    system("PAUSE");
                    getch();
                    goto pilihMenu2;
            }
	}
	
	// Menu Penutup
	programSelesai: // Label programSelesai
	system("cls");
	cout<<"\n";
	cout<<"\t=======================================\n";
	cout<<"\t|   Terima Kasih, Telah Menggunakan   |\n";
	cout<<"\t|            Program  Kami            |\n";
	cout<<"\t=======================================\n";
	cout<<"\t";
	getch();
}
