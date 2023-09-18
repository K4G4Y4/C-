#include "Encryption.h"
#include <iostream>
#include <sstream>
#include <algorithm>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///ZAMIANA STRINGÓW NA <VECTOR INT>
auto to_vector_int(auto val) -> std::vector<int> {
    std::vector<int> vec;
    for (char const e: val) {
        vec.push_back(e);
    }
    return vec;

}///DODAWANIE WARTOŚCI VECTOR CLASS_PASSWOERD I KLUCZA
auto change_vector_int(auto const &int_val, auto &key)->std::vector<int>{
    std::vector<int> int_vec;
    for (size_t i = 0; i < int_val.size(); i++) {
        int_vec.push_back(int_val[i] + key[i % key.size()]);
    }
    return int_vec;
}

///ZMIANA WARTOŚCI VECTOR <INT> NA CHAR I TWORZENIE JEDNEGO STRINGA
auto int_to_string(auto const &convert)->std::string{
    std::stringstream stream;
    for (int const e :convert) {
        char a = char(e);
        stream << a;
    }
    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// SZYFROWANIE DO ZAISU W PLIKU
auto encryption(Class_password &class_val, std::string &Password ) ->std::string{
    auto class_int_val = to_vector_int(class_val.to_string());
    auto key = to_vector_int(Password);
    auto encryption = change_vector_int(class_int_val, key);
    return int_to_string(encryption);
}

///ODSZYFROWYWANIE PLIKU DO APLIKACJI
auto decryption(std::string &string_val, std::string &Password ) ->std::string{
    auto string_int_val = to_vector_int(string_val);
    auto key = to_vector_int(Password);
    std::transform(key.begin(), key.end(), key.begin(), [](int x) { return -x; });
    auto decryption = change_vector_int(string_int_val, key);
    return int_to_string(decryption);
}