#ifndef PASSWORD_01_PASSWORD_FUNC_H
#define PASSWORD_01_PASSWORD_FUNC_H
#include "Password_func.h"
#include "User_interface.h"

///FUNKCJA DO USTALANIA PARAMETROW GENEROWANEGO HASLA: USTALENIE WIELKIE/MALE LITERY, ZNAKI SPECJALNE
auto getCharParametersPass(int &alert, int label, int &value)->void;

///FUNKCJA DO USTALANIA PARAMETROW GENEROWANEGO HASLA: DLUGOSC HASLA
auto getIntParametersPass(int &alert, int label, int &value)->void;

///GENEROWANIE HASLA PRZEZ PODANE ZMIENNE
auto generatePassword(int length, bool hasUpper, bool hasSpecial)->std::string;

///SPRAWDZANIE BEZPIECZENSTWA HASLA PODANEGO PRZEZ USERA
bool checkPasswordSecurity(std::string password);

///OPCJA MENU::DODAWANIE HASLA
auto addPassword(std::string &pass) ->void ;

///WYSWIETLANIE I WYBIERANIE ELEMENTOW VECTORA KATEGORII
auto selectByIdVec(std::vector<std::string> &vec, std::string &val, int label, int &answer)->void;

///OPCJA MENU::USUWANIE KATEGORII
void categoryDel(std::vector<std::string> &categoryVec, std::vector<Class_password> &myPasswords);

///DODAWANIE ELEMENTOW VECTORA KATEGORII
auto initCategoryVec(std::vector<std::string> &categoryVec,std::vector<Class_password> &myPasswords)->void;

///WYSWIETLANIE I WYBIERANIE ELEMENTOW VECTORA CLASS_PASSWORDS
auto selectByIdPass(std::vector<Class_password> &vec, int label, int &answer) -> void;

///OPCJA MENU::USUN HASLO
auto deletePassword(std::vector<Class_password> &myPasswords) -> void;

///FUNKCJA DO POBIERANIA WARTOSCI ORAZ CZYZCZENIA OKNA - EDIT PASSWORD
void edit(std::string &newVal);

///OPCJA MENU::eDYTOWANIE HASLA
void editPassword(std::vector<Class_password> &myPasswords);




#endif //PASSWORD_01_PASSWORD_FUNC_H
