//
// Created by kostr on 06.09.22.
//

#include "rc4.h"

rc4::rc4(std::vector<std::byte>& key) {
    this->init(key);
    this->x = 0;
    this->y = 0;
}

void rc4::init(std::vector<std::byte>& key) {
    size_t keyLength = key.size();
    for(int i = 0; i < 256; i++){
        this->S.push_back((std::byte)i);
    }
    int j = 0;
    for(int i = 0; i < 256; i++){
        j = (j + std::to_integer<int>(this->S.at(i)) + std::to_integer<int>(key.at(i % keyLength))) % 256;
        this->swap(i, j);
    }
}

void rc4::swap(int i, int j) {
    std::byte temp = this->S[i];
    this->S[i] = this->S[i];
    this->S[j] = temp;
}

std::byte rc4::keyItem() {
    this->x = (x+1) % 256;
    this->y = (y + (int)S[x]) % 256;
    this->swap(x, y);
    return S[((int)this->S[x] + (int)this->S[y]) % 256];
}

std::vector<std::byte> rc4::Encode(std::vector<std::byte>& dataB, int size) {
    std::vector<std::byte> cipher;
    for(int m = 0; m < size; m++){
        cipher.push_back((std::byte)(dataB[m]^keyItem()));
    }
    return cipher;
}
