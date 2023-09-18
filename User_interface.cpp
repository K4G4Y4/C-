#include "User_interface.h"
#include "Password_func.h"

///CZYSZCZENIE OKNA
void clear_window() {
    //std::system("clear");
}

///POKAZYWANIE ALERTÓW
void show_alert(std::vector<std::string> const &v, int &e) {
    std::cout << v[e] << "\n";
    e = 0;
}

///WYSWIETLANIE WARTOSCI VECTORA Z PLIKU LABELS
auto show_label_val(std::vector<std::string> const &v, int e) -> void {
    std::cout << v[e]<<"\n";
}

///ZMIANA WARTOSC ALERT W MAIN
void replace_alert_value(int value, int &alert_value) {
    alert_value = value;
}

///RYSOWANIE OKIEN
void draw(std::vector<std::string> const &v, int alert_value) {
    clear_window();
    show_alert(Labels::alerts, alert_value);
    std::cout << v[0] << "\n";
    for (int e = 1; e < v.size(); e++) {
        std::cout << "    " << e << ". " << v[e] << "\n";
    }
    std::cout << "SENTENCE: ";
}

///RYSOWANIE SZUKANYCH WARTOSCI OBIEKTOW
auto printVecVal(std::vector<Class_password> const &vec) -> void {
   int counter=0;
    for (Class_password e: vec) {
    std::cout<<counter<<".   ";
        e.show();
        counter++;
    }
}

///FILTROWANIE OBIEKTOW KLASY  WEDLUG PODANEJ WARTOSCI
auto filterObjects(std::string &val, std::vector<Class_password> const &myPass)->std::vector<Class_password>{
  std::vector<Class_password> results;
  for(Class_password const & e : myPass){
      if(e.getName().find(val) != -1){
          results.push_back(e);
      }else if(e.getPass().find(val) != -1){
          results.push_back(e);
      }else if(e.getCategory().find(val) != -1){
          results.push_back(e);
      }else if(e.getAddress().find(val) != -1){
          results.push_back(e);
      }else if(e.getLogin().find(val) != -1){
          results.push_back(e);
      }
  }
    return results;
}

///WCZYTANIE INTA Z EKRANU I SPRAWDZENIE POPRAWNOSCI
int get_number() {
    std::string value;
    std::cin >> value;
    try {
        int x = std::stoi(value);
        return x;
    } catch (const std::invalid_argument &e) {
        return 0;
    }

}

///WCZYTANIE STRINGA Z EKRANU
auto get_string() -> std::string {
    std::string value;
    std::cin >> value;
    return value;
}

///WCZYTANIE ODPOWIEDZI Z EKRANU [T/N] I PRZEKAZANIE
auto get_answer()->int{
    std::string choice;
    std::cin>>choice;
        if ((choice == "Y" )|| (choice == "y")) {
            return 1;
        } else if ((choice == "n") || (choice == "N")) {
            return 0;
        } else return 2;

}

///USATWIENIE WARTOSCI HASLA DO PLIKU
auto setPassVal(std::string &val, std::vector<std::string>const& label, int i) ->void {
    show_label_val(Labels::addPassword, i);
    std::string check = get_string();
    if(check =="~"){val =" ";}
    else val = check;
}

/// DODAWANIE WARTOSCI CLASS_PASSWORD PRZY DODAWANIU WARTOSCI NOWYCH OBIEKTOW
auto addPassVal(std::string &val,std::vector<std::string>const & lab, int i, int alert)->void {
    clear_window();
    show_alert(Labels::alerts,alert);
    setPassVal(val,lab, i );
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                               OKNA DIALOGOWE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///OKNO DO LADOWANIA PLIOW
auto load_file(int &alert_value, int &status, std::string &fileToRead) -> void {
    draw(Labels::load_file, alert_value);                               //RYSOWANIE OKNA LOAD_FILE
    int value = get_number();

    switch (value) {
        case (1): {                                                        //WCZYTANIE PLIKU Z LISTY
            clear_window();
            show_label_val(Labels::load_file_case, 0);
            explorerFile();
            show_label_val(Labels::load_file_case, 1);
            std::string filename = get_string();

            int alert = ifExist(filename);
            if (alert == 1) {
                fileToRead = filename;
                status =2;
                clear_window();
            } else replace_alert_value(1, alert_value);
        }

            break;
        //---------------------------------------------------------------------------

        case (2): {                                                         //WCZYTANIE PLIKU ZE SCIEZKI
            clear_window();
            show_label_val(Labels::load_file_case, 2);
            std::string path = get_string();
            int alert = ifExist(path);
            if (alert == 1) {
                fileToRead = path;
                status =2;
            } else replace_alert_value(alert, alert_value);
        }
            break;
        case(3):{                                                            //TWORZENIE NOWEGO PLIKU
            clear_window();
            show_label_val(Labels::load_file_case, 4);
            fileToRead = get_string();
            status=3;

        }
        default:
            replace_alert_value(1, alert_value);
            break;
    }
}

//======================================================================================================================
///OKNO DO POBIERANIA HASLA BY OTWORZYC PLIK
void get_password(int &alert_value, std::string &password){                    //POBIERANIE HASLO OD USERA
    clear_window();
    show_alert(Labels::password,alert_value );
    password = get_string();
}
//======================================================================================================================

///OKNO MENU
void menu(int &alert_value, int &status , std::vector<Class_password>& myPasswords,std::vector<std::string>&categoryVec) {
    draw(Labels::menu, alert_value);
    alert_value =0;

    int value = get_number();
    switch (value) {
    //---------------------------------------------------------------------------
        case (1):                                                                   //SZUKANIE HASŁA
        {
            if(myPasswords.size() == 0){
                clear_window();
                int alert = 6;
                show_alert(Labels::alerts,alert);
                alert = 5;
                show_alert(Labels::alerts,alert );
                get_string();
            }else {
                bool status =true;
                while(status) {
                    draw(Labels::searchPassword, 5);
                    std::string search = get_string();
                    std::vector<Class_password> results = filterObjects(search, myPasswords);
                    printVecVal(results);

                    if(search == "~") {
                        status = false;
                    }else get_string();
                }
            }
        }
        break;
    //---------------------------------------------------------------------------
        case (2):                                                                    //SORTOWANIE HASŁA
            break;
    //---------------------------------------------------------------------------
        case (3):                                                                    //DODAWANIE HASŁA
        {
            clear_window();
            if(categoryVec.size()==0){
                int i =9;
                replace_alert_value(i,alert_value);
            }else
            {
                std::string name, pass, category, address, login;
                addPassVal(name, Labels::addPassword, 1, 0);
                addPassword(pass);
                int trash;
                selectByIdVec(categoryVec, category, 0, trash);
                addPassVal(address, Labels::addPassword, 4, 4);
                addPassVal(login, Labels::addPassword, 5, 4);
                Class_password p =*new Class_password{name,pass,category,address,login};
                myPasswords.push_back(p);
            }
        }

        break;
    //---------------------------------------------------------------------------
        case (4):                                                                    //EDYTOWANIE HASŁA
        {
            editPassword(myPasswords);
        }
        break;
    //---------------------------------------------------------------------------
        case (5):                                                                    //USUWANIE HASŁA
        {
            deletePassword(myPasswords);
        }
        break;
    //---------------------------------------------------------------------------
        case (6):                                                                    //DODAWANIE KATEGORII
        {
            clear_window();
            show_alert(Labels::alerts,alert_value);
            show_label_val(Labels::addCategory,0);
            std::string element = get_string();
            categoryVec.push_back(element);
            replace_alert_value(10,alert_value);
        }
        break;
    //---------------------------------------------------------------------------
        case (7):                                                                    //USUAWNIE KATEGORII
        {
            clear_window();
            show_alert(Labels::alerts,alert_value);
            show_label_val(Labels::deleteCategory,0);
            categoryDel(categoryVec, myPasswords);
        }
        break;
    //---------------------------------------------------------------------------
        case (8):                                                                    //WYŁĄCZANIE MENU
            status =4;
            break;

        default:
            break;
    }

}



