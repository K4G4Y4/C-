#ifndef PASSWORD_01_INPUT_OUTPUT_FILE_H

#include "Class_password.h"


#define PASSWORD_01_INPUT_OUTPUT_FILE_H
#include <vector>
#include <iostream>

///TWORZENIE TIMESTAMP I ZAPISYWANIE DO ODDZIELNEGO PLIKU
auto saveTimestamp(std::string const& fileToRead) ->void;

///WYSWIETLANIE LISTY PLIKOW W TYM SAMYM FOLDERZE
auto explorerFile() -> void;

///SPRAWDZANIE POPRAWNOSCI ISTNIENIA PLIKU ORAZ MOZLIWOSCI JEGO OTWARCIA
auto ifExist(std::string const &val) -> int;

///ODZCZYTYWANIE PIKU,ODSZYFROWYWANIE,SPRAWDZANIE POPRAWNOSCI HASLA, ZAPISYWANIE TIMESTAMP,DODAWANIE OBIEKTOW DO VEC MYPASSWORDS
auto readFile(std::string &fileToRead, std::string &filePassword, std::vector<Class_password> &myPasswords)->bool;

///ZAPISYWANIE PLIKU,SZYFROWANIE, HASLA(KLUCZA)
auto saveFile(std::string &fileToRead, std::string &filePassword, std::vector<Class_password> &myPasswords)->void;


#endif//PASSWORD_01_INPUT_OUTPUT_FILE_H