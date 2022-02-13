#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define ROZ 20

using namespace std;

void GreetingScreen();
int Menu();
int Settings();
void Teacher(bool version);
void ScreenCleaner();

int main() {
    unsigned short mode = 2;
    bool version;
    srand(time(NULL));

    GreetingScreen();

    while (mode != 3) {
        mode = Menu();
        if (mode == 2)
            version = Settings();
        if (mode == 1)
            Teacher(version);
    }
    return 0;
}

void GreetingScreen() {
    cout << "\t\t\tWelcome in VocabTeacher!";
    Sleep(1000);
    ScreenCleaner();
}

int Menu() {
    unsigned short mode;
    cout << "(1) Start" << endl << "(2) Settings" << endl << "(3) Exit" << endl;
    cin >> mode;
    ScreenCleaner();
    return mode;
}

int Settings() {
    bool version;
    cout << "Which translation do you prefer?" << endl << "(0) english - polish" << endl << "(1) polish - english" << endl;
    cin >> version;
    ScreenCleaner();
    return version;
}

void Teacher(bool version) {
    int i, letter, word;
    char english[ROZ], polish[ROZ];
    char temp, *peng, *ppol;
    peng = &english[0];
    ppol = &polish[0];
    FILE *f;

    cout << "Loading";
    for (i = 0; i < 3; ++i) {
        Sleep(1000);
        cout << ".";
    }

    letter = 0; //rand() % 3;
    switch (letter) {
        case 0:
            word = 1; //rand() % 3;
            break;
        case 1:
            word = rand() % 2;
            break;
        case 2:
            word = rand() % 4;
            break;
        default:
            break;
    }

    f = fopen ("data.txt", "r");
    if (f == NULL) printf("Can't open file!");
    else {
        switch (letter) {
            case 0:
                while ((temp = getc(f)) != '\r');
                if (word) {
                    for (i = 0; i < word; ++i)
                        while ((temp = getc(f)) != '\r');
                }
                break;
            case 1:
                word = rand() % 2;
                break;
            case 2:
                word = rand() % 4;
                break;
            default:
                break;
        }
        while ((*peng = getc(f)) != ' ')
            peng++;
        *peng = '\00';
        while ((*ppol = getc(f)) != '\n')
            ppol++;
        *ppol = '\00';
        ScreenCleaner();

        puts(english);
        puts(polish);
        Sleep(5000);
    }

    ScreenCleaner();
}

void ScreenCleaner() {
    int i;
    for (i = 0; i < 40; i++) {
        cout << endl;
    }
}