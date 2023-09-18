#ifndef PASSWORD_01_LABELS_H
#include <iostream>
#include <vector>
#define PASSWORD_01_LABELS_H
///ZAIERA WSZYSTKIE TXT DO WYSWIETLENIA W GUI
class Labels {
public:

    static const std::vector<std::string> load_file;
    static const std::vector<std::string>load_file_case;
    static const std::vector<std::string> password;
    static const std::vector<std::string> menu;
    static const std::vector<std::string> searchPassword;
    static const std::vector<std::string> sortPassword;
    static const std::vector<std::string> addPassword;
    static const std::vector<std::string> createPassword;
    static const std::vector<std::string> func_Password;
    static const std::vector<std::string> editPassword;
    static const std::vector<std::string> deletePassword;
    static const std::vector<std::string> addCategory;
    static const std::vector<std::string> deleteCategory;
    static const std::vector<std::string> selectById;
    static const std::vector<std::string> alerts;
};
#endif //PASSWORD_01_LABELS_H
