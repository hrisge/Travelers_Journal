#pragma once
#include "JournalSystem.h"

void system();

void logIn(JournalSystem&);
void registerNewUser(JournalSystem&);
void addNewTrip(JournalSystem&);
void viewTrips(const JournalSystem&);
void viewDestinationAverageGrade(const JournalSystem&);
void exit(JournalSystem&);
void logOut(JournalSystem&);
void help(JournalSystem&);
void searchByDestination(const JournalSystem&);

void printJourneyInfo(const JournalSystem&, unsigned, unsigned);
