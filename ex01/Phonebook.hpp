#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>

int	main(int argc, char **argv);

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;

  public:
	Contact(const std::string &first = "", const std::string &last = "",
		const std::string &nicknm = "", const std::string &phone = "");

	void setDetails(const std::string &first, const std::string &last,
		const std::string &nicknm, const std::string &phone);

	void display() const;

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
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
		const std::string &nicknm, const std::string &phone);
	void displayContacts() const;
	void displaySingleContact(int index) const;
	int getContactCount();
};