#include <filesystem>
#include <fstream>
#include "Input_output_file.h"
#include "Encryption.h"
#include <ctime>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///TWORZENIE TIMESTAMP I ZAPISYWANIE DO ODDZIELNEGO PLIKU
auto saveTimestamp(std::string const& fileToRead) ->void{
    std::ofstream logFile("fileToReadd", std::ios::app);
    std::time_t now = std::time(nullptr);
    logFile << std::put_time(std::localtime(&now), "%Y-%m-%d %X") << ' ';
    logFile.seekp(-30, std::ios::end);
    logFile.close();
}

///WYSWIETLANIE LISTY PLIKOW W TYM SAMYM FOLDERZE
auto explorerFile() -> void {
    std::cout << "\n";
    for (const auto &entry: std::filesystem::directory_iterator(".")) {
        std::cout << entry.path().filename() << '\n';
    }
}

///SPRAWDZANIE POPRAWNOSCI ISTNIENIA PLIKU ORAZ MOZLIWOSCI JEGO OTWARCIA
auto ifExist(std::string const &val) -> int {
    if (std::filesystem::exists(val)) {
        std::ifstream file(val);
        if (file.is_open()) {
            return 1;
        } else return 0;
    } else return 3;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




///ODZCZYTYWANIE PIKU,ODSZYFROWYWANIE,SPRAWDZANIE POPRAWNOSCI HASLA, ZAPISYWANIE TIMESTAMP,DODAWANIE OBIEKTOW DO VEC MYPASSWORDS
auto readFile(std::string &fileToRead, std::string &filePassword, std::vector<Class_password> &myPasswords) -> bool {

    std::string line;
    char comma = ' ';
    std::ifstream file(fileToRead);

    getline(file, line);                                            // WCZYTYWANIE I SPRAWDZANIE POPRAWNOSCI
    std::string pass2Check = "";                                           // POPRAWNOSCI HASŁA
    std::istringstream stream2 (decryption(line,filePassword));
    stream2 >>pass2Check>>comma>>pass2Check;                               //MAIN <- RAPORTOWANIE O BŁĘDNYCH PRÓBACH
    stream2.clear();                                                       //
    if (filePassword != pass2Check) {                                      //
        std::cout << "Podano niepoprawne haslo! Sprobuj jeszcze raz!";
        saveTimestamp(fileToRead);

        return true;

    }
    while (getline(file, line)) {                                             //ODCZYTYWANIE LINII PLIKU
        std::istringstream stream (decryption(line,filePassword));        //ODSZYFROWYWANIE
        std::string name,pass,category,address,login;                               //ZMIENNE DLA KONSTRUKTORA
        stream >>name>>comma>>pass>>comma>>category>>comma>>address>>comma>>login;  //WCZYTYWANIE STRING DLA ZMIENNYCH
        Class_password p = *new Class_password(name, pass, category, address, login);
        myPasswords.push_back(p);
    }
    file.close();
    return false;
}

///ZAPISYWANIE PLIKU,SZYFROWANIE, HASLA(KLUCZA)
auto saveFile(std::string &fileToRead,std::string &filePassword, std::vector<Class_password> &myPasswords)->void{
    std::ofstream file(fileToRead, std::ios::out);

    Class_password mainPass("", filePassword, "", "");      //TWORZENIE OBIEKTU Z HASŁA(KLUCZA)
    file << encryption(mainPass, filePassword) << '\n';          //ZAPISANIE HASŁA(KLUCZA)

        for(Class_password e : myPasswords) {                           //ZAPISWYANIE OBIEKTOW CLASS Z HASŁAMI
            std::string value = encryption(e, filePassword);
            file << value << "\n";
        }
        file.flush();
        file.close();


}

