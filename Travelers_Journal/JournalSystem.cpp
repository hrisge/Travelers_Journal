#include "JournalSystem.h"

void JournalSystem::free()
{
	delete[] users;
	size = 0;
	capacity = 0;
	loggedIn = 0;
	isLoggedIn = false;
}
void JournalSystem::copyFrom(const JournalSystem& journalSystem)
{
	users = new User[journalSystem.getCapacity()];
	
	for (size_t i = 0; i < journalSystem.getSize(); ++i)
		users[i] = journalSystem.users[i];

	size = journalSystem.getSize();
	capacity = journalSystem.getCapacity();
	loggedIn = journalSystem.getIsLoggedIn();
	isLoggedIn = journalSystem.getIsLoggedIn();
}

void JournalSystem::loadUsersData()
{
	MyString ext = ".db";
	for (size_t i = 0; i < getSize(); ++i)
	{
		MyString fileName = users[i].getUsername();
		fileName.concat(ext);

		std::ifstream inputFile(fileName.getString());

		if (!inputFile.is_open())
			continue;

		addUserData(inputFile, i);

		inputFile.close();
	}
}
void JournalSystem::saveUsersData(size_t index)
{
	MyString ext = ".db";
	MyString fileName = getUsers()[index].getUsername();
	fileName.concat(ext);

	std::ofstream outputFile(fileName.getString(), std::ios::out | std::ios::trunc);

	if (!outputFile.is_open())
		return;

	for (size_t i = 0; i < getUsers()[index].getUsersDataBase().getSize(); ++i)
	{
		outputFile << getUsers()[index].getUsersDataBase().getDataBase()[i].getDestination() << '$' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getTimeArrival().getYear() << '-' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getTimeArrival().getMonth() << '-' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getTimeArrival().getDay() << ' ' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getTimeDeparture().getYear() << '-' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getTimeDeparture().getMonth() << '-' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getTimeDeparture().getDay() << '$' <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getGrade() <<
			getUsers()[index].getUsersDataBase().getDataBase()[i].getComment() << '$';
		for (size_t k = 0; k <= (int)getUsers()[index].getUsersDataBase().getDataBase()[i].getPhotos().getSize()-1; ++k)
		{
			outputFile << getUsers()[index].getUsersDataBase().getDataBase()[i].getPhotos().getArray()[k].getString()<<'#';
		}
		outputFile << getUsers()[index].getUsersDataBase().getDataBase()[i].getPhotos().getArray()[getUsers()[index].getUsersDataBase().getDataBase()[i].getPhotos().getSize() - 1].getString() << '\n';
	}
}
void JournalSystem::addUserData(std::ifstream& inputFile, size_t index)
{
	char buffDest[MAX_BUFF_SIZE];

	char buffYear[MAX_NUMBER_LEN];
	char buffMonth[MAX_NUMBER_LEN];
	char buffDay[MAX_NUMBER_LEN];

	char buffMonth2[MAX_NUMBER_LEN];
	char buffDay2[MAX_NUMBER_LEN];
	char buffYear2[MAX_NUMBER_LEN];

	char buffGrade[MAX_NUMBER_LEN];
	char buffComment[MAX_BUFF3];
	char buffPhotos[MAX_BUFF3];

	inputFile.getline(buffDest, MAX_BUFF_SIZE, '$');

	inputFile.getline(buffYear, MAX_NUMBER_LEN, '-');
	inputFile.getline(buffMonth, MAX_NUMBER_LEN, '-');
	inputFile.getline(buffDay, MAX_NUMBER_LEN, ' ');

	inputFile.getline(buffYear2, MAX_NUMBER_LEN, '-');
	inputFile.getline(buffMonth2, MAX_NUMBER_LEN, '-');
	inputFile.getline(buffDay2, MAX_NUMBER_LEN, '$');

	inputFile.getline(buffGrade, MAX_NUMBER_LEN, '$');
	inputFile.getline(buffComment, MAX_BUFF3, '$');
	inputFile.getline(buffPhotos, MAX_BUFF3);

	Data buff;
	buff.setDestination(buffDest);
	buff.setTimeArr(convertCharToInt(buffYear), convertCharToInt(buffMonth), convertCharToInt(buffYear));
	buff.setTimeDep(convertCharToInt(buffYear2), convertCharToInt(buffMonth2), convertCharToInt(buffYear2));
	buff.setGrade(convertCharToInt(buffGrade));
	buff.setComment(buffComment);
	buff.setPhotosFromList(buffPhotos);


	users[index].addData(buff);
}

void JournalSystem::resize()
{
	capacity *= 2;
	if (capacity == 0)
		capacity = 4;
	User* buff = new User[getCapacity()];
	for (size_t i = 0; i < getSize(); ++i)
		buff[i] = users[i];
	delete[] users;
	users = buff;
}

JournalSystem::JournalSystem()
{
	std::ifstream inputFile(usersFile);
	
	if (!inputFile.is_open())
		return;

	users = new User[4];
	capacity = 4;
	size = 0;

	while (!inputFile.eof())
	{
		if (getSize() == getCapacity())
			resize();


		char buffUsername[MAX_BUFF_SIZE];
		char buffPassword[MAX_BUFF_SIZE];
		char buffEmail1[MAX_BUFF_SIZE];
		char buffEmail2[MAX_BUFF2];
		char buffEmail3[MAX_BUFF2];


		inputFile.getline(buffUsername, MAX_BUFF_SIZE, '$');
		inputFile.getline(buffPassword, MAX_BUFF_SIZE, '$');
		inputFile.getline(buffEmail1, MAX_BUFF_SIZE, '@');
		inputFile.getline(buffEmail2, MAX_BUFF2, '.');
		inputFile.getline(buffEmail3, MAX_BUFF2);

		users[getSize()].setUsername(buffUsername);
		users[getSize()].setPassword(buffPassword);
		users[getSize()].setEmail(buffEmail1, buffEmail2, buffEmail3);

		++size;
	}

	inputFile.close();
}
JournalSystem::JournalSystem(const JournalSystem& journalSystem)
{
	copyFrom(journalSystem);
}
JournalSystem::JournalSystem(JournalSystem&& journalSystem)
{
	users = journalSystem.users;
	size = journalSystem.size;
	capacity = journalSystem.capacity;
	loggedIn = journalSystem.loggedIn;
	isLoggedIn = journalSystem.isLoggedIn;

	journalSystem.users = nullptr;
	journalSystem.size = 0;
	journalSystem.capacity = 0;
	journalSystem.loggedIn = 0;
	journalSystem.isLoggedIn = false;
}
JournalSystem::~JournalSystem()
{
	free();
}

const User* JournalSystem::getUsers() const
{
	return users;
}
size_t JournalSystem::getSize() const
{
	return size;
}
size_t JournalSystem::getCapacity() const
{
	return capacity;
}
size_t JournalSystem::getLoggedIn() const
{
	return loggedIn;
}
bool JournalSystem::getIsLoggedIn() const
{
	return isLoggedIn;
}

void JournalSystem::addUser(const User& user)
{
	if (getSize() == getCapacity())
		resize();

	users[getSize()] = user;
	++size;
}
void JournalSystem::save()
{
	std::ofstream outFile(usersFile, std::ios::trunc);

	if (!outFile.is_open())
		return;

	for (size_t i = 0; i < getSize(); ++i)
	{
		outFile << getUsers()[i].getUsername() << '$' << getUsers()[i].getPassword() << '$' << getUsers()[i].getEmail();
		saveUsersData(i);
	}
	outFile.close();
}

void JournalSystem::addAJourney(const MyString& destination, const CalendarTime& arrTime, const CalendarTime& depTime, 
	size_t grade, const MyString& comment, const ArrayOfStrings& photos)
{
	Data buff;
	buff.setDestination(destination);
	buff.setTimeArr(arrTime);
	buff.setTimeDep(depTime);
	buff.setGrade(grade);
	buff.setComment(comment);
	buff.setPhotos(photos);

	users[getLoggedIn()].addData(buff);
}

void JournalSystem::logOut()
{
	loggedIn = 0;
	isLoggedIn = 0;
}


bool JournalSystem::checkLogIn(MyString& username, MyString& password)
{
	for (size_t i = 0; i < getSize(); i++)
	{
		if (getUsers()[i].getUsername() == username)
		{
			if (getUsers()[i].getPassword() == password)
			{
				isLoggedIn = true;
				loggedIn = i;

				return true;
			}

		}
	}
	return false;
}

bool JournalSystem::checkUser(MyString& username)
{
	for (size_t i = 0; i < getSize(); i++)
		if (getUsers()[i].getUsername() == username)
			return false;

	return true;
}
