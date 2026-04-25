#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
using namespace std;

struct User{
    string username;
    string password;
};
struct Produk{
    string nama;
    string warna;
    int harga;
    int stok;
};

bool inputAngka(int &x){
    cin >> x;
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        throw runtime_error("input harus berupa angka!");
    }
    return true;
}

void tampilProduk(Produk *produk, int jumlahProduk);
void tambahProduk(Produk *produk, int *jumlahProduk);
void ubahProduk(Produk *produk, int jumlahProduk);
void hapusProduk(Produk *produk, int *jumlahProduk);
bool login(User *user, int jumlahUser);
void registrasi(User *user, int *jumlahUser);
int totalStok(Produk *produk, int n);
void garis(); 
void garis(int n);

// sort
void bubbleSortNamaDesc(Produk *produk, int n);
void selectionSortHargaAsc(Produk *produk, int n);
void insertionSortStokAsc(Produk *produk, int n);

// search
void linearSearchNama(Produk *produk, int n, string cari);
void binarySearchHarga(Produk *produk, int n, int cari);

int main(){
    User user[100];
    Produk produk[100];
    int jumlahUser = 0;
    int jumlahProduk = 0;
    int menuUtama;

    do{
        system("cls");
        cout<<"-------------------------------"<<endl;
        cout<<"         MENU UTAMA            "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. login"<<endl;
        cout<<"2. registrasi"<<endl;
        cout<<"3. keluar"<<endl;
        cout<<"pilih menu : ";

        try{
            inputAngka(menuUtama);
        }catch(exception &e){
            cout<<e.what()<<endl;
            system("pause");
            continue;
        }

        if(menuUtama==1){
            if(login(user,jumlahUser)){
                int menuAdmin;
                do{
                    system("cls");
                    cout<<"--------------------------------------"<<endl;
                    cout<<"        MENU ADMIN SYIFA HIJAB        "<<endl;
                    cout<<"--------------------------------------"<<endl;
                    cout<<"1. tampilkan produk"<<endl;
                    cout<<"2. tambah produk"<<endl;
                    cout<<"3. ubah produk"<<endl;
                    cout<<"4. hapus produk"<<endl;
                    cout<<"5. keluar"<<endl;
                    cout<<"6. sorting produk"<<endl;
                    cout<<"7. searching produk"<<endl;
                    cout<<"pilih menu : ";

                    try{
                        inputAngka(menuAdmin);
                    }catch(exception &e){
                        cout<<e.what()<<endl;
                        system("pause");
                        continue;
                    }

                    if(menuAdmin==1){
                        tampilProduk(produk,jumlahProduk);
                        int total = totalStok(produk,jumlahProduk);
                        cout<<"total stok semua produk : "<<total<<endl;
                        system("pause");
                    }
                    else if(menuAdmin==2){
                        tambahProduk(produk,&jumlahProduk);
                    }
                    else if(menuAdmin==3){
                        ubahProduk(produk,jumlahProduk);
                    }
                    else if(menuAdmin==4){
                        hapusProduk(produk,&jumlahProduk);
                    }
                    else if(menuAdmin==6){
                        int pilihSort;
                        do{
                            system("cls");
                            cout<<"------ MENU SORTING ------"<<endl;
                            cout<<"1. sort nama (descending)"<<endl;
                            cout<<"2. sort harga (ascending)"<<endl;
                            cout<<"3. sort stok (ascending)"<<endl;
                            cout<<"4. kembali"<<endl;
                            cout<<"pilih : ";

                            try{
                                inputAngka(pilihSort);
                            }catch(exception &e){
                                cout<<e.what()<<endl;
                                system("pause");
                                continue;
                            }

                            if(pilihSort==1){
                                bubbleSortNamaDesc(produk,jumlahProduk);
                                cout<<"berhasil sorting nama desc"<<endl;
                                tampilProduk(produk,jumlahProduk);
                                system("pause");
                            }
                            else if(pilihSort==2){
                                selectionSortHargaAsc(produk,jumlahProduk);
                                cout<<"berhasil sorting harga asc"<<endl;
                                tampilProduk(produk,jumlahProduk);
                                system("pause");
                            }
                            else if(pilihSort==3){
                                insertionSortStokAsc(produk,jumlahProduk);
                                cout<<"berhasil sorting stok asc"<<endl;
                                tampilProduk(produk,jumlahProduk);
                                system("pause");
                            }
                            else if(pilihSort==4){
                                cout<<"kembali ke menu admin"<<endl;
                            }
                            else{
                                cout<<"pilihan tidak ada"<<endl;
                                system("pause");
                            }
                        }while(pilihSort!=4);
                    }

                    else if(menuAdmin==6){ // tetap seperti kode kamu (tidak diubah)
                        int pilihSort;
                        do{
                        }while(pilihSort!=4);
                    }

                    else if(menuAdmin==7){
                        int pilihCari;
                        do{
                            system("cls");
                            cout<<"------ MENU SEARCHING ------"<<endl;
                            cout<<"1. cari nama produk"<<endl;
                            cout<<"2. cari harga produk"<<endl;
                            cout<<"3. kembali"<<endl;
                            cout<<"pilih : ";

                            try{
                                inputAngka(pilihCari);
                            }catch(exception &e){
                                cout<<e.what()<<endl;
                                system("pause");
                                continue;
                            }

                            if(pilihCari==1){
                                cin.ignore();
                                string cari;
                                cout<<"masukkan nama produk : ";
                                getline(cin,cari);
                                linearSearchNama(produk,jumlahProduk,cari);
                                system("pause");
                            }
                            else if(pilihCari==2){
                                int cari;
                                cout<<"masukkan harga : ";
                                try{
                                    inputAngka(cari);
                                }catch(exception &e){
                                    cout<<e.what()<<endl;
                                    system("pause");
                                    continue;
                                }
                                selectionSortHargaAsc(produk,jumlahProduk); 
                                binarySearchHarga(produk,jumlahProduk,cari);
                                system("pause");
                            }
                        }while(pilihCari!=3);
                    }

                }while(menuAdmin!=5);
            }
        }
        else if(menuUtama==2){
            registrasi(user,&jumlahUser);
        }

    }while(menuUtama!=3);

    cout<<"terima kasih"<<endl;
}

// ================= FUNGSI ASLI =================

bool login(User *user, int jumlahUser){
    string username,password;
    int kesempatan = 3;
    while(kesempatan>0){
        system("cls");
        cout<<"----------- LOGIN -----------"<<endl;
        cout<<"username : ";
        cin>>username;
        cout<<"password : ";
        cin>>password;

        if(username=="admincipa" && password=="004"){
            return true;
        }
        for(int i=0;i<jumlahUser;i++){
            if(username==user[i].username && password==user[i].password){
                return true;
            }
        }
        kesempatan--;
        cout<<"login gagal, sisa kesempatan : "<<kesempatan<<endl;
        system("pause");
    }
    return false;
}

void registrasi(User *user, int *jumlahUser){
    system("cls");
    cout<<"----------- REGISTRASI -----------"<<endl;
    cout<<"username : ";
    cin>>user[*jumlahUser].username;
    cout<<"password : ";
    cin>>user[*jumlahUser].password;
    (*jumlahUser)++;
    cout<<"registrasi berhasil"<<endl;
    system("pause");
}

void tampilProduk(Produk *produk, int jumlahProduk){
    system("cls");
    cout<<"----------------- DAFTAR PRODUK -----------------"<<endl;
    if(jumlahProduk==0){
        cout<<"belum ada produk"<<endl;
        return;
    }
    garis(55);
    cout<<left<<setw(5)<<"No"
        <<setw(20)<<"nama"
        <<setw(15)<<"warna"
        <<setw(10)<<"harga"
        <<setw(5)<<"stok"<<endl;
    garis(55);

    for(int i=0;i<jumlahProduk;i++){
        cout<<left<<setw(5)<<i+1
            <<setw(20)<<produk[i].nama
            <<setw(15)<<produk[i].warna
            <<setw(10)<<produk[i].harga
            <<setw(5)<<produk[i].stok<<endl;
    }
    garis(55);
}

void tambahProduk(Produk *produk, int *jumlahProduk){
    system("cls");
    cout<<"------ tambah produk ------"<<endl;
    cin.ignore();
    cout<<"nama produk : ";
    getline(cin,produk[*jumlahProduk].nama);
    cout<<"warna : ";
    getline(cin,produk[*jumlahProduk].warna);

    cout<<"harga : ";
    while(true){
        try{
            inputAngka(produk[*jumlahProduk].harga);
            break;
        }catch(exception &e){
            cout<<e.what()<<" ulangi: ";
        }
    }

    cout<<"stok : ";
    while(true){
        try{
            inputAngka(produk[*jumlahProduk].stok);
            break;
        }catch(exception &e){
            cout<<e.what()<<" ulangi: ";
        }
    }

    (*jumlahProduk)++;
    cout<<"produk berhasil ditambahkan"<<endl;
    system("pause");
}

void ubahProduk(Produk *produk, int jumlahProduk){
    tampilProduk(produk,jumlahProduk);
    int pilih;
    cout<<"pilih nomor produk : ";

    try{
        inputAngka(pilih);
    }catch(exception &e){
        cout<<e.what()<<endl;
        system("pause");
        return;
    }

    if(pilih>=1 && pilih<=jumlahProduk){
        cin.ignore();
        cout<<"nama baru : ";
        getline(cin,produk[pilih-1].nama);
        cout<<"warna baru : ";
        getline(cin,produk[pilih-1].warna);

        cout<<"harga baru : ";
        inputAngka(produk[pilih-1].harga);
        cout<<"stok baru : ";
        inputAngka(produk[pilih-1].stok);

        cout<<"produk berhasil diubah"<<endl;
    }
    else{
        cout<<"nomor tidak valid"<<endl;
    }
    system("pause");
}

void hapusProduk(Produk *produk, int *jumlahProduk){
    tampilProduk(produk,*jumlahProduk);
    int hapus;
    cout<<"pilih nomor produk : ";

    try{
        inputAngka(hapus);
    }catch(exception &e){
        cout<<e.what()<<endl;
        system("pause");
        return;
    }

    if(hapus>=1 && hapus<=*jumlahProduk){
        for(int i=hapus-1;i<(*jumlahProduk)-1;i++){
            produk[i]=produk[i+1];
        }
        (*jumlahProduk)--;
        cout<<"produk berhasil dihapus"<<endl;
    }
    else{
        cout<<"nomor tidak valid"<<endl;
    }
    system("pause");
}

int totalStok(Produk *produk, int n){
    if(n==0) return 0;
    return produk[n-1].stok + totalStok(produk,n-1);
}

void garis(){
    cout<<"-----------------------------"<<endl;
}

void garis(int n){
    for(int i=0;i<n;i++) cout<<"-";
    cout<<endl;
}

void bubbleSortNamaDesc(Produk *produk, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(produk[j].nama < produk[j+1].nama){
                Produk temp = produk[j];
                produk[j] = produk[j+1];
                produk[j+1] = temp;
            }
        }
    }
}

void selectionSortHargaAsc(Produk *produk, int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(produk[j].harga < produk[min].harga){
                min = j;
            }
        }
        Produk temp = produk[i];
        produk[i] = produk[min];
        produk[min] = temp;
    }
}

void insertionSortStokAsc(Produk *produk, int n){
    for(int i=1;i<n;i++){
        Produk key = produk[i];
        int j = i-1;
        while(j>=0 && produk[j].stok > key.stok){
            produk[j+1] = produk[j];
            j--;
        }
        produk[j+1] = key;
    }
}

void linearSearchNama(Produk *produk, int n, string cari){
    bool ketemu = false;
    for(int i=0;i<n;i++){
        if(produk[i].nama.find(cari) != string::npos){
            cout<<produk[i].nama<<" "<<produk[i].warna<<endl;
            ketemu = true;
        }
    }
    if(!ketemu){
        cout<<"produk tidak ditemukan"<<endl;
    }
}

void binarySearchHarga(Produk *produk, int n, int cari){
    int low=0, high=n-1, mid, ketemu=-1;
    while(low<=high){
        mid=(low+high)/2;
        if(produk[mid].harga == cari){
            ketemu=mid;
            break;
        }
        else if(produk[mid].harga < cari){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(ketemu==-1){
        cout<<"produk tidak ditemukan"<<endl;
        return;
    }
    int i=ketemu;
    while(i>=0 && produk[i].harga==cari){
        cout<<produk[i].nama<<" "<<produk[i].warna<<endl;
        i--;
    }
    i=ketemu+1;
    while(i<n && produk[i].harga==cari){
        cout<<produk[i].nama<<" "<<produk[i].warna<<endl;
        i++;
    }
}