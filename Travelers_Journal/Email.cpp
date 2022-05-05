#include "Email.h"

Email::Email() : user(), adress(), host()
{
	
}
Email::Email(const char* username, const char* host, const char* adress)
{
	setUser(username);
	setHost(host);
	setAdress(adress);
}
Email::Email(const MyString& user, const MyString& host, const MyString& adress)
{
	setUser(user);
	setHost(host);
	setAdress(adress);
}

Email& Email::operator=(const Email& email)
{
	if (this != &email)
	{
		setUser(email.getUser());
		setHost(email.getHost());
		setAdress(email.getAdress());
	}
	return *this;
}

const MyString& Email::getUser() const
{
	return user;
}
const MyString& Email::getHost() const
{
	return host;
}
const MyString& Email::getAdress() const
{
	return adress;
}

void Email::setUser(const char* user)
{
	if (!isNameValid(user))
		return;

	this->user = user;
}
void Email::setUser(const MyString& user)
{
	if (!isNameValid(user))
		return;
	this->user = user;
}
void Email::setHost(const char* host)
{
	if (!isNameValid(host))
		return;
	this->host = host;
}
void Email::setHost(const MyString& host)
{
	if (!isNameValid(host))
		return;
	this->host = host;
}
void Email::setAdress(const char* adress)
{
	if (!isNameValid(adress))
		return;
	this->adress = adress;
}
void Email::setAdress(const MyString& adress)
{
	if (!isNameValid(adress))
		return;
	this->adress = adress;
}

bool isNameValid(const char* str)
{
	size_t len = strlen(str);
	for (size_t i = 0; i < len; i++)
	{
		if (!((str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] < 'Z') || (str[i] > '0' && str[i] < '9')))
			return false;
	}
	return true;
}
bool isNameValid(const MyString& str)
{
	size_t len = str.getStringLen();
	for (size_t i = 0; i < len; i++)
	{
		if (!((str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] < 'Z') || (str[i] > '0' && str[i] < '9')))
			return false;
	}
	return true;
}

std::istream& operator>>(std::istream& ifs, Email& email)
{
	char buff1[MAX_BUFF_SIZE];

	ifs.getline(buff1, MAX_BUFF_SIZE, '@');
	if (!isNameValid(buff1))
		return ifs;
	
	email.setUser(buff1);

	char buff2[MAX_BUFF_SIZE];

	ifs.getline(buff2, MAX_BUFF_SIZE, '.');
	if (!isNameValid(buff2))
		return ifs;

	email.setHost(buff2);

	char buff3[MAX_BUFF_SIZE];

	ifs.getline(buff3, MAX_BUFF_SIZE);
	if (!isNameValid(buff3))
		return ifs;

	email.setAdress(buff3);
	return ifs;
}
std::ostream& operator<<(std::ostream& ofs, Email& email)
{
	ofs << email.getAdress() << '@' << email.getHost() << '.' << email.getAdress() << '\n';
	return ofs;
}

