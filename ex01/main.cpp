# include "Phonebook.hpp"

// void	leaks(void)
// {
// 	system("leaks phonebook");
// }

void	handleSearch(PhoneBook &phoneBook)
{
	int	index;

	if(phoneBook.getContactCount() > 0)
	{
		phoneBook.displayContacts();
		std::cout << "Enter index of contact to find: ";
        if (std::cin >> index && index >= 0 && index <= phoneBook.getContactCount() - 1)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            phoneBook.displaySingleContact(index);
        }
        else
        {
           std::cout << "\nError: Invalid index. Please enter a digit between 0 and "  << phoneBook.getContactCount() - 1 << ".\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
	}
	else
	{
		std::cout << "\nPhoneBook is Empty\n\n";
		return ;
	}
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
			std::cout << "\nInvalid Command. Please try again.\n\n";
		}
	}
	return (0);
}
