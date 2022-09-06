//
// Created by kostr on 06.09.22.
//

#ifndef RC4_RC4_H
#define RC4_RC4_H

#include <cstddef>
#include <vector>

class rc4 {
private:
    std::vector<std::byte> S;
    int x, y = 0;

public:
    rc4(std::vector<std::byte>& key);
    void init(std::vector<std::byte>& key);
    void swap(int i, int j);
    std::byte keyItem();
    std::vector<std::byte> Encode(std::vector<std::byte>& dataB, int size);
};



#endif //RC4_RC4_H
