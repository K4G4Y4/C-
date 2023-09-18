#include "Class_password.h"
#include <iostream>
#include <string>
#include <algorithm>


///KONSTRUKTOR KLASY POSIADA DWIE DOMYSLNE WARTOSCI DLA NIEWYMAGANYCH ELEMENTOW
Class_password::Class_password(const std::string &n, const std::string &p, const std::string &c, const std::string &a,
                               const std::string &l) : name(n), pass(p), category(c), address(a), login(l) {
}
/// WYSWIETLANIE ELEMENTOW DLA TERMINALA
auto Class_password::show() -> void {
    name;pass;category;address;login;
    std::string show =
    "\033[34m  Name: \033[37m" + name +
    "\033[34m  PASSWORD: \033[37m" + pass +
    "\033[34m  CATEGORY: \033[37m" + category +
    "\033[34m  ADDRESS: \033[37m" + address +
    "\033[34m  LOGIN: \033[37m" + login +
    "\n\033[0m";
    std::cout<<show<<"\n";
}
/// WYSWIETLANIE ELEMENTOW DO FUNKCJI ZAPISU
auto Class_password::to_string() -> std::string {
    std::string value;
    value = name + " " + pass + " " + category + " " + address + " " + login;
    return value;
}
/// PRZEKAZYWANIE ELEMENTU NAME
const std::string &Class_password::getName() const {
    name;
    return name;
}
/// PRZEKAZYWANIE ELEMENTU CATEGORY
const std::string &Class_password::getCategory() const {
    category;
    return category;
}
/// PRZEKAZYWANIE ELEMENTU PASS
const std::string &Class_password::getPass() const {
    pass;
    return pass;
}
/// PRZEKAZYWANIE ELEMENTU ADDRESS
const std::string &Class_password::getAddress() const {
    address;
    return address;
}
/// PRZEKAZYWANIE ELEMENTU LOGIN
const std::string &Class_password::getLogin() const {
    login;
    return login;
}



