#include "System.h"

void system()
{
	JournalSystem journalSystem;

	MyString command;
	std::cout << "Please enter a command. If you need help enter help. Command: ";
	std::cin >> command;
}

void logIn(JournalSystem& journalSystem)
{
	if (!journalSystem.getIsLoggedIn())
	{
		std::cout << "You are already logged in as " << journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsername();
		return;
	}

	MyString username;
	MyString password;

	system("CLS");
	std::cout << "Please enter your username: ";
	std::cin >> username;
	std::cout << "Please enter your passsword: ";
	enteringPassword(password);
	
	bool logIn = journalSystem.checkLogIn(username, password);
	if (logIn)
	{
		std::cout << "\nYou logged in successfully! \n";
		return;
	}
	
	std::cout << "\nThere is no such user with those username and password. Please try again! \n";
}
void registerNewUser(JournalSystem& journalSystem)
{
	if (!journalSystem.getIsLoggedIn())
	{
		std::cout << "You are already logged in as " << journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsername();
		return;
	}

	MyString username;
	MyString password;
	Email email;

	system("CLS");
	std::cout << "Please enter your username: ";
	std::cin >> username;
	std::cout << "Please enter your passsword: ";
	enteringPassword(password);
	std::cout << "\nPlease enter your Email: ";
	std::cin >> email;

	bool logIn = journalSystem.checkUser(username);
	if (logIn)
	{
		User buff;
		buff.setUsername(username);
		buff.setPasword(password);
		buff.setEmail(email);

		journalSystem.addUser(buff);
		std::cout << "\nUser registered successfully! \n";
		return;
	}

	std::cout << "\nThere is already such User! Try again! \n";


}
void addNewTrip(JournalSystem& journalSystem)
{
	if (!journalSystem.getIsLoggedIn())
	{
		std::cout << "\nYou are not logged in! \n";
		return;
	}

	system("ClS");
	
	MyString destination;
	CalendarTime arrTime;
	CalendarTime depTime;
	size_t grade;
	MyString comment;
	ArrayOfStrings photos;
	size_t numberOfPhotos;


	std::cout << "Enter your destination: ";
	std::cin >> destination;
	std::cout << "\nEnter your arrival Time in the format dd-mm-yyyy : ";
	std::cin >> arrTime;
	std::cout << "\nEnter your departure Time in the format dd-mm-yyyy : ";
	std::cin >> depTime;
	std::cout << "\nEnter your grade for the journer between 1 and 5 : ";
	std::cin >> grade;
	std::cout << "\nEnter your comment about the journey : ";
	std::cin >> comment;
	std::cout << "\nEnter the number of photos you would like to attach: ";
	std::cin >> numberOfPhotos;

	for (size_t i = 0; i < numberOfPhotos; ++i)
	{
		std::cout << "Enter photo. Photo could be only .jpeg and .png! : ";
		MyString photo;
		std::cin >> photo;
		photos.addString(photo);
	}

	journalSystem.addAJourney(destination, arrTime, depTime, grade, comment, photos);
}
void viewTrips(JournalSystem& journalSystem)
{
	system("CLS");
	if (!journalSystem.getIsLoggedIn())
	{
		std::cout << "\nYou are not logged in! \n";
		return;
	}

	size_t numberOfTrips = journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getSize();

	if (numberOfTrips == 0)
	{
		std::cout << "\nYou do not have any trips recorded!\n";
		return;
	}

	std::cout << "Your journeys are: \n";
	for (size_t i = 0; i < numberOfTrips; ++i)
	{
		std::cout << "Journey Number " << i << "\nDestination:" <<
			journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getDestination() << "\nTime Period: " <<
			journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getTimeArrival() << " " <<
			journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getTimeDeparture() << "\nGrade: " <<
			journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getGrade() << "\nComment: " <<
			journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getComment() << "\nPhotos: ";
		for (size_t k = 0; k < journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getPhotos().getSize(); ++i)
			std::cout << journalSystem.getUsers()[journalSystem.getLoggedIn()].getUsersDataBase().getDataBase()[i].getPhotos().getArray()[k] << " ";
		std::cout << std::endl;
	}
}
void viewDestinationAverageGrade(JournalSystem& journalSystem)
{
	system("CLS");
	if (!journalSystem.getIsLoggedIn())
	{
		std::cout << "\nYou are not logged in! \n";
		return;
	}

	std::cout << "Enter the destination you want to check: ";
	MyString destination;
	std::cin >> destination;

	size_t numberOfTimesVisited = 0;
	double gradeSum = 0;
	double average = 0;
	for (size_t i = 0; i < journalSystem.getSize(); ++i)
	{
		for(size_t k=0;k<journalSystem.getUsers()[i].getUsersDataBase().getSize();++k)
			if (journalSystem.getUsers()[i].getUsersDataBase().getDataBase()[k].getDestination() == destination)
			{
				gradeSum += journalSystem.getUsers()[i].getUsersDataBase().getDataBase()[k].getGrade();
				++numberOfTimesVisited;
			}
	}
	average = gradeSum / numberOfTimesVisited;
	std::cout << destination << "'s average grade is " << average;
}
void exit(JournalSystem& journalSystem)
{
	journalSystem.save();
}

void logOut(JournalSystem& journalSystem)
{
	journalSystem.logOut();
}

void help(JournalSystem& journalSystem)
{
	if (!journalSystem.getIsLoggedIn())
		std::cout << "If you want to log in type: log in!" << std::endl << "If you want to register new user type: register!" << std::endl;
	else
	{
		std::cout << "If you want to add a new trip: add a new trip!" << std::endl;
		std::cout << "If you want to view trips: view trips!" << std::endl;
		std::cout << "If you want to view the average destination grade: average grade!" << std::endl;
		std::cout << "If you want to exit: exit!" << std::endl;
	}
}

void enteringPassword(MyString& password)
{
	size_t cnt = 0;
	char ch;
	while (true)
	{
		std::cin >> ch;
		if (ch == '\n')
			break;
		password.concatChar(ch);
		++cnt;
		system("CLS");
		std::cout << "Please enter yout passsword: ";
		for (size_t i = 0; i < cnt; ++i)
			std::cout << '*';
	}
}