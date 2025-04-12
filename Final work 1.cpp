// Final work 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <string>
#include <locale> // Для работы с локализацией
#include "Chat.h" // Подключаем класс Chat

int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем локализацию на русский язык
    Chat chat; // Создаем объект чата
    std::string command; // Переменная для хранения команды пользователя

    while (true) { // Бесконечный цикл для обработки команд
        std::cout << "Введите команду (register, login, send, show, exit): "; // Запрашиваем команду
        std::cin >> command; // Считываем команду

        try {
            if (command == "register") { // Если команда "register"
                std::string login, password, name; // Переменные для логина, пароля и имени
                std::cout << "Введите логин: "; // Запрашиваем логин
                std::cin >> login; // Считываем логин
                std::cout << "Введите пароль: "; // Запрашиваем пароль
                std::cin >> password; // Считываем пароль
                std::cout << "Введите имя: "; // Запрашиваем имя
                std::cin >> name; // Считываем имя
                chat.registerUser(login, password, name); // Регистрируем пользователя
            }
            else if (command == "login") { // Если команда "login"
                std::string login, password; // Переменные для логина и пароля
                std::cout << "Введите логин: "; // Запрашиваем логин
                std::cin >> login; // Считываем логин
                std::cout << "Введите пароль: "; // Запрашиваем пароль
                std::cin >> password; // Считываем пароль
                chat.loginUser(login, password); // Авторизуем пользователя
            }
            else if (command == "send") { // Если команда "send"
                std::string recipient, message; // Переменные для получателя и сообщения
                std::cout << "Введите получателя: "; // Запрашиваем получателя
                std::cin >> recipient; // Считываем получателя
                std::cout << "Введите сообщение: "; // Запрашиваем сообщение
                std::cin.ignore(); // Игнорируем символ новой строки
                std::getline(std::cin, message); // Считываем сообщение с пробелами
                chat.sendMessage(recipient, message); // Отправляем сообщение
            }
            else if (command == "show") { // Если команда "show"
                chat.showMessages(); // Показываем все сообщения
            }
            else if (command == "exit") { // Если команда "exit"
                break; // Выходим из цикла
            }
            else {
                std::cout << "Неизвестная команда.\n"; // Сообщаем о неизвестной команде
            }
        }
        catch (const std::exception& e) { // Обработка исключений
            std::cout << "Ошибка: " << e.what() << "\n"; // Выводим сообщение об ошибке
        }
    }

    return 0; 

}
