#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;
class Course
{
 protected:
  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;

 public:
  Course();
  Course(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  void setCourseInfo(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  long getCRN();
  int getMaxAvailableSeats();
  string getName();
  long getDepartId();
  long getAssignedSeats();
  void setIsTaughtBy(long cTaughtBy);
  long getIsTaughtBy();
  long getNextCRN();
  void print() const;
};

#endif //COURSE_H
