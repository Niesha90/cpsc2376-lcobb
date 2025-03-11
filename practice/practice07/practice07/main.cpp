#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Base class: Employee
class Employee {
protected:
    std::string name;
    int id;
public:
    Employee(const std::string& n, int i) : name(n), id(i) {}
    virtual ~Employee() = default;
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

// Derived: SalariedEmployee
class SalariedEmployee : public Employee {
    double monthlySalary;
public:
    SalariedEmployee(const std::string& n, int i, double s)
        : Employee(n, i), monthlySalary(s) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        std::cout << "ID: " << id
            << ", Name: " << name
            << ", Type: Salaried, Monthly Salary: $"
            << monthlySalary << "\n";
    }
};

// Derived: HourlyEmployee
class HourlyEmployee : public Employee {
    double hourlyRate;
    int hoursWorked;
public:
    HourlyEmployee(const std::string& n, int i, double r, int h)
        : Employee(n, i), hourlyRate(r), hoursWorked(h) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        double salary = calculateSalary();
        std::cout << "ID: " << id
            << ", Name: " << name
            << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << hourlyRate
            << ", Salary: $" << salary << "\n";
    }
};

// Derived: CommissionEmployee
class CommissionEmployee : public Employee {
    double baseSalary, salesAmount, commissionRate;
public:
    CommissionEmployee(const std::string& n, int i,
        double baseSal, double s, double c)
        : Employee(n, i), baseSalary(baseSal),
        salesAmount(s), commissionRate(c) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        double salary = calculateSalary();
        double ratePercent = commissionRate * 100;
        std::cout << "ID: " << id
            << ", Name: " << name
            << ", Type: Commission, Base Salary: $" << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << ratePercent << "%"
            << ", Salary: $" << salary << "\n";
    }
};

int main() {
    // Open file
    std::ifstream inFile("employees.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open employees.txt\n";
        return 1;
    }

    std::vector<Employee*> employees;
    std::string type;
    int eid;
    std::string ename;

    while (inFile >> type >> eid >> ename) {
        if (type == "Salaried") {
            double sal;
            if (inFile >> sal) {
                employees.push_back(new SalariedEmployee(ename, eid, sal));
            }
        }
        else if (type == "Hourly") {
            double rate;
            int hours;
            if (inFile >> rate >> hours) {
                employees.push_back(new HourlyEmployee(ename, eid, rate, hours));
            }
        }
        else if (type == "Commission") {
            double baseSal, salesAmt, cRate;
            if (inFile >> baseSal >> salesAmt >> cRate) {
                employees.push_back(
                    new CommissionEmployee(ename, eid, baseSal, salesAmt, cRate));
            }
        }
    }
    inFile.close();

    // Display all info
    std::cout << "Employee Information:\n";
    for (Employee* emp : employees) {
        emp->displayInfo();
    }

    // Clean up
    for (Employee* emp : employees) {
        delete emp;
    }
    return 0;
}