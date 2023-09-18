#ifndef PASSWORD_01_ENCRYPTION_H

#define PASSWORD_01_ENCRYPTION_H
#include <string>
#include <vector>
#include "Class_password.h"

///ZAMIANA STRINGÓW NA <VECTOR INT>
auto to_vector_int(auto val) -> std::vector<int>;

///DODAWANIE WARTOŚCI VECTOR CLASS_PASSWOERD I KLUCZA
auto change_vector_int(auto const &int_val, auto &key)->std::vector<int>;

///ZMIANA WARTOŚCI VECTOR <INT> NA CHAR I TWORZENIE JEDNEGO STRINGA
auto int_to_string(auto const &convert)->std::string;

/// SZYFROWANIE DO ZAISU W PLIKU
auto encryption(Class_password &class_val, std::string &Password ) ->std::string;

///ODSZYFROWYWANIE PLIKU DO APLIKACJI
auto decryption(std::string &string_val, std::string &Password ) ->std::string;



#endif//PASSWORD_01_ENCRYPTION_H