#include <iostream>
#include <cstdlib>

using std::string;

class AbstractEmployee{
    virtual void AskPromotion() = 0;
};

class Employee: AbstractEmployee{
    private:
        string Company;
        int Age;
    protected:
        string Name;
    public:
        void changeName(string name) {
            Name = name;
        }
        string getName() {
            return Name;
        }
        void changeCompany(string company) {
            Company = company;
        }
        string getCompany() {
            return Company;
        }
        void changeAge(int age) {
            Age = age;
        }
        int getAge() {
            return Age;
        }
        void Introduction() {
            std::cout << "Name - " << this->Name << std::endl;
            std::cout << "Company - " << this->Company << std::endl;
            std::cout << "Age - " << this->Age << std::endl;
        }
        Employee(string name, string company, int age) {
            Name = name;
            Company = company;
            Age = age;
        }
        void AskPromotion() {
            if(Age>30){
                std::cout << Name << " got promoted!" << std::endl;
            } else {
                std::cout << Name << ", No promotion" << std::endl;
            }
        };
        virtual void Work() {
            std::cout<<Name<<" is checking email, task backlog, performing tasks..." << std::endl;
        }
};

class Developer:public Employee {
    public:
        string FavoritePLang;
        Developer(string name, string company, int age, string favoritePLang):Employee(name, company, age) {
            FavoritePLang = favoritePLang;
        }
        void FixBug() {
            std::cout << Name << " fixed a bug using "<< FavoritePLang <<std::endl;
        }
        void Work() {
            std::cout<<Name<<" is writing" << FavoritePLang << std::endl;
        }
};

class Teacher:public Employee {
    public:
        string Subject;
        Teacher(string name, string company, int age, string subject):Employee(name, company, age) {
            Subject = subject;
        }
        void PrepareLesson() {
            std::cout<<Name<<" is preparing " << Subject << "lesson " << std::endl;
        }
        void Work() {
            std::cout<<Name<<" is lessoning " << Subject << std::endl;
        }
};

int main() {
    Employee employeeOne = Employee("Fabricio", "SAP", 23);
    Employee employeeTwo = Employee("Felipe", "SAP", 31);

    Developer developerOne = Developer("Fabricio", "SAP", 23, "Rust");

    Teacher teacherOne = Teacher("Jesse", "Liberato", 22, "Physics");

    // employeeOne.AskPromotion();
    // employeeTwo.AskPromotion();

    // developerOne.FixBug();
    // developerOne.AskPromotion();

    // teacherOne.PrepareLesson();
    // teacherOne.AskPromotion();

    // teacherOne.Work();
    // developerOne.Work();

    Employee *eOne=&developerOne;
    Employee *eTwo=&teacherOne;

    eOne->Work();
    eTwo->Work();

    // employeeOne.Introduction();
    // employeeOne.changeName("Fabricio Rubo Machado");
    // employeeOne.Introduction();
    //employeeTwo.Introduction();

    std::cin.ignore();
    return 0;
}