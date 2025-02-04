#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>

// Colors
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[38;5;214m";
const std::string BLUE = "\033[38;5;129m";

int	main(int argc, char **argv);

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	Contact(const std::string &first = "", const std::string &last = "",
		const std::string &nicknm = "", const std::string &phone = "",
		const std::string &secret = "");

	void setDetails(const std::string &first, const std::string &last,
		const std::string &nicknm, const std::string &phone,
		const std::string &secret);

	void display() const;

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
};

class PhoneBook
{
  private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int contactCount;
	int oldestContactIndex;

  public:
	PhoneBook();
	void addContact(const std::string &first, const std::string &last,
		const std::string &nicknm, const std::string &phone,
		const std::string &secret);
	void displayContacts() const;
	void displaySingleContact(int index) const;
	int getContactCount();
};