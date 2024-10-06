/*
Trabalho Avaliativo 3:
Alunos: Gustavo Moro; João Vítor F. Goetz
*/


#include <iostream>
#include <string>

using namespace std;

class Person{
private:
    string Name;
    string BirthDate;
    string Sex;
public:
    Person(string name, string birthdate, string sex);
    string getName();
    string getBirthDate();
    string getSex();
};

class University{
private:
    string Uname;
public:
    University(string uname);
    string getUname();
};

class Student : public Person, public University{
private:
    string department;
public:
    Student(string name, string birthdate, string sex, string uname, string depart);
    string getDepartment();
};

class Teacher : public Person, public University{
private:
    string department;
    string course;
public:
    Teacher(string name, string birthdate, string sex, string uname, string depart, string crse);
    string getDepartment();
    string getCourse();
};

class TeachingAssistant: public Teacher, public Student{
public: 
    TeachingAssistant(string name, string birthdate, string sex, string uname, string departs, string departt, string crse);
};


int main()
{
    cout<<"--- Student ---"<<endl;
    Student aluno ("Paulo", "17/09/1990", "Male", "UFSC", "EMB");
    cout<<aluno.getName()<<endl;
    cout<<aluno.getBirthDate()<<endl;
    cout<<aluno.getSex()<<endl;
    cout<<aluno.getUname()<<endl;
    cout<<aluno.getDepartment()<<endl;
    cout<<"--- Teacher ---"<<endl;
    Teacher professor ("Rafael", "09/12/1970", "Male", "UFSC", "EMB", "Prog III");
    cout<<professor.getName()<<endl;
    cout<<professor.getBirthDate()<<endl;
    cout<<professor.getSex()<<endl;
    cout<<professor.getUname()<<endl;
    cout<<professor.getDepartment()<<endl;
    cout<<professor.getCourse()<<endl;
    cout<<"--- Teaching Assistant ---"<<endl;
    TeachingAssistant assistente ("Samira", "10/05/1990", "Female", "UFSC", "EMB", "EE", "Prog III");
    cout<<assistente.Student::getName()<<endl;
    cout<<assistente.Student::getBirthDate()<<endl;
    cout<<assistente.Student::getSex()<<endl;
    cout<<assistente.Student::getUname()<<endl;
    cout<<"Student's department"<<endl;
    cout<<assistente.Student::getDepartment()<<endl;
    cout<<"Teaching department"<<endl;
    cout<<assistente.Teacher::getDepartment()<<endl;
    cout<<assistente.getCourse()<<endl;
    return 0;
}

Person::Person(string name, string birthdate, string sex){
    Name = name;
    BirthDate = birthdate;
    Sex = sex;
}

string Person::getName(){
    return Name;
}

string Person::getBirthDate(){
    return BirthDate;
}

string Person::getSex(){
    return Sex;
}

University::University(string uname){
    Uname = uname;
}

string University::getUname(){
    return Uname;
}

Student::Student(string name, string birthdate, string sex, string uname, string depart):
        Person(name, birthdate, sex), University(uname){
    department = depart;
}

string Student::getDepartment(){
    return department;
}

Teacher::Teacher(string name, string birthdate, string sex, string uname, string depart, string crse):
        Person(name, birthdate, sex), University(uname){
    department = depart;
    course = crse;
}

string Teacher::getDepartment(){
    return department;
}

string Teacher::getCourse(){
    return course;
}

TeachingAssistant::TeachingAssistant(string name, string birthdate, string sex, string uname, string departs, string departt, string crse):
        Student(name, birthdate, sex, uname, departs), Teacher(name, birthdate, sex, uname, departt, crse){
            
}