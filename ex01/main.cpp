#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;

  public:
	Contact(const std::string &first = "", const std::string &last = "",
		const std::string &nicknm = "",
		const std::string &phone = "") : firstName(first), lastName(last),
		nickName(nicknm), phoneNumber(phone)
	{
	}

	void setDetails(const std::string &first, const std::string &last,
		const std::string &nicknm, const std::string &phone)
	{
		firstName = first;
		lastName = last;
		nickName = nicknm;
		phoneNumber = phone;
	}

	void display() const
	{
		std::cout << "Name: " << firstName << " " << lastName << "Nickname: " << nickName << "/ Phone: " << phoneNumber << std::endl;
	}

	std::string getFirstName() const
	{
		return (firstName);
	}
	std::string getLastName() const
	{
		return (lastName);
	}
	std::string getNickName() const
	{
		return (nickName);
	}
	std::string getPhoneNumber() const
	{
		return (phoneNumber);
	}
};

class PhoneBook
{
  private:
	static const int MAX_CONTACTS = 8;
	Contact contacts[MAX_CONTACTS];
	int contactCount;

  public:
	PhoneBook() : contactCount(0)
	{
	}

	void addContact(const std::string &first, const std::string &last,
		const std::string &nicknm, const std::string &phone)
	{
		if (contactCount < MAX_CONTACTS)
		{
			contacts[contactCount].setDetails(first, last, nicknm, phone);
			contactCount++;
		}
		else
		{
			std::cout << "PhoneBook is full! Cannot add more contacts.\n";
		}
	}

	void displayContacts() const
	{
		if (contactCount == 0)
		{
			std::cout << "PhoneBook is Empty\n";
			return ;
		}
		else
		{
			std::cout << "Index | First Name    | Last Name        | Nickname     \n";
			std::cout << "-------------------------------------------------------------\n";
			for (int i = 0; i < contactCount; i++)
			{
				std::cout << i << "     | ";
				std::cout << std::setw(10) << std::left << contacts[i].getFirstName() << "    | ";
				std::cout << std::setw(10) << std::left << contacts[i].getLastName().substr(0, 10) << "       | ";
				std::cout << std::setw(10) << std::left << contacts[i].getNickName() << "\n";
				// contacts[i].display();
				// std::cout << "\n";
			}
		}
	}
};

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	PhoneBook phoneBook;

	phoneBook.addContact("Alice", "Smith", "Wonderland", "+123-456-7890");
	phoneBook.addContact("Sasha", "Uplisashvili", "BOOO", "+995-599-32-57-75");
	phoneBook.addContact("Tea", "Tvaradze", "Tekoo", "+995-577-76-04-01");
	phoneBook.addContact("Kote", "Uplisashvili", "KU", "+995-599-57-75-35");
	phoneBook.addContact("Anano", "Glonti", "BUSIKIII", "+49-155-092-2131");
	phoneBook.displayContacts();
	return (0);
}