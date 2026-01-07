#include <iostream>
#include <string>

using namespace std;
//By default a class is private.

/*class Employee{ //A class is a building block of OOP. A Class is also a user defined data type
public:
	string Name;
	string Company;
	int Age;
	
	
	void introduceYourself(){
		cout<<"My name is "<<Name<<endl;
		cout<<"I work at "<<Company<<endl;
		cout<<"I am "<<Age<<"Years old"<<endl;
	}
};

int main(){
	Employee employee1;
	employee1.Name = "Dapo";
	employee1.Company = "PAU";
	employee1.Age = 29;
	employee1.introduceYourself();
}

	
	// A constructor is a special type of method that is invoked whenever we create a new object is created
	 TO create a constructor in c++ it follows 3 rules
	1. A constructor must have then same name as the class name
	2. A constructor does not have a return type.
	3. It must have a public access	 
	
	
	Pillars of OOP {Read Ift2 note}
	1. Encapsulation{getter and setter are used}
	2. absraction
	3. Inherence 
	4. Encapsulation:	*/
	
	
	
	

class Employee {
private:
    string Name;
    string Company;
    int Age;

public:
    // Constructor
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }

    // Getter methods
    string getName() {
        return Name;
    }

    string getCompany() {
        return Company;
    }

    int getAge() {
        return Age;
    }

    // Setter methods
    void setName(string name) {
        Name = name;
    }

    void setCompany(string company) {
        Company = company;
    }

    void setAge(int age) {
        Age = age;
    }

    // Method to introduce yourself
    void introduceYourself() {
        cout << "My name is " << Name << endl;
        cout << "I work at " << Company << endl;
        cout << "I am " << Age << " years old" << endl;
    }
};

int main() {
    Employee employee1("Dapo", "PAU", 29);
    employee1.introduceYourself();

    Employee employee2("Tolu", "TechCorp", 25);
    employee2.introduceYourself();

    // Using setter to change age
    employee1.setAge(39);

    // Using getter to access name and age
    cout << employee1.getName() << " is " << employee1.getAge() << " years old." << endl;

    return 0;
}


// For Cars

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string Brand;
    string Model;
    int Year;
    double Price;

public:
    // Constructor
    Car(string brand, string model, int year, double price) {
        Brand = brand;
        Model = model;
        setYear(year);   // use a setter for validation
        setPrice(price);
    }

    // Getters
    string getBrand() {
        return Brand;
    }

    string getModel() {
        return Model;
    }

    int getYear() {
        return Year;
    }

    double getPrice() {
        return Price;
    }

    // Setters with validation
    void setBrand(string brand) {
        Brand = brand;
    }

    void setModel(string model) {
        Model = model;
    }

    void setYear(int year) {
        if(year > 1885 && year <= 2026) { // first car invented in 1886
            Year = year;
        } else {
            cout << "Invalid year! Setting default year 2023." << endl;
            Year = 2023;
        }
    }

    void setPrice(double price) {
        if(price >= 0) {
            Price = price;
        } else {
            cout << "Invalid price! Setting default price 0." << endl;
            Price = 0;
        }
    }

    // Method to display car info
    void displayCarInfo() {
        cout << "Car: " << Brand << " " << Model << endl;
        cout << "Year: " << Year << endl;
        cout << "Price: $" << Price << endl;
    }
};

int main() {
    // Create car objects
    Car car1("Toyota", "Camry", 2020, 25000);
    Car car2("Tesla", "Model S", 2025, 120000);

    // Display info
    car1.displayCarInfo();
    cout << endl;
    car2.displayCarInfo();

    // Update car info using setters
    car1.setPrice(24000);
    car1.setYear(2021);

    cout << "\nAfter updates:" << endl;
    car1.displayCarInfo();

    return 0;
}
