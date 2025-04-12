#include "Chat.h" // ����������� ������������� ����� Chat.h

// ����� ��� ����������� ������ ������������
void Chat::registerUser(const std::string& login, const std::string& password, const std::string& name) {
    // ��������, ���������� �� ��� ������������ � ����� �������
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            throw std::exception("User already exists."); // ��������� ����������, ���� ������������ ��� ����������
        }
    }
    // ���������� ������ ������������ � ������
    users.emplace_back(login, password, name);
    std::cout << "User registered successfully.\n"; // ����������� � �������� �����������
}

// ����� ��� ����� ������������ � �������
void Chat::loginUser(const std::string& login, const std::string& password) {
    // ��������, ���������� �� ������������ � ���������� �� ������
    for (const auto& user : users) {
        if (user.getLogin() == login) {
            if (user.getPassword() == password) {
                currentUser = login; // ��������� �������� ������������
                std::cout << "Logged in as " << user.getName() << "\n"; // ����������� � �����
                return;
            }
            else {
                throw std::exception("Invalid login or password."); // ��������� ����������, ���� ������ ��������
            }
        }
    }
    throw std::exception("Invalid login or password."); // ��������� ����������, ���� ������������ �� ������
}

// ����� ��� �������� ��������� ������������
void Chat::sendMessage(const std::string& recipient, const std::string& message) {
    // ��������, ��� ������������ ����� � �������
    if (currentUser.empty()) {
        throw std::exception("You must be logged in to send messages."); // ��������� ����������, ���� ������������ �� �����
    }

    // ��������, ���������� �� ����������
    bool recipientExists = false;
    for (const auto& user : users) {
        if (user.getLogin() == recipient) {
            recipientExists = true; // ���������� ����, ���� ���������� ������
            break;
        }
    }

    if (!recipientExists) {
        throw std::exception("Recipient not found."); // ��������� ����������, ���� ���������� �� ������
    }

    // ���������� ��������� � ������ ���������
    messages.push_back(currentUser + " to " + recipient + ": " + message);
    std::cout << "Message sent to " << recipient << ".\n"; // ����������� �� �������� ���������
}

// ����� ��� ����������� ���� ���������
void Chat::showMessages() const {
    // ��������, ���� �� ���������
    if (messages.empty()) {
        std::cout << "No messages yet.\n"; // ����������� � ���, ��� ��������� ���
        return;
    }

    // ����� ���� ���������
    for (const auto& msg : messages) {
        std::cout << msg << "\n"; // ����� ���������
    }
}


