#pragma once

#include "User.h" // Предполагаем, что User определен в отдельном заголовочном файле.

#include <vector> // Для использования вектора
#include <string> // Для работы со строками
#include <iostream> // Для вывода в консоль
#include <exception> // Для обработки исключений

// Класс чата
class Chat {
public:
    // Метод для регистрации нового пользователя
    void registerUser(const std::string& login, const std::string& password, const std::string& name);

    // Метод для входа пользователя в систему
    void loginUser(const std::string& login, const std::string& password);

    // Метод для отправки сообщения пользователю
    void sendMessage(const std::string& recipient, const std::string& message);

    // Метод для отображения всех сообщений
    void showMessages() const;

private:
    std::vector<User> users; // Вектор для хранения пользователей
    std::vector<std::string> messages; // Вектор для хранения сообщений
    std::string currentUser; // Логин текущего пользователя
};
