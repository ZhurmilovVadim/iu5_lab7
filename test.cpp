#include "header.h"


void enc() {
    std::fstream f_base;
    f_base.open("Base.txt");
    f_base.seekg(std::ios_base::beg, std::ios_base::end);
    long int lenb = f_base.tellg();
    std::cout << lenb << std::endl;
    f_base.seekg(0);
    char *b = new char[lenb];
    f_base.read(b, lenb);
    int counti = 0;
    for (int q = 0; q <= lenb; q++) {
        if (q > 1)
            if (!ispunct(b[q - 1]) && !isspace(b[q - 1])) continue;
        if (ispunct(b[q + 1]) || isspace(b[q + 1]) || (b[q + 1] == '\0')) {
            counti++;
            std::cout << q << std::endl;
        }
    }
    std::cout << counti << std::endl;
}