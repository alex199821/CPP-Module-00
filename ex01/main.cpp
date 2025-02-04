#include "PhoneBook.hpp"

// void	leaks(void)
// {
// 	system("leaks phonebook");
// }

void	handleSearch(PhoneBook &phoneBook)
{
	int	index;

	if (phoneBook.getContactCount() > 0)
	{
		phoneBook.displayContacts();
		std::cout << "Enter index of contact to find: ";
		if (std::cin.peek() == '\n')
		{
			std::cout << RED << "Error: Input cannot be empty. Please enter a valid index.\n" << RESET;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}
		if (!(std::cin >> index))
		{
    		if (std::cin.eof())
			{
				std::cout << std::endl;
				exit(0);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << RED << "Error: Please enter a valid digit.\n" << RESET;
			return;
		}
		if (index >= 0 && index <= phoneBook.getContactCount() - 1)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			phoneBook.displaySingleContact(index);
		}
		else
		{
			std::cout << RED  <<  "Error: Please enter a digit between 0 and " << phoneBook.getContactCount()
				- 1 << ".\n" << RESET;
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

bool getNonEmptyInput(const std::string& prompt, std::string& output) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, output)) {
            std::cout << std::endl;
            return false;
        }
        
        if (output.empty()) {
            std::cout << RED << "Error: Input cannot be empty.\n" << RESET;
        } else {
            return true;
        }
    }
}

void handleAdd(PhoneBook &phoneBook) {
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    if (!getNonEmptyInput("First name: ", firstName)) {
        exit(0);
    }
    if (!getNonEmptyInput("Last name: ", lastName)) {
        exit(0);
    }
    if (!getNonEmptyInput("Nickname: ", nickName)) {
        exit(0);
    }
    if (!getNonEmptyInput("Phone Number: ", phoneNumber)) {
        exit(0);
    }
	if (!getNonEmptyInput("Darkest Secret: ", darkestSecret)) {
        exit(0);
    }

    phoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    std::cout << GREEN << "Contact added\n" << RESET;
}

int	main(int argc, char **argv)
{
	PhoneBook	phoneBook;

	// atexit(leaks);
	(void)argc;
	(void)argv;
	std::string command;
	std::cout << std::endl;
	std::cout << GREEN << "Welcome to your PhoneBook!" << RESET << std::endl;
	std::cout << YELLOW << "You can use the following commands:" << RESET << std::endl;
	std::cout << YELLOW << "ADD" << " - Add a new contact" << RESET << std::endl;
	std::cout << YELLOW << "SEARCH" << " - Search for a contact" << RESET << std::endl;
	std::cout << YELLOW << "EXIT" << " - Exit the application\n"<< RESET << std::endl;
	while (1)
	{
		std::cout << "Enter a Command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			break ;
		}
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
			std::cout << RED << "Invalid Command. Please try again.\n" << RESET;
		}
	}
	return (0);
}
