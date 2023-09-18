#ifndef PASSWORD_01_USER_INTERFACE_H
#include "Labels.h"
#include "Input_output_file.h"
#define PASSWORD_01_USER_INTERFACE_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

///CZYSZCZENIE OKNA
void clear_window();

///POKAZYWANIE ALERTÓW
void show_alert(std::vector<std::string> const &v, int &e);

///WYSWIETLANIE WARTOSCI VECTORA Z PLIKU LABELS
auto show_label_val(std::vector<std::string> const &v, int e) ->void;

///ZMIANA WARTOSC ALERT W MAIN
void replace_alert_value(int value, int &alert_value);

///RYSOWANIE OKIEN
void draw(std::vector<std::string>const &v, int alert_value);

///RYSOWANIE SZUKANYCH WARTOSCI OBIEKTOW
auto printVecVal(std::vector<Class_password> const &vec) -> void;

///FILTROWANIE OBIEKTOW KLASY  WEDLUG PODANEJ WARTOSCI
auto filterObjects(std::string &val, std::vector<Class_password>const &myPass)->std::vector<Class_password>;

///WCZYTANIE INTA Z EKRANU I SPRAWDZENIE POPRAWNOSCI
int get_number();

///WCZYTANIE STRINGA Z EKRANU
auto get_string()->std::string;

///WCZYTANIE ODPOWIEDZI Z EKRANU [T/N] I PRZEKAZANIE
auto get_answer()->int;

///USATWIENIE WARTOSCI HASLA DO PLIKU
auto setPassVal(std::string &val, std::vector<std::string>const& label, int i) ->void;

/// DODAWANIE WARTOSCI CLASS_PASSWORD PRZY DODAWANIU WARTOSCI NOWYCH OBIEKTOW
auto addPassVal(std::string &val,std::vector<std::string>const & lab, int i, int alert)->void;

///OKNO DO LADOWANIA PLIOW
auto load_file(int &alert_value, int &status,std::string &fileToRead) ->void;

///OKNO DO POBIERANIA HASLA BY OTWORZYC PLIK
void get_password(int &alert_value, std::string &password);

///OKNO MENU
void menu(int& alert_value, int &status, std::vector<Class_password> &myPasswords,std::vector<std::string>&categoryVec);








std::string show_menu(std::vector<std::string> const &headlines);

#endif //PASSWORD_01_USER_INTERFACE_H
