#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Appointment
{
protected:
  string description;
  string date;
  string apt_time;
public:
  Appointment(string desc, string date, string apt_time):description(desc), date(date), apt_time(apt_time)
  {

  }
  virtual void show()
  {
    
  }
  string getDesc()
  {
    return description;
  }
  string getTime()
  {
    return apt_time;
  }

};
class Daily:public Appointment
{

public:
Daily(string desc, string date, string apt_time):Appointment(desc,date,apt_time)
{
}
void show()
{std::cout << "Time: "<<apt_time<<" " <<description <<  "daily : "<<endl;
  
}

};
class Weekly:public Appointment
{

public:
Weekly(string desc, string date, string apt_time):Appointment(desc,date,apt_time)
{
}
void show()
{
  std::cout << "Time: "<<apt_time<<" " <<description << "weekly : "<<endl;
}

};
class Monthly:public Appointment
{

public:
Monthly(string desc, string date, string apt_time):Appointment(desc,date,apt_time)
{
}
void show()
{
  std::cout << "Time: "<<apt_time<<" " <<description << "monthly : "<<endl;
}

};


void allAppointments(std::vector<Appointment*> &apts)
{
  /**Fill here */
  /*for(auto appointment:apts)
  {
    cout<<appointment->getDesc();
  }*/
  for(int i=0;i<apts.size();i++)
  {
    apts[i]->show();
  }

}
void addAppointment(std::vector<Appointment*> &apts)
{
  /*create appointment here and push it in the apts*/
  string desc,date,timie;
int type;


  cout<<"description=";
  getline(cin,desc);
  getline(cin,desc);
  cout<<"date=";
  cin>>date;
  cout<<"time=";
  cin>>timie;


cout<<"*********** appointment type ***********"<<endl;
cout<<"(1) for Daily **************************"<<endl;
cout<<"(2) for Weekly *************************"<<endl;
cout<<"(3) for Monthly ************************"<<endl;
cin>>type;
switch(type){
case 1:
       apts.push_back(new Daily(desc,date,timie));
break;
case 2:
      apts.push_back(new Weekly(desc,date,timie));
break;
case 3:
      apts.push_back(new Monthly(desc,date,timie));
break;
default:
cout<<"invalid inputs"<<endl;
}
     

  
}

int main(int argc, char const *argv[]) {
    vector<Appointment*> apptRecord;

    char option;
    do {
       cout << "********** Appointment Book Application ************" << endl<< endl;
       cout << "(a) See all appointments on a given day." << endl;
       cout << "(b) Add an appointment." << endl << endl;
       cout << "Enter an option or 'q' to quit: ";

       cin >> option;
       switch(option){
  	    case 'a':
  			allAppointments(apptRecord);

              break;
  		case 'b':

  			addAppointment(apptRecord);
  		     break;
  		case 'q':
  		     break;
  		default:
  			cout << "You entered an invalid option.  Try again!";
       }
  	 cout << endl;
    }
    while(option != 'q');

  return 0;
}

