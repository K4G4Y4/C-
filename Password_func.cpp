//
// Created by Kamil Bolek on 14/01/2023.
//

#include <regex>
#include "Password_func.h"
#include "User_interface.h"

///FUNKCJA DO USTALANIA PARAMETROW GENEROWANEGO HASLA: USTALENIE WIELKIE/MALE LITERY, ZNAKI SPECJALNE
auto getCharParametersPass(int &alert, int label, int &value)->void {
    int answer = 2;
    while (answer == 2) {
        clear_window();
        show_alert(Labels::alerts, alert);
        show_label_val(Labels::createPassword, label);
        answer = get_answer();
        if (answer == 2) { alert = 1; }
    }
    alert = 0;
}

///FUNKCJA DO USTALANIA PARAMETROW GENEROWANEGO HASLA: DLUGOSC HASLA
auto getIntParametersPass(int &alert, int label, int &value)->void {
    int answer;
    bool status = true;

    while (status) {
        clear_window();
        show_alert(Labels::alerts, alert);
        show_label_val(Labels::createPassword, label);

        answer = get_number();
        if (answer == 0) {
            alert = 1;
        } else status = false;
    }
    value = answer;
}

///GENEROWANIE HASLA PRZEZ PODANE ZMIENNE
auto generatePassword(int length, bool hasUpper, bool hasSpecial)->std::string {
    std::string password = "";
    for (int i = 0; i < length; i++) {
        char c;
        if (hasSpecial && rand() % 2 == 0) {
            c = 33 + rand() % 15;
        } else {
            c = (rand() % 2 == 0) ? 48 + rand() % 10 : (hasUpper ? 65 + rand() % 26 : 97 + rand() % 26);
        }
        password += c;
    }
    return password;
}
//-==================================================================================================================

///SPRAWDZANIE BEZPIECZENSTWA HASLA PODANEGO PRZEZ USERA
bool checkPasswordSecurity(std::string password) {
    clear_window();
    if (password.length() < 8) {                                                     //SPRAWDZANIE DLUGOSCI HASLA
        clear_window();
        show_label_val(Labels::alerts, 7);
        std::cout << "\n";
        show_label_val(Labels::alerts, 8);
        show_label_val(Labels::func_Password, 2);
        std::string val = get_string();
        if (val == "~")return true;
        else
            return false;
    }

    bool hasDigit = false, hasUpper = false, hasSpecial = false;                    //SPRAWDZANIE ROZNORODNOSCI ZNAKOW
    for (char c: password) {
        if (isdigit(c)) hasDigit = true;
        else if (isupper(c)) hasUpper = true;
        else if (!isalnum(c)) hasSpecial = true;
    }
    if (!hasDigit || !hasUpper || !hasSpecial) {
        clear_window();
        show_label_val(Labels::alerts, 7);
        std::cout << "\n";
        show_label_val(Labels::alerts, 8);
        show_label_val(Labels::func_Password, 3);
        std::string val = get_string();
        if (val == "~")return true;
        else
            return false;
    }

    if (!regex_match(password, std::regex("^[a-zA-Z0-9!@#%^&*()_+-=]+$"))) { //SPRAWDZANIE ROZNORODNOSCI HASLA
        clear_window();
        show_label_val(Labels::alerts, 7);
        std::cout << "\n";
        show_label_val(Labels::alerts, 8);
        show_label_val(Labels::func_Password, 4);
        std::string val = get_string();
        if (val == "~")return true;
        else
            return false;
    }
    return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///OPCJA MENU::DODAWANIE HASLA
auto addPassword(std::string &pass) -> void {
    int alert = 0, val = 2, val2;
    bool status = true;
    while (status) {
        clear_window();
        show_alert(Labels::alerts, alert);
        std::cout << Labels::createPassword[0] << "\n";
        val = get_answer();
        if ((val == 1) || (val == 0)) {
            status = false;
            alert = 0;
        } else alert = 1;
    }
    if (val == 1) {
        int length, hasUpper, hasSpecial;
        getIntParametersPass(alert, 1, length);
        getCharParametersPass(alert, 2, hasUpper);
        getCharParametersPass(alert, 3, hasSpecial);
        pass = generatePassword(length, hasUpper, hasSpecial);
    } else {
        status = true;
        while (status) {
            clear_window();
            show_alert(Labels::alerts, alert);
            show_label_val(Labels::addPassword, 2);
            pass = get_string();

            if (checkPasswordSecurity(pass)) {
                show_label_val(Labels::func_Password, 0);
                status = false;
            } else {
                show_label_val(Labels::func_Password, 1);
            }
        }
    }
    std::cout << pass << "\n";
}


///WYSWIETLANIE I WYBIERANIE ELEMENTOW VECTORA KATEGORII
auto selectByIdVec(std::vector<std::string> &vec, std::string &val, int label, int &answer) -> void {
    int alert = 0;
    bool status = true;
    while (status) {
        clear_window();
        int id = 0;
        show_alert(Labels::alerts, alert);
        show_label_val(Labels::selectById, label);
        for (auto const &e: vec) {

            std::cout << id << ".   " << e << "\n";
            id++;
        }
        answer = get_number();
        if ((answer <= vec.size() - 1) || (answer >= 0)) {
            val = vec[answer];
            status = false;
        } else {
            alert = 1;
        }
    }

}

///OPCJA MENU::USUWANIE KATEGORII
void categoryDel(std::vector<std::string> &categoryVec, std::vector<Class_password> &myPasswords) {
    bool status = true;
    int answer, counter = 0, alert = 11, val;
    std::string delElement;

    for (Class_password &e: myPasswords) {
        std::cout << "id. " << counter << " ";
        e.show();
        counter++;
    }
    answer = get_number();
    while (status) {
        clear_window();
        show_alert(Labels::alerts, alert);
        show_label_val(Labels::deletePassword, 1);
        val = get_answer();
        if (val == 1 || val == 0) {
            status = false;
        } else alert = 1;
    }
    if (val == 1) {
        categoryVec.erase(categoryVec.begin() + answer);
        for (Class_password &e: myPasswords) {
            if (e.getCategory() == delElement) {
                categoryVec.erase(categoryVec.begin() + counter);
            }
            counter++;
        }
    }
}

///DODAWANIE ELEMENTOW VECTORA KATEGORII
auto initCategoryVec(std::vector<std::string> &categoryVec, std::vector<Class_password> &myPasswords) -> void {

    if (myPasswords.size() > 0) {
        for (Class_password &e: myPasswords) {
            categoryVec.push_back(e.getCategory());
        }
    }
}

///WYSWIETLANIE I WYBIERANIE ELEMENTOW VECTORA CLASS_PASSWORDS
auto selectByIdPass(std::vector<Class_password> &vec, int label, int &answer) -> void {
    int alert = 0;
    bool status = true;
    while (status) {
        clear_window();
        int id = 0;
        show_alert(Labels::alerts, alert);
        show_label_val(Labels::selectById, label);
        for (Class_password &e: vec) {
            std::cout << id << ".   ";
            e.show();
            id++;
        }
        std::cout << "SENTENCE ";
        int e = get_number();
        if ((answer <= vec.size() - 1) || (answer >= 0)) {
            answer = e;
            status = false;
        } else {
            alert = 1;
        }
    }

}

///OPCJA MENU::USUN HASLO
void deletePassword(std::vector<Class_password> &myPasswords) {
    bool status = true;
    int answer, counter = 0, alert = 11, val;
    std::string delElement;
    selectByIdPass(myPasswords, 2, answer);

    while (status) {
        clear_window();
        show_alert(Labels::alerts, alert);
        show_label_val(Labels::deleteCategory, 1);
        val = get_answer();
        if (val == 1 || val == 0) {
            status = false;
        } else alert = 1;
    }
    if (val == 1) {
        myPasswords.erase(myPasswords.begin() + answer);

    }
}

///FUNKCJA DO POBIERANIA WARTOSCI ORAZ CZYZCZENIA OKNA - EDIT PASSWORD
void edit(std::string &newVal) {
    std::cout << "enter a new value or enter \"~\" to exit" << "\n";
    newVal = get_string();
    clear_window();

}

///OPCJA MENU::eDYTOWANIE HASLA
void editPassword(std::vector<Class_password> &myPasswords) {
    bool status = true;
    int answer;
    selectByIdPass(myPasswords, 2, answer);
    std::string nam, pas, cat, add, log;

    edit(nam);
    std::cout<<"Name: "<<"\n";
    if(nam == "~"){
        nam= myPasswords[answer].getName();
    }
    edit(pas);
    std::cout<<"Password: "<<"\n";
    if(pas == "~"){
        pas= myPasswords[answer].getPass();
    }
    cat= myPasswords[answer].getCategory();

    edit(add);
    std::cout<<"Address: "<<"\n";
    if(add == "~"){
        add= myPasswords[answer].getAddress();
    }
    edit(log);
    std::cout<<"Login: "<<"\n";
    if(log == "~"){
        log= myPasswords[answer].getLogin();
    }
    myPasswords.erase(myPasswords.begin() + answer);
    Class_password p(nam,pas,cat,add,log);
    myPasswords.push_back(p);
}