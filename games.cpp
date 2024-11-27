#include <ncurses/curses.h>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>

using namespace std;


const string USERNAME = "daffa,muthia,chayara";
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
int main() {
    int x = 10, y = 10;
    int ch;
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();

    start_color();
    init_pair(1, COLOR_BLUE, COLOR_WHITE); 
    init_pair(2, COLOR_RED, COLOR_BLACK); 
    init_pair(3, COLOR_GREEN, COLOR_YELLOW);
    mvprintw(0, 0, "Gunakan tombol panah untuk bergerak. Tekan 'q' untuk keluar.");
    box(stdscr, 0, 0);

    while ((ch = getch()) != 'q') {
        clear();
        box(stdscr, 0, 0);
        mvprintw(0, 0, "Gunakan tombol panah untuk bergerak. Tekan 'q' untuk keluar.");

        time_t now = time(0);
        std::string currentTime = ctime(&now);
        mvprintw(0, COLS - currentTime.size(), currentTime.c_str());

        int prev_x = x, prev_y = y;

        switch (ch) {
            case KEY_UP:
                y = (y > 1) ? y - 1 : y;
                break;
            case KEY_DOWN:
                y = (y < LINES - 2) ? y + 1 : y;
                break;
            case KEY_LEFT:
                x = (x > 1) ? x - 1 : x;
                break;
            case KEY_RIGHT:
                x = (x < COLS - 2) ? x + 1 : x; 
                break;
        }

        attron(COLOR_PAIR(2));
        mvprintw(prev_y, prev_x, "+");
        attroff(COLOR_PAIR(2));

        static int colorToggle = 1;
        colorToggle = (colorToggle % 3) + 1;

        attron(COLOR_PAIR(colorToggle));
        mvprintw(y, x, "X");
        attroff(COLOR_PAIR(colorToggle));

        mvprintw(1, 2, "Posisi: (%d, %d)", x, y);

        refresh();
    }
int main() {
    initscr();
    start_color();
    
    init_pair(1, COLOR_BLUE, COLOR_WHITE); 
    init_pair(2, COLOR_BLACK, COLOR_GREEN);

    for (int i = 0; i < 3; i++) {
        attron(COLOR_PAIR(1));
        mvprintw(26, 100, "Loading....");
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(1));
        mvprintw(27, 100, "-------------------");
        mvprintw(28, 100, "|                 |");
        mvprintw(29, 100, "-------------------");
        attroff(COLOR_PAIR(1));

        for (int f = 0; f < 18; f++) {
            attron(COLOR_PAIR(1));
            mvprintw(28, 101 + f, "->");
            attroff(COLOR_PAIR(1));
            refresh();
            Sleep(200);
        }
    }
    endwin();
    return 0;
}
