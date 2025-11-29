#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));  // seed random number generator

    string fullName;
    bool isPauStudent;
    int course = 0, location = 0;
    string courseName, locationName;
    int days = 0, regfee = 0, lodgingPerDay = 0;
    double lodgeDiscount = 0, regDiscount = 0;
    int promo = 0;
    int i = 1;

    while (i!=0) {
        // Get input
        cin.ignore();
        cout << "Enter Full Name ===> ";
        getline(cin, fullName);

        cout << "Is PAU student? (1 = yes, 0 = no): ";
        int temp;
        cin >> temp;
        isPauStudent = (temp != 0);

        cout << "\nEnter course (1–5):\n"
             << "\t1. Photography\n"
             << "\t2. Painting\n"
             << "\t3. Fish Farming\n"
             << "\t4. Baking\n"
             << "\t5. Public Speaking\n"
             << "Enter here ===> ";
        cin >> course;

        cout << "\nEnter location (1–5):\n"
             << "\t1. Camp House A\n"
             << "\t2. Camp House B\n"
             << "\t3. Camp House C\n"
             << "\t4. Camp House D\n"
             << "\t5. Camp House E\n"
             << "Enter here ===> ";
        cin >> location;

        // Course selection
        switch (course) {
            case 1:
                courseName = "Photography";
                days = 3;
                regfee = 10000;
                break;
            case 2:
                courseName = "Painting";
                days = 5;
                regfee = 8000;
                break;
            case 3:
                courseName = "Fish Farming";
                days = 7;
                regfee = 15000;
                break;
            case 4:
                courseName = "Baking";
                days = 5;
                regfee = 13000;
                break;
            case 5:
                courseName = "Public Speaking";
                days = 2;
                regfee = 5000;
                break;
            default:
                cout << "Invalid course number!" << endl;
                continue;
        }

        // Location selection
        switch (location) {
            case 1:
                locationName = "Camp House A";
                lodgingPerDay = 10000;
                break;
            case 2:
                locationName = "Camp House B";
                lodgingPerDay = 2500;
                break;
            case 3:
                locationName = "Camp House C";
                lodgingPerDay = 5000;
                break;
            case 4:
                locationName = "Camp House D";
                lodgingPerDay = 13000;
                break;
            case 5:
                locationName = "Camp House E";
                lodgingPerDay = 5000;
                break;
            default:
                cout << "Invalid location number!" << endl;
                continue;
        }

        int lodgingCost = lodgingPerDay * days;

        // Apply discounts
        if (isPauStudent && (location == 1 || location == 2)) {
            lodgeDiscount = 0.05 * lodgingCost;
            lodgingCost -= lodgeDiscount;
        }

        if ((days > 5) || (regfee > 12000)) {
            regDiscount = 0.03 * regfee;
            regfee -= regDiscount;
        }

        // Promo random
        int r = rand() % 100 + 1;
        if (r == 7 || r == 77)
            promo = 500;

        // Final total
        int total = regfee + lodgingCost - promo;

        // Output
        cout << "\n===== CAMP REGISTRATION RECEIPT =====\n";
        cout << "Name: " << fullName
             << "   (PAU student: " << (isPauStudent ? "Yes" : "No") << ")\n";
        cout << "Course: " << courseName << "   Days: " << days << endl;
        cout << "Registration: " << regfee << "  (Reg discount: " << regDiscount << ")\n";
        cout << "Lodging: " << lodgingPerDay << " × " << days
             << " = " << (lodgingPerDay * days)
             << "  (Lodging discount: " << lodgeDiscount << ")\n";
        cout << "Random draw: " << r << "  Promo applied: " << promo << endl;
        cout << "TOTAL: " << total << endl;
        cout << "=====================================\n";

        cout << "\nDo you want to register another person? (0->no/1->yes): ";
        cin >> i;
    }

    cout << "\nThank you for using the Camp Registration System!\n";
    return 0;
}
