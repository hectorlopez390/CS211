#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
using namespace std;

class Department
{
 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId;
 public:
  Department();
  Department(string depName, string depLoc, long depChairId);
  void setDepartmentInfo(string depName, string depLoc, long depChairId);
  long getId();
  string getName();
  string getLocation();
  void setChairId(long depChairId);
  long getChairId();
  long getNextDepId();
  void print() const;
};

#endif //DEPARTMENT_H
