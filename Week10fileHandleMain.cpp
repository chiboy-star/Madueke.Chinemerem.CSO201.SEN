#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio> // for remove and rename
using namespace std;

struct Student {
    char name[50];
    int age;
};

int main() {
    // 1. Create and write to file
    ofstream file("data.txt");
    file << "Hello World!\nWelcome to C++ File Handling\n";
    file.close();

    // 2. Append to file
    ofstream file_append("data.txt", ios::app);
    file_append << "This line is appended.\n";
    file_append.close();

    // 3. Read file line by line
    ifstream file_read("data.txt");
    string line;
    cout << "--- File Content (lines) ---\n";
    while(getline(file_read, line)) cout << line << endl;
    file_read.close();

    // 4. Read word by word
    ifstream file_words("data.txt");
    string word;
    cout << "\n--- Words ---\n";
    while(file_words >> word) cout << word << endl;
    file_words.close();

    // 5. Count lines
    ifstream file_count("data.txt");
    int count = 0;
    while(getline(file_count, line)) count++;
    cout << "\nTotal lines: " << count << endl;
    file_count.close();

    // 6. Binary file write/read
    Student s1 = {"Alice", 20};
    ofstream bin_out("student.dat", ios::binary);
    bin_out.write((char*)&s1, sizeof(s1));
    bin_out.close();

    Student s2;
    ifstream bin_in("student.dat", ios::binary);
    bin_in.read((char*)&s2, sizeof(s2));
    cout << "\nBinary read: " << s2.name << ", " << s2.age << endl;
    bin_in.close();

    // 7. Copy file
    ifstream src("data.txt");
    ofstream dest("copy.txt");
    while(getline(src, line)) dest << line << endl;
    src.close();
    dest.close();

    // 8. Rename file
    rename("copy.txt", "renamed.txt");

    // 9. Delete file
    //remove("data.txt");

    // 10. Logging timestamps
    ofstream log("log.txt", ios::app);
    time_t now = time(0);
    log << ctime(&now) << " - Program executed\n";
    log.close();

    cout << "\nAll file operations executed successfully!\n";
    return 0;
}
