#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

class User {
public:
	std::string _name;
	std::string _login;
	std::string _pass;

	User(std::string name, std::string login, std::string pass) : _name(name), _login(login), _pass(pass) {}
	User() {}

	void writeInUserFile(const std::string& filename) {

		std::ofstream file(filename);
		if (file.is_open()) {
			file << "Name: " << _name << std::endl;
			file << "Login: " << _login << std::endl;
			file << "Password: " << _pass << std::endl;

			file.close();
		}
		else {
			std::cerr << "Unable to open file for writing." << std::endl;
		}
	}

	static User readUser(const std::string& filename) {

		std::ifstream file(filename, std::ios::binary);
		if (file.is_open()) {
			std::string name, login, pass;

			file >> name >> login >> pass;
			file.close();
			return User(name, login, pass);
		}

	}
};
class Message {
public:
	std::string _text;
	std::string _sender;
	std::string _receiver;

	Message(std::string text, std::string sender, std::string receiver) : _text(text), _sender(sender), _receiver(receiver) {}
	Message() {}

	void writeInMessageFile(const std::string& filename) {
		std::ofstream file(filename, std::ios::binary);
		if (file.is_open()) {
			file << "Message text: " << _text << std::endl;
			file << "Sender: " << _sender << std::endl;
			file << "Recipient: " << _receiver << std::endl;

			file.close();
		}
		else {
			std::cerr << "Unable to open file for writing." << std::endl;
		}

	}

	static Message readMessage(const std::string& filename) {

		std::ifstream file(filename, std::ios::binary);
		if (file.is_open()) {
			std::string text, sender, receiver;

			file >> text >> sender >> receiver;
			file.close();
			return Message(text, sender, receiver);
		}

	}
};

int main() {
	User user{ "John Doe", "john", "password123" };
	Message message{ "Hello, World!", "john", "jane" };

	user.writeInUserFile("userData.txt");

	message.writeInMessageFile("messageData.txt");

	User loadedUser = User::readUser("userData.txt");
	Message loadedMessage = Message::readMessage("messageData.txt");
		

	fs::permissions("Userdata.exe", fs::perms::owner_all | fs::perms::none | fs::perms::none);
	fs::permissions("Messagedata.exe", fs::perms::owner_all | fs::perms::none | fs::perms::none);

	return 0;
}