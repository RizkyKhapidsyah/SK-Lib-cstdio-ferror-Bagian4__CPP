#pragma warning(disable:4996)

#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cwchar>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main(void) {
    const char* fname = std::tmpnam(nullptr);
    std::FILE* f = std::fopen(fname, "wb");
    std::fputs("\xff\xff\n", f);
    std::fclose(f);

    std::setlocale(LC_ALL, "en_US.utf8");
    f = std::fopen(fname, "rb");
    std::wint_t ch;

    while ((ch = std::fgetwc(f)) != WEOF) {
        std::printf("%#x ", ch);
    }
        

    if (std::feof(f)) {
        puts("EOF indicator set");
    }
        
    if (std::ferror(f)) {
        puts("Error indicator set");
    }
        
    _getch();
    return 0;
}