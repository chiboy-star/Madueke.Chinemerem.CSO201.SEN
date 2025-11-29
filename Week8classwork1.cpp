#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // Input variables
    string full_name;
    int jamb;
    double waec;
    int age;
    int hostel_pref;
    bool firstChoice, disciplinary;
    //Input variables with base values
    double baseTuition = 1500000;
    double hostelFee = 0;
    double scholarship = 0;
    double meritGrant = 0;
    string admissionStatus;
    string hostel = "";
    // Random number maker
    int r = rand() % 100 + 1;
    // Input vaules to the varibales
    //Name
    cout << "Enter full name: ";
    getline(cin, full_name);
    //Jamb score
    cout << "Enter JAMB score: ";
    cin >> jamb;
    //Weac average
    cout << "Enter WAEC average: ";
    cin >> waec;
    //Age
    cout << "Enter age: ";
    cin >> age;
    //Was thier first choice pau
    cout << "First choice PAU? (1/0): ";
    int flag;
    cin >> flag;
    firstChoice = (flag == 1);//True if the user enters 1 otherwise false
    //record
    cout << "Any disciplinary record? (1/0): ";
    cin >> flag;
    disciplinary = (flag == 1);//True if the user enters 1 otherwise false
    //Hostel prefernce
    cout << "Hostel (1=Main, 2=Annex, 3=Day): ";
    cin >> hostel_pref;
    //Tasks 
/*
Admit if: 
(JAMB ≥ 220 && WAEC ≥ 60) AND firstChoice == true 
OR (JAMB ≥ 200 && WAEC ≥ 70) (exceptional WAEC can compensate) 
Reject if disciplinaryRecord == true OR age < 15. 
Otherwise, Pending.
*/
    if (disciplinary || age < 15) {
        admissionStatus = "Rejected";
    }
    else if ((jamb >= 220 && waec >= 60 && firstChoice) ||
             (jamb >= 200 && waec >= 70)) {
        admissionStatus = "Admitted";
    }
    else {
        admissionStatus = "Pending";
    }
/*
Multi-way if-else on JAMB: 
JAMB ≥ 320: 30% tuition scholarship 
JAMB ≥ 280: 20% 
JAMB ≥ 240: 10% 
else: 0% 
*/
    if (admissionStatus == "Admitted") {
        if (jamb >= 320) scholarship = 30;
        else if (jamb >= 280) scholarship = 20;
        else if (jamb >= 240) scholarship = 10;
        else scholarship = 0;
/*
Bonus rule using logical operators: 
If WAEC ≥ 80 && firstChoice == true, add extra 5% scholarship (cap total scholarship at 35%)
*/
        if (waec >= 80 && firstChoice) {
            scholarship += 5;
            if (scholarship > 35){
                 scholarship = 35;
            }
        }
    }
/*
If Admitted and no disciplinary record, accept the chosen hostel and set the corresponding hostelFee. 
If Pending → hostel is On Hold (₦0). 
If Rejected → hostel is Not Applicable (₦0). 
*/
    if (admissionStatus == "Admitted" && !disciplinary) {
        switch (hostel_pref) {
            case 1:
                hostel = "Main Hostel";
                hostelFee = 180000;
                break;
            case 2:
                hostel = "Annex Hostel";
                hostelFee = 120000;
                break;
            case 3:
                hostel = "Day Student";
                hostelFee = 0;
                break;
        }
    }
    else if (admissionStatus == "Pending") {
        hostel = "On Hold";
        hostelFee = 0;
    }
    else if (admissionStatus == "Rejected") { 
        hostel = "Not Applicable";
        hostelFee = 0;
    }
    /*
Generate r in [1, 100]. 
If r is a prime number ≤ 97 and the student is Admitted, apply a flat ₦50,000 grant (subtract from final payable). 
Print the generated number and whether the grant applied. 
(Tip: To stay within the outline, hard-code a bool like isPrime = (r==2 || r==3 || r==5 || ... || r==97); — no loops or arrays.) 
    */
    // MERIT GRANT
    bool isPrime =
        (r==2||r==3||r==5||r==7||r==11||r==13||r==17||r==19||r==23||r==29||
         r==31||r==37||r==41||r==43||r==47||r==53||r==59||r==61||r==67||
         r==71||r==73||r==79||r==83||r==89||r==97);

    if (admissionStatus == "Admitted" && isPrime) {
        meritGrant = 50000;
    }

    // TOTALS
    double tuitionAfterScholarship = baseTuition - (scholarship/100 * baseTuition);
    double totalPayable = tuitionAfterScholarship + hostelFee - meritGrant;

    if (totalPayable < 0) totalPayable = 0;

    // OUTPUT
    cout << "\nName: " << full_name << endl;
    cout << "Admission Status: " << admissionStatus << endl;
    cout << "Scholarship: " << scholarship << "%  Tuition After Scholarship: ₦" 
         << tuitionAfterScholarship << endl;
    cout << "Hostel: " << hostel << "  Fee: ₦" << hostelFee << endl;
    cout << "Random draw: " << r << "   Merit Grant: ₦" << meritGrant << endl;
    cout << "TOTAL PAYABLE: ₦" << totalPayable << endl;

    return 0;
}
