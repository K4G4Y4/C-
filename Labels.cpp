#include "Labels.h"

const std::vector<std::string> Labels::load_file ={"CHOOSE OPTION:","CHOOSE FILE FROM THE LIST",
                                                   "SPECIFY THE DIRECT, ABSOLUTE PATH TO THE FILE",
                                                   "CREATE NEW FILE"};

const std::vector<std::string> Labels::load_file_case ={"FILES AVAILABLE:","ENTER THE NAME OF THE FILE:",
                                                        "ENTER THE DIRECT, ABSOLUTE PATH TO THE FILE:",
                                                        "FILE DOES NOT EXIST", "SET NEW FILE NAME"};

//======================================================================================================================

const std::vector<std::string> Labels::password ={"ENTER THE PASSWORD:","SET THE NEW FILE PASSWORD:"};

//======================================================================================================================
const std::vector<std::string> Labels::menu ={"HELLO! Welcome to your Password Manager", "SEARCH PASSWORD",
                                              "SORT PASSWORD", "ADD PASSWORD", "EDIT PASSWORD", "DELETE PASSWORD",
                                                "ADD CATEGORY", "DELETE CATEGORY", "EXIT"};

//----------------------------------------------------------------------------------------------------------------------
const std::vector<std::string> Labels::searchPassword{"SEARCH PASSWORD"};
const std::vector<std::string> Labels::sortPassword{"SORT CLASS_PASSWORD.\nYOU CAN CHOOSE TWO VALUES:\nSELECT SELECT THE FIRST VALUE",
                                                   "CHOOSE THE SECOND VALUE:"};
const std::vector<std::string> Labels::addPassword{"CREATE NEW PASSWORD.",
                                                   "CREATE NEW PASSWORD.\nENTER THE  NAME:",
                                                   "CREATE NEW PASSWORD.\nENTER THE  PASSWORD:",
                                                   "CREATE NEW PASSWORD.\nENTER THE CATEGORY:",
                                                   "CREATE NEW PASSWORD.\nENTER WEB ADDRESS:",
                                                   "CREATE NEW PASSWORD.\nENTER LOGIN:"};
const std::vector<std::string> Labels::createPassword{"DO YOU WANT TO GENERATE PASSWORD AUTOMATICALLY? [Y/N]",
                                                      "ENTER PASSWORD LENGTH: ","IS IT UPPERCASE? [Y/N]",
                                                      "SHOULD IT CONTAIN SPECIAL CHARACTERS? [Y/N]"};
const std::vector<std::string> Labels::func_Password{"THE PASSWORD IS SAFE.",
                                                     "THE PASSWORD IS NOT SECURE.",
                                                     "THE PASSWORD IS TOO SHORT AND MUST CONTAIN AT LEAST 8 CHARACTERS",
                                                     "THE PASSWORD DOES NOT MEET THE CHARACTER DIVERSITY REQUIREMENTS. \nUSE UPPERCASE AND LOWERCASE LETTERS, ADD SPECIAL CHARACTERS AND \nNUMBERS TO THE PASSWORD.",
                                                     "THE PASSWORD CONTAINS ILLEGAL CHARACTERS"};
const std::vector<std::string> Labels::editPassword{"EDIT PASSWORD.\nCHOOSE RIGHT NUMBER AND ENTER CORRECT VALUE:"};
const std::vector<std::string> Labels::deletePassword{"CHOOSE PASSWORD TO DELETE.\nWRITE RIGHT NUMBER TO THE FIELD:\n",
                                                      "ARE YOU SURE YOU WANT TO DO THIS? BY DELETING A CATEGORY, \nYOU WILL DELETE ALL PASSWORD WITH THIS CATEGORY![Y/N]"};
const std::vector<std::string> Labels::addCategory{"CREATE NEW CATEGORY.\nENTER NAME:  "};
const std::vector<std::string> Labels::deleteCategory{"CHOOSE CATEGORY TO DELETE.\nWRITE RIGHT NUMBER TO THE FIELD:",
                                                      "ARE YOU SURE YOU WANT TO DO THIS? BY DELETING A CATEGORY, \nYOU WILL DELETE ALL PASSWORD WITH THIS CATEGORY![Y/N]"};
const std::vector<std::string> Labels::selectById{"SELECT CATEGORY BY ID CATEGORY","SELECT BY ID CATEGORY","SELECT BY ID"};

//======================================================================================================================
const std::vector<std::string> Labels::alerts = {"\033[32m:)\033[0m ",
                                                 "\033[31mWRITE CORRECT VALUE\033[0m",
                                                 "\033[31mFAILED TO OPEN THE FILE\033[0m",
                                                 "\033[31mFILE DOES NOT EXIST\033[0m",
                                                 "\033[32mIF YOU DONT'T WANT TO SET VALUE ENTER '~' \033[0m ",
                                                 "\033[32mIF YOU WANT TO BACK ENTER '~' \033[0m ",
                                                 "\033[31mFILE IS EMPTY\033[0m",
                                                 "\033[32mIF YOU WANT TO SET VALUE ENTER '~'\033[0m ",
                                                 "\033[31mOTHERWISE YOU WILL GO BACK TO ENTER YOUR PASSWORD AGAIN\033[0m ",
                                                 "\033[31m>:(\nCREATE A NEW CATEGORY FIRST\033[0m",
                                                 "\033[36mYOU HAVE ADDED A NEW CATEGORY\033[0m",
                                                 "\033[33m:o!!!\033[0m"};


