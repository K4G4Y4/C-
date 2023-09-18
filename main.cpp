#include <iostream>
#include "Encryption.h"
#include "Input_output_file.h"
#include "Labels.h"
#include "Class_password.h"
#include "User_interface.h"
#include "Password_func.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
auto main() -> int {

    int alert_value = 0;                                                           //
    int status = 1;                                                                //
    std::string fileToRead = "text.txt", filePassword;                             //DANE KONFIGURACYJNE
    std::vector<Class_password> myPasswords;                                       //
    std::vector<std::string> categoryVec;                                          //
    std::string timestamp;
    //--------------------------------------------------------------------------------------------

    while (status == 1) {                                                        //EKRAN WYBIERANIA PLIKU
        load_file(alert_value, status, fileToRead);
    }
    //--------------------------------------------------------------------------------------------
    if (status == 2) {
        get_password(alert_value, filePassword);                          //EKRAN WPISYWANIA HASŁA
        while (readFile(fileToRead, filePassword, myPasswords)) {      //SPRAWDZANIE POPRAWNOSCI HASŁA
            get_password(alert_value, filePassword);
        };
    }
    //--------------------------------------------------------------------------------------------
       initCategoryVec(categoryVec, myPasswords);                         //INICJALIZACJA VECTORA KATEGORII
    //--------------------------------------------------------------------------------------------
    alert_value = 0;                                                             //PRZYWROCENIE WARTOSCI ALERTOW
    status = 3;                                                                  //URUCHOMIENIE MENU
    while (status == 3) {                                                        //
        menu(alert_value, status, myPasswords, categoryVec);        //
    }
    //--------------------------------------------------------------------------------------------
    alert_value = 1;
    get_password(alert_value, filePassword);                              //DODAWANIE NOWEGO ASLA DO PLIKU
    //--------------------------------------------------------------------------------------------
    saveFile(fileToRead, filePassword, myPasswords);                   //URUCHOMIENIE ZAPISYWANIA DO PLIKU
}
