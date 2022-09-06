#include <iostream>
#include <string>         // std::string, std::u16string
#include <locale>         // std::wstring_convert
#include <codecvt>
#include "rc4.h"

std::vector<std::byte> to_byte(const std::string& a){
    std::vector<std::byte> bstring;
    char* cstr = const_cast<char *>(a.c_str());
    for(int i = 0; i < a.length(); i++){
        bstring.push_back((std::byte)(int)cstr[i]);
    }
    return bstring;
}
std::string to_str(std::vector<std::byte>& a){
    int length = a.size();
    unsigned char* cstr = new unsigned char[length];
    for(int i = 0; i < length; i++){
        cstr[i] = (unsigned char)std::to_integer<int>(a[i]);
    }
    std::string out(reinterpret_cast< char const* >(cstr));
    return out;
}

int main() {
    std::string keyWord = "key";
    std::vector<std::byte> key = to_byte(keyWord);
    rc4 encoder(key);
    std::string testString = "A byte can be converted to a numeric value (such as to produce an integer hash of an object";
    std::cout << "Initial string:   "<< testString << std::endl << testString.size() << std::endl << std::endl ;
    std::vector<std::byte> testBytes = to_byte(testString);
    std::vector<std::byte> result = encoder.Encode(testBytes, testBytes.size());
    std::string out = to_str(result);
    std::cout << "Encoded string:    " << out << std::endl << out.size() << std::endl << std::endl;
    rc4 decoder(key);
    std::vector<std::byte> result_de = decoder.Encode(result, result.size());
    std::string out2 = to_str(result_de);
    std::cout << "Decoded string:    " << out2 << std::endl << out.size();
    return 0;
}
