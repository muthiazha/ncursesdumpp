#include <iostream>
#include <string>

using namespace std;


const string USERNAME = "Daffa,muthia,chayara";
const string PASSWORD = "12345";

void showMenu() {
    cout << "\n=== Selamat Datang di Game ===\n";
    cout << "1. Mulai Permainan\n";
    cout << "2. Lihat Profil\n";
    cout << "3. Keluar\n";
    cout << "Pilih menu (1-3): ";
    int pilihan;
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Memulai permainan...\n";
            break;
        case 2:
            cout << "Menampilkan profil...\n";
            break;
        case 3:
            cout << "Keluar dari game. Terima kasih sudah bermain!\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
    }
}

int main() {
    string inputUsername, inputPassword;
    int attempts = 3;

    cout << "=== Login Game ===\n";

    while (attempts > 0) {

    
        cout << "Username: ";
        cin >> inputUsername;
        cout << "Password: ";
        cin >> inputPassword;
      
        if (inputUsername == USERNAME && inputPassword == PASSWORD) {
            cout << "\nLogin berhasil!\n";
            showMenu();
            break;
        } else {
            attempts--;
            if (attempts > 0) {
                cout << "Username atau password salah. Coba lagi. (" << attempts << " percobaan tersisa)\n";
            } else {
                cout << "Anda telah mencoba terlalu banyak. Akses ditolak.\n";
            }
        }
    }

    return 0;
}
