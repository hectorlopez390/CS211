#ifndef UNIVERSITY_CPP
#define UNIVERSITY_CPP
#include "UniversityMember.h"
#include <string>
long UniversityMember::getId()
{
  return id;
}
string UniversityMember::getName()
{
  return name;
}

string UniversityMember::getEmail()
{
  return email;
}

string UniversityMember::getAddress()
{
  return address;
}

string UniversityMember::getDateOfBirth()
{
  return dateOfBirth;
}

string UniversityMember::getGender()
{
  return gender;
}

#endif //UNIVERSITY_CPP
