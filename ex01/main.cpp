#include <cctype>
#include <iostream>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string phoneNumber;

  public:
	Contact(const std::string &first = "", const std::string &last = "",
		const std::string &phone = "") : firstName(first), lastName(last),
		phoneNumber(phone)
	{
	}

	void setDetails(const std::string &first, const std::string &last,
		const std::string &phone)
	{
		firstName = first;
		lastName = last;
		phoneNumber = phone;
	}

	void display() const
	{
		std::cout << "Name: " << firstName << " " << lastName << ", Phone: " << phoneNumber << std::endl;
	}

	std::string getFirstName() const
	{
		return (firstName);
	}
	std::string getLastName() const
	{
		return (lastName);
	}
	std::string getPhoneNumber() const
	{
		return (phoneNumber);
	}
};

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Contact singleContact;

	singleContact.setDetails("Alice", "Smith", "123-456-7890");
	singleContact.display();
	return (0);
}