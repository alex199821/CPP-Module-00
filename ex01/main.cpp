# include "Phonebook.hpp"

void	leaks(void)
{
	system("leaks phonebook");
}
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
	int oldestContactIndex;

  public:
	PhoneBook() : contactCount(0), oldestContactIndex(0)
	{
	}

	void addContact(const std::string &first, const std::string &last,
		const std::string &nicknm, const std::string &phone)
	{
		if (contactCount == 0)
		{
			contacts[0].setDetails(first, last, nicknm, phone);
			contactCount++;
			oldestContactIndex++;
		}
		else if (contactCount > 0 && contactCount < MAX_CONTACTS)
		{
			for (int i = contactCount; i > 0; i--)
			{
				contacts[i].setDetails(
					contacts[i - 1].getFirstName(),
					contacts[i - 1].getLastName(),
					contacts[i - 1].getNickName(),
					contacts[i - 1].getPhoneNumber()
				);
			}

			contacts[0].setDetails(first, last, nicknm, phone);
			contactCount++;
		}
		else if (contactCount >= MAX_CONTACTS)
		{
			for (int i = MAX_CONTACTS - 1; i > 0; i--)
			{
				contacts[i].setDetails(
					contacts[i - 1].getFirstName(),
					contacts[i - 1].getLastName(),
					contacts[i - 1].getNickName(),
					contacts[i - 1].getPhoneNumber()
				);
			}

			contacts[0].setDetails(first, last, nicknm, phone);
			oldestContactIndex = MAX_CONTACTS - 1;
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
			std::cout << "\n";
			std::cout << "Index | First Name    | Last Name        | Nickname     \n";
			std::cout << "-------------------------------------------------------------\n";
			for (int i = 0; i < contactCount; i++)
			{
				std::cout << i << "     | ";
				std::cout << std::setw(10) << std::left << contacts[i].getFirstName().substr(0, 10) << "    | ";
				std::cout << std::setw(10) << std::left << contacts[i].getLastName().substr(0, 10) << "       | ";
				std::cout << std::setw(10) << std::left << contacts[i].getNickName().substr(0, 10) << "\n";
			}
			std::cout << "\n";
		}
	}
	void displaySingleContact(int index) const
	{
		if (contactCount == 0)
		{
			std::cout << "PhoneBook is Empty\n";
			return ;
		}
		else
		{
			std::cout << "\n";
			for (int i = 0; i < contactCount; i++)
			{
				if (i == index)
				{
					std::cout << "Found Contact" << std::endl;
					std::cout << "----------------------------\n" << std::endl;
					std::cout << "First Name: " << contacts[i].getFirstName() << std::endl;
					std::cout << "Last Name: " << contacts[i].getLastName() << std::endl;
					std::cout << "Nick Name: " << contacts[i].getNickName() << std::endl;
					std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
					std::cout << "\n----------------------------" << std::endl;
				}
			}
			std::cout << "\n";
		}
	}
};

void	handleSearch(PhoneBook &phoneBook)
{
	int	index;

	phoneBook.displayContacts();
	std::cout << "Enter index of contact to find: ";
	std::cin >> index;
	std::cin.ignore();
	phoneBook.displaySingleContact(index);
}

void	handleAdd(PhoneBook &phoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::cout << "First name: ";
	std::cin >> firstName;
	std::cout << "Last name: ";
	std::cin >> lastName;
	std::cout << "Nickname: ";
	std::cin >> nickName;
	std::cout << "Phone Number: ";
	std::cin >> phoneNumber;
	phoneBook.addContact(firstName, lastName, nickName, phoneNumber);
	std::cin.ignore();
	std::cout << "\nContact added\n\n";
}

int	main(int argc, char **argv)
{
	PhoneBook	phoneBook;

	(void)argc;
	(void)argv;
	std::string command;
	// int contact_index;
	// atexit(leaks);
	std::cout << std::endl;
	std::cout << "Welcome to your PhoneBook!" << std::endl;
	std::cout << "You can use the following commands:" << std::endl;
	std::cout << "ADD" << " - Add a new contact" << std::endl;
	std::cout << "SEARCH" << " - Search for a contact" << std::endl;
	std::cout << "EXIT" << " - Exit the application\n" << std::endl;
	while (1)
	{
		std::cout << "Enter a Command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			handleAdd(phoneBook);
		}
		else if (command == "SEARCH")
		{
			handleSearch(phoneBook);
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Invalid Command. Please try again.\n";
		}
	}
	return (0);
}

// phoneBook.addContact("Anamaria", "Smith", "Wonderland", "+123-456-7890");
// phoneBook.addContact("Sasha", "Uplisashvili", "BOOO","+995-599-32-57-75");
// phoneBook.addContact("Tea", "Tvaradze", "Tekoo", "+995-577-76-04-01");
// phoneBook.addContact("Kote", "Uplisashvili", "KU", "+995-599-57-75-35");
// phoneBook.addContact("Anano", "Glonti", "BUSIKIII", "+49-155-092-2131");
// phoneBook.addContact("John", "Doe", "Johnny", "+1-800-555-1234");
// phoneBook.addContact("Jane", "Smith", "Janey", "+44-20-7946-0958");
// phoneBook.addContact("Alice", "Johnson", "Ali", "+1-303-555-6789");
// phoneBook.addContact("Bob", "Brown", "Bobby", "+1-212-555-4321");
// phoneBook.addContact("Gela", "Trolishvili", "TROLOLOLO","+1-289-89-8989");
// phoneBook.addContact("Churiko", "Gremmmery", "Chikoo","+995-599-324-123");
// phoneBook.displayContacts();
// phoneBook.displaySingleContact(2);