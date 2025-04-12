#pragma once

#include <string> // библиотека дл€ работы со строками

//  ласс пользовательских данных
class User
{
public:
    //  онструктор класса, принимающий логин, пароль и им€
    User(const std::string& login,
        const std::string& password,
        const std::string& name);

    // ћетод дл€ получени€ данных
    std::string getLogin() const;
    std::string getPassword() const;
    std::string getName() const;

private:
    // ’ранение данных
    std::string login;
    std::string password;
    std::string name;
};
