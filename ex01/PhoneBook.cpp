#include "PhoneBook.hpp"

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
			contacts[i].setDetails(contacts[i - 1].getFirstName(), contacts[i
				- 1].getLastName(), contacts[i - 1].getNickName(), contacts[i
				- 1].getPhoneNumber());
		}
		contacts[0].setDetails(first, last, nicknm, phone);
		contactCount++;
	}
	else if (contactCount >= MAX_CONTACTS)
	{
		for (int i = MAX_CONTACTS - 1; i > 0; i--)
		{
			contacts[i].setDetails(contacts[i - 1].getFirstName(), contacts[i
				- 1].getLastName(), contacts[i - 1].getNickName(), contacts[i
				- 1].getPhoneNumber());
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
		std::cout << BLUE << "     Index|First Name| Last Name|  Nickname\n" << RESET;
		std::cout << BLUE << "-------------------------------------------\n" << RESET;
		for (int i = 0; i < contactCount; i++)
		{
			std::cout << BLUE << std::setw(10) << std::right << i << "|" << RESET;
			std::string first_name = contacts[i].getFirstName();
			if (first_name.length() > 10)
			{
				first_name = first_name.substr(0, 9) + ".";
			}
			std::cout << BLUE << std::setw(10) << std::right << first_name << "|" << RESET;

			std::string last_name = contacts[i].getLastName();
			if (last_name.length() > 10)
			{
				last_name = last_name.substr(0, 9) + ".";
			}
			std::cout << BLUE << std::setw(10) << std::right << last_name << "|" << RESET;

			std::string nickname = contacts[i].getNickName();
			if (nickname.length() > 10)
			{
				nickname = nickname.substr(0, 9) + ".";
			}
			std::cout << BLUE << std::setw(10) << std::right << nickname << "\n" << RESET;
		}
		std::cout << "\n";
	}
}

void PhoneBook::displaySingleContact(int index) const
{
	if (contactCount == 0)
	{
		std::cout << RED << "Error. PhoneBook is Empty\n" << RESET;
		return ;
	}
	else
	{
		std::cout << "\n";
		for (int i = 0; i < contactCount; i++)
		{
			if (i == index)
			{
				std::cout << GREEN << "Found Contact" << RESET << std::endl;
				std::cout << BLUE << "----------------------------\n" << RESET << std::endl;
				std::cout << BLUE << "First Name: " << contacts[i].getFirstName() << RESET << std::endl;
				std::cout << BLUE << "Last Name: " << contacts[i].getLastName() << RESET << std::endl;
				std::cout << BLUE << "Nick Name: " << contacts[i].getNickName() << RESET << std::endl;
				std::cout << BLUE << "Phone Number: " << contacts[i].getPhoneNumber() << RESET << std::endl;
				std::cout << BLUE << "\n----------------------------" << RESET << std::endl;
			}
		}
		std::cout << "\n";
	}
}

int PhoneBook::getContactCount()
{
	return (contactCount);
}
