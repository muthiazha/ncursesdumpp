#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <ncurses/curses.h>
#include <cstdio>

void loadingScreen() {
    clear();
    for (int i = 0; i <= 100; i += 25) {
        mvprintw(10, 10, "Loading: %d%%", i);
        refresh();
        sleep(1);
    }
}

void textAnimation() {
    clear();
    const std::string message = "aur auran, jangan suka aur auran...";
    for (size_t i = 0; i <= message.length(); ++i) {
        mvprintw(10, 10, "%s", message.substr(0, i).c_str());
        refresh();
        usleep(200000); // 200000 mikrodetik = 0.2 detik
    }
    getch();
}

void readFile() {
    clear();
    std::ifstream file("example.txt", std::ios::in);
    if (!file) {
        mvprintw(10, 10, "Tidak bisa membuka file!");
    } else {
        std::string line;
        int lineNum = 0;
        while (std::getline(file, line) && lineNum < 10) {
            mvprintw(10 + lineNum, 10, "%s", line.c_str());
            lineNum++;
        }
    }
    file.close();
    getch();
}

void writeFile() {
    clear();
    std::ofstream file("example.txt", std::ios::out | std::ios::app);
    if (!file) {
        mvprintw(10, 10, "Tidak bisa membuka file untuk menulis!");
    } else {
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        file << "DDP Selesai.\n";
        mvprintw(10, 10, "Berhasil Menamatkan DDP!");
        attroff(COLOR_PAIR(1));
    }
    file.close();
    sleep(1);
    getch();
}

void deleteFile() {
    if (remove("example.txt") == 0) {
        clear();
        mvprintw(10, 10, "File 'example.txt' telah dihapus.");
    } else {
        clear();
        mvprintw(10, 10, "Tidak bisa menghapus file 'example.txt'.");
    }
    refresh();
    sleep(2);
}

int main() {
    initscr();
    start_color();
    noecho();
    cbreak();
    loadingScreen();
    
    while (true) {
        clear();
        mvprintw(10, 10, "Pilih opsi:");
        mvprintw(12, 10, "1. Animasi Teks");
        mvprintw(13, 10, "2. Baca File Teks");
        mvprintw(14, 10, "3. Tulis ke File Teks");
        mvprintw(15, 10, "4. Keluar dan Hapus File");
        mvprintw(17, 10, "Pilih opsi (1-4): ");
        
        char choice = getch();

        switch (choice) {
            case '1':
                textAnimation();
                break;
            case '2':
                readFile();
                break;
            case '3':
                writeFile();
                break;
            case '4':
                deleteFile();
                endwin();
                return 0;
            default:
                mvprintw(10, 10, "Pilihan tidak valid! Tekan tombol apapun untuk melanjutkan.");
                refresh();
                getch();
                break;
        }
    }
    endwin();
    return 0;
} 
