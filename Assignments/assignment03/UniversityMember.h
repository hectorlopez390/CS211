#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H
#include <string>
using namespace std;

class UniversityMember
{
 protected:
  long id;
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:
  long getId();
  string getName();
  string getEmail();
  string getAddress();
  string getDateOfBirth();
  string getGender();
};

#endif //UNIVERSITYMEMBER_H
