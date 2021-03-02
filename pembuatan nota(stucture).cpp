//pembuatan nota kasir
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct pbl
{
    string kode_pbl, status, nama;
} pembeli[5];

struct brg
{
    string kode_brg, nama_brg;
    int harga, jumlah, total;
} barang[5];

struct trx
{
    string kBarang, namaBarang;
    int jumlah, harga, total;
} transaksi[3];

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void dataBarang(){
    barang[0].kode_brg = "BRG001";
    barang[0].nama_brg = "Pensil";
    barang[0].harga = 2000;

    barang[1].kode_brg = "BRG002";
    barang[1].nama_brg = "Buku Tulis";
    barang[1].harga = 3500;

    barang[2].kode_brg = "BRG003";
    barang[2].nama_brg = "Penghapus";
    barang[2].harga = 1000;

    barang[3].kode_brg = "BRG004";
    barang[3].nama_brg = "Penggaris";
    barang[3].harga = 1500;

    barang[4].kode_brg = "BRG005";
    barang[4].nama_brg = "Ballpoint";
    barang[4].harga = 2500;
}

void dataPembeli(){
    //pembeli 1
    pembeli[0].kode_pbl = "P001";
    pembeli[0].status = "M";
    pembeli[0].nama = "Diana";

    //pembeli 2
    pembeli[1].kode_pbl = "P002";
    pembeli[1].status = "M";
    pembeli[1].nama = "Rina";

    //pembeli 3
    pembeli[2].kode_pbl = "P003";
    pembeli[2].status = "BM";
    pembeli[2].nama = "Lina";

    //pembeli 4
    pembeli[3].kode_pbl = "P004";
    pembeli[3].status = "BM";
    pembeli[3].nama = "Doni";

    //pembeli 5
    pembeli[4].kode_pbl = "P005";
    pembeli[4].status = "M";
    pembeli[4].nama = "Dodi";

}

void strip(int jumlah){
    for (int i=0; i<=jumlah; i++){
        cout << "=";
    }
}

void tampilData(){

    int n, ln=4;

    dataPembeli();
    dataBarang();

    cout << "Data Pembeli\n";
    gotoxy(0,1); strip(30);
    gotoxy(50, 1); strip(30);
    gotoxy(0,2); cout << "Kode_pbl";
    gotoxy(10,2); cout << "Status";
    gotoxy(20,2); cout << "Nama" ;

    gotoxy(50,0); cout << "Data Barang\n";

    gotoxy(0,3); strip(30);
    gotoxy(50,3); strip(30);

    gotoxy(50,2); cout << "Kode_brg";
    gotoxy(60,2); cout << "Nama_brg";
    gotoxy(74,2); cout << "Harga" ;


    for (n = 0; n<5; n++){
        gotoxy(0,ln); cout << pembeli[n].kode_pbl;
        gotoxy(10,ln); cout << pembeli[n].status;
        gotoxy(20,ln); cout << pembeli[n].nama;
        gotoxy(50,ln); cout << barang[n].kode_brg;
        gotoxy(60,ln); cout << barang[n].nama_brg;
        gotoxy(74,ln); cout << barang[n].harga;
        ln++;
    }

    gotoxy(0,9); strip(30);
    gotoxy(50,9); strip(30);

}

void cetakNota(int data, int subtotal, int diskon, int total, int jmlBayar, int kembali, string kodePemb, string NamaPembeli, string status){
    int ln = 5, n;
    gotoxy(0,0); cout << "TOKO INDO APRIL";
    gotoxy(0,1); cout << "Jl. DI Panjaitan 128 Purwokerto";
    gotoxy(0,4); cout << "Kode Barang";
    gotoxy(15,4); cout << "Nama Barang";
    gotoxy(30,4); cout << "Jumlah";
    gotoxy(40,4); cout << "Harga";
    gotoxy(49,4); cout << "Total";

    for(n = 0; n<data; n++){
        gotoxy(0,ln); cout << transaksi[n].kBarang;
        gotoxy(15,ln); cout << transaksi[n].namaBarang;
        gotoxy(30,ln); cout << transaksi[n].jumlah;
        gotoxy(40,ln); cout << transaksi[n].harga;
        gotoxy(49,ln); cout << transaksi[n].total;
        ln++;
    }

    gotoxy(0,8); strip(60);
    gotoxy(0,9); cout << "Subtotal";
    gotoxy(49,9); cout << subtotal;
    gotoxy(0,10); cout << "Diskon";
    gotoxy(49,10); cout << diskon;
    gotoxy(0,11); cout << "Total";
    gotoxy(49,11); cout << total;
    gotoxy(0,12); strip(60);
    gotoxy(0,13); cout << "Jumlah Bayar";
    gotoxy(49,13); cout << jmlBayar;
    gotoxy(0,14); cout << "Kembali";
    gotoxy(49,14); cout << kembali;


    gotoxy(0,17); cout << "Kode Pembeli";
    gotoxy(15,17); cout << ":";
    gotoxy(18,17); cout << kodePemb;
    gotoxy(0,18); cout << "Nama Pembeli";
    gotoxy(15,18); cout << ":";
    gotoxy(18,18); cout << NamaPembeli;
    gotoxy(0,19); cout << "Status";
    gotoxy(15,19); cout << ":";
    gotoxy(18,19); cout << status;

}


int main()
{
    int tambah, bnykBarang = 0, indxTrx;
    int data_Pembeli, data_barang, jumlah, kembalian, jmlBayar;
    float diskon, total, subTotal = 0, tmpSubTotal = 0;
    string kdPembeli, kdBarang, cnvrtStatus;

    tampilData();
    cout << endl;
    strip(100);
    gotoxy(40,11); cout << "Transaksi Pembelian\n";
    strip(100);

    gotoxy (0,13); cout << "KodGe Pembeli : ";
    cin >> kdPembeli;
    if (kdPembeli == "P001"){
        data_Pembeli = 0;
    } else if (kdPembeli == "P002"){
        data_Pembeli = 1;
    } else if (kdPembeli == "P003"){
        data_Pembeli = 2;
    } else if (kdPembeli == "P004"){
        data_Pembeli = 3;
    } else if (kdPembeli == "P005"){
        data_Pembeli = 4;
    }

    gotoxy(0,14); cout << "Nama Pembeli   : " << pembeli[data_Pembeli].nama;
    if (pembeli[data_Pembeli].status == "M"){
        cnvrtStatus = "Member";
    } else {
        cnvrtStatus = "Bukan Member";
    }
    gotoxy(0,15); cout << "Status pembeli : " << cnvrtStatus << endl;

    do {
        bnykBarang++;
        cout << endl;
        cout << "Kode Barang : ";
        cin >> kdBarang;
        if (kdBarang == "BRG001"){
            data_barang = 0;
        } else if (kdBarang == "BRG002"){
            data_barang = 1;
        }else if (kdBarang == "BRG003"){
            data_barang = 2;
        }else if (kdBarang == "BRG004"){
            data_barang = 3;
        }else if (kdBarang == "BRG005"){
            data_barang = 4;
        }

        cout << "Nama Barang   : " << barang[data_barang].nama_brg << "\n";
        cout << "Harga Barang  : " << barang[data_barang].harga << "\n";
        cout << "Jumlah Barang : ";
        cin >> jumlah;
        tmpSubTotal = jumlah * barang[data_barang].harga;
        if (jumlah > 3){
            tmpSubTotal = tmpSubTotal - 300;
        } else {
            tmpSubTotal = tmpSubTotal;
        }
        cout << "Sub Total     : " << tmpSubTotal;
        subTotal = subTotal + tmpSubTotal;

        //Insert ke Structure Transaksi
        indxTrx = bnykBarang - 1;
        transaksi[indxTrx].kBarang = kdBarang;
        transaksi[indxTrx].namaBarang = barang[data_barang].nama_brg;
        transaksi[indxTrx].jumlah = jumlah;
        transaksi[indxTrx].harga = barang[data_barang].harga;
        transaksi[indxTrx].total = tmpSubTotal;

        cout << endl;
        cout << "\nApakah anda ingin menambah barang?\n1. Ya\n2. Tidak\nPilihan : ";
        cin >> tambah;
        if(bnykBarang > 5){
            cout << endl;
            cout << "Belanjaan sudah maksimal !";
            tambah = 4;
        }
    } while (tambah == 1);


    if (cnvrtStatus == "Member"){
        diskon = 0.1 * subTotal;
    } else {
        diskon = 0;
    }

    total = subTotal - diskon;

    strip(100);
    cout << endl;
    cout << "Total : "<< total << endl;
    strip(100);
    cout<< endl;
    cout << "Jumlah Bayar : ";
    cin >> jmlBayar;
    kembalian = jmlBayar - total;

    cout << endl;
    cout << endl;
    cout << "Tekan enter untuk mencetak nota..." << endl;

    getch();

    system("cls");

    cetakNota(bnykBarang, subTotal, diskon, total, jmlBayar, kembalian, kdPembeli, pembeli[data_Pembeli].nama, cnvrtStatus);

    cout << endl;
    cout << endl;
    cout << "Tekan enter untuk mengahkiri Program..." << endl;
    getch();
}

