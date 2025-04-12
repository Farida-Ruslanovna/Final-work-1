#include "User.h" // Подключение заголовочного файла User.h

// Определение конструктора класса User
User::User(const std::string& login, const std::string& password, const std::string& name)
    : login(login), password(password), name(name)
{
}

// Определение метода 
std::string User::getLogin() const {
    return login; // Возвращение логина 
}

std::string User::getPassword() const {
    return password; // Возвращение пароля
}

std::string User::getName() const {
    return name; // Возвращение имени
}