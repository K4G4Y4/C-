#ifndef PASSWORD_01_CLASS_PASSWORD_H
#define PASSWORD_01_CLASS_PASSWORD_H
#include <iostream>


///KLASA PASSWORD PRZECHOWUJE WSZYSTKIE WYGENEROWANE PROFIE HASEŁ
class Class_password {
    ///ELEMENTY STRING CLASS-Y
private:
    std::string name;
    std::string pass;
    std::string category;
    std::string address;
    std::string login;
public:
    ///KONSTRUKTOR KLASY POSIADA DWIE DOMYSLNE WARTOSCI DLA NIEWYMAGANYCH ELEMENTOW
    Class_password(const std::string &n, const std::string &p, const std::string &c, const std::string &a=" ",
                   const std::string &l=" ");
    auto show()->void;                            /// WYSWIETLANIE ELEMENTOW DLA TERMINALA
    auto to_string() -> std::string;              /// WYSWIETLANIE ELEMENTOW DO FUNKCJI ZAPISU
    const std::string &getName() const;           /// PRZEKAZYWANIE ELEMENTU NAME
    const std::string &getCategory() const;       /// PRZEKAZYWANIE ELEMENTU CATEGORY
    const std::string &getPass() const;           /// PRZEKAZYWANIE ELEMENTU PASS
    const std::string &getAddress() const;        /// PRZEKAZYWANIE ELEMENTU ADDRESS
    const std::string &getLogin() const;          /// PRZEKAZYWANIE ELEMENTU LOGIN

};
#endif//PASSWORD_01_CLASS_PASSWORD_H