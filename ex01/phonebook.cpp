#include "Phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0)
{
}

void PhoneBook::addContact(const std::string &first, const std::string &last,
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

void PhoneBook::displayContacts() const
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
			std::cout << std::setw(10) << std::left << contacts[i].getFirstName().substr(0,
				10) << "    | ";
			std::cout << std::setw(10) << std::left << contacts[i].getLastName().substr(0,
				10) << "       | ";
			std::cout << std::setw(10) << std::left << contacts[i].getNickName().substr(0,
				10) << "\n";
		}
		std::cout << "\n";
	}
}

void PhoneBook::displaySingleContact(int index) const
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

int PhoneBook::getContactCount()
{
	return (contactCount);
}
