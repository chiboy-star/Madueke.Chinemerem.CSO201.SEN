#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int loadData(const char filename[],int ids[], int scores[], int maxSize){
    ifstream file(filename);
    //This returns an error if the file does not exist
    if (!file) {
        cout << "Error: Could not open file " << filename << endl;
        return 0;
    }
    //This skips the header of the file
    string header;
    getline(file, header);
    int count = 0;
    while (count < maxSize && file >> ids[count]) {
        char comma;
        file >> comma;//stores the comma after the student id   
        file >> scores[count];//stores the score of the student 
        count++;
    }
    file.close();
    return count;//Returns the number of students loaded
}
void printAll(int ids[], int scores[], int size) {
    for(int i =0; i <size; i++){
        //This prints out all the students in this file with the respective score
        cout<<"StudentID: "<<ids[i]<<" Score: "<< scores[i]<<endl;
    }
}
// The & in the varables below does Pass-by-Reference and changes the vaules in main()
void computeStats(int scores[], int size, double &average, int &minScore, int &maxScore){
    int sum = 0;
    maxScore = scores[0];
    minScore = scores[0];
    for(int i = 0; i<size; i++){
        //Get the max score
        if(scores[i] > maxScore){
            maxScore = scores[i];
        }
        //Get the min score
        if(scores[i] < minScore){
            minScore = scores[i];
        }
        //Get the sum of scores
        sum = sum + scores[i];
    }
    //type casting. Find the average if the scores in the file
    average = (double)sum/size;
}   
void computeGradeDistribution(int scores[], int size, int &countA, int &countB, int &countC, int &countD, int &countF){
    //Counts the number of people that got a certain grade depending on what score the person has
    for(int i = 0; i < size;i++){
        if(scores[i] >=70){
            countA++;
        }else if(scores[i] >= 60){
            countB++;
        }else if(scores[i] >= 50){
            countC++;
        }else if(scores[i] >= 45){
            countD++;
        }else{
            countF++;
        }
    }
}
int pickRandomPassingStudent(int ids[], int scores[], int size){
    int passingIndices[100];
    int pCount = 0;
    for (int i = 0; i < size; i++) {
        if (scores[i] >= 50) {
            passingIndices[pCount++] = i;
        }
    }
    if (pCount == 0) return -1;
    int randomIndex = rand() % pCount;
    return passingIndices[randomIndex];
}
void saveSummary(const char filename[], double average, int minScore, int maxScore, int countA, int countB, int countC, int countD, int countF){
    ofstream file(filename);
    if (!file) {
        cout << "Error creating summary file.\n";
        return;
    }
    file << "Metric,Value\n";
    file << "Average Score," << average << "\n";
    file << "Minimum Score," << minScore << "\n";
    file << "Maximum Score," << maxScore << "\n";
    file << "A Count," << countA << "\n";
    file << "B Count," << countB << "\n";
    file << "C Count," << countC << "\n";
    file << "D Count," << countD << "\n";
    file << "F Count," << countF << "\n";
    file.close();
}
int main(){
    srand(time(0));   
    const int MAX = 100;
    int ids[MAX];
    int scores[MAX];
    int size = loadData("socre.csv", ids, scores, MAX);
    cout << "Total number of students: " << size << "\n";
    printAll(ids, scores, size);    
    double average;
    int minScore, maxScore;
    computeStats(scores, size, average, minScore, maxScore);
    cout << "\nAverage Score: " << average << endl;
    cout << "Minimum Score: " << minScore << endl;
    cout << "Maximum Score: " << maxScore << endl;
    int countA, countB, countC, countD, countF;
    computeGradeDistribution(scores, size,countA, countB, countC,countD, countF);
    cout << "\nGrade Distribution:\n";
    cout << "A: " << countA << endl;
    cout << "B: " << countB << endl;
    cout << "C: " << countC << endl;
    cout << "D: " << countD << endl;
    cout << "F: " << countF << endl;    
    int pick = pickRandomPassingStudent(ids, scores, size);
    cout << "\nRandom Passing Student: ";
    if (pick == -1)
        cout << "No passing students.\n";
    else
        cout << "StudentID = " << ids[pick]<< "  Score = " << scores[pick] << endl;
    saveSummary("summary.csv", average, minScore, maxScore, countA, countB, countC, countD, countF);
    cout << "\nsummary.csv has been created successfully.\n";
    return 0; 
}