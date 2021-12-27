//
// Created by vadim on 22.10.2021.
//
#include "header.h"
void encription(char *file_name,char *key_file_name, bool flag){
    std::fstream original_file;
    original_file.open(file_name);
    original_file.seekg(std::ios_base::beg, std::ios_base::end);
    long int file_len = original_file.tellg();
    original_file.seekg(0);
    char *text = new char [file_len];
    original_file.read(text, file_len + 1);
    original_file.close();

    std::fstream key_file;
    key_file.open(key_file_name);
    key_file.seekg(std::ios_base::beg, std::ios_base::end);
    long int key_len = key_file.tellg();
    key_file.seekg(0);
    char *key = new char [key_len];
    int count = 0;
    int space = 0;
    for(int i = 0; i < key_len; ++i){
        char tmp = key_file.peek();
        if (!std::ispunct(tmp) && !std::isspace(tmp)) {
            key[count] += key_file.get();
            space = 0;
        }
        else{
            if (space != 0){
                --count;
            }
            else{
                ++space;

            }
            ++count;
            key_file.get();
        }
    }
    std::fstream encryption;
    encryption.open("encrypted.txt", std::ios::out);

    long int i = 0;
    int k = flag ? 1 : -1;
    for(; i < file_len; ++i){
        text[i] += k * key[i % count];
    }
    encryption.write(text, file_len);
    encryption.close();
}
