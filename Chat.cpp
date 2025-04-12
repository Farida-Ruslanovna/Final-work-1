#include "Chat.h" // Подключение заголовочного файла Chat.h

// Метод для регистрации нового пользователя
void Chat::registerUser(const std::string& login, const std::string& password, const std::string& name) {
    // Проверка, существует ли уже пользователь с таким логином
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            throw std::exception("User already exists."); // Генерация исключения, если пользователь уже существует
        }
    }
    // Добавление нового пользователя в вектор
    users.emplace_back(login, password, name);
    std::cout << "User registered successfully.\n"; // Уведомление о успешной регистрации
}

// Метод для входа пользователя в систему
void Chat::loginUser(const std::string& login, const std::string& password) {
    // Проверка, существует ли пользователь и правильный ли пароль
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            if (user.getPassword() == password) {
                currentUser = login; // Установка текущего пользователя
                std::cout << "Logged in as " << user.getName() << "\n"; // Уведомление о входе
                return;
            }
            else {
                throw std::exception("Invalid login or password."); // Генерация исключения, если пароль неверный
            }
        }
    }
    throw std::exception("Invalid login or password."); // Генерация исключения, если пользователь не найден
}

// Метод для отправки сообщения пользователю
void Chat::sendMessage(const std::string& recipient, const std::string& message) {
    // Проверка, что пользователь вошел в систему
    if (currentUser.empty()) {
        throw std::exception("You must be logged in to send messages."); // Генерация исключения, если пользователь не вошел
    }

    // Проверка, существует ли получатель
    bool recipientExists = false;
    for (const auto& user : users) {
        if (user.getLogin() == recipient) {
            recipientExists = true; // Установить флаг, если получатель найден
            break;
        }
    }

    if (!recipientExists) {
        throw std::exception("Recipient not found."); // Генерация исключения, если получатель не найден
    }

    // Добавление сообщения в вектор сообщений
    messages.push_back(currentUser + " to " + recipient + ": " + message);
    std::cout << "Message sent to " << recipient << ".\n"; // Уведомление об отправке сообщения
}

// Метод для отображения всех сообщений
void Chat::showMessages() const {
    // Проверка, есть ли сообщения
    if (messages.empty()) {
        std::cout << "No messages yet.\n"; // Уведомление о том, что сообщений нет
        return;
    }

    // Вывод всех сообщений
    for (const auto& msg : messages) {
        std::cout << msg << "\n"; // Вывод сообщения
    }
}


