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
           std::cout << "\nError: index. Please enter a digit between 0 and "  << phoneBook.getContactCount() - 1 << ".\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
	}
	else
	{
		std::cout << RED << "\nPhoneBook is Empty\n\n" << RESET;
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
	std::cout << GREEN  << "\nContact added\n\n" << RESET;
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
	std::cout << GREEN << "Welcome to your PhoneBook!" << RESET << std::endl;
	std::cout << YELLOW << "You can use the following commands:" << RESET << std::endl;
	std::cout << YELLOW << "ADD" << " - Add a new contact" << RESET << std::endl;
	std::cout << YELLOW << "SEARCH" << " - Search for a contact" << RESET << std::endl;
	std::cout << YELLOW << "EXIT" << " - Exit the application\n" << RESET << std::endl;
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
			std::cout << RED << "\nInvalid Command. Please try again.\n\n" << RESET;
		}
	}
	return (0);
}
