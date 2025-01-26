#include "Phonebook.hpp"

Contact::Contact(const std::string &first, const std::string &last,
                 const std::string &nicknm, const std::string &phone)
    : firstName(first), lastName(last), nickName(nicknm), phoneNumber(phone)
{
}

void Contact::setDetails(const std::string &first, const std::string &last,
	const std::string &nicknm, const std::string &phone)
{
	firstName = first;
	lastName = last;
	nickName = nicknm;
	phoneNumber = phone;
}

void Contact::display() const
{
	std::cout << "Name: " << firstName << " " << lastName << "Nickname: " << nickName << "/ Phone: " << phoneNumber << std::endl;
}

std::string Contact::getFirstName() const
{
	return (firstName);
}

std::string Contact::getLastName() const
{
	return (lastName);
}

std::string Contact::getNickName() const
{
	return (nickName);
}

std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}