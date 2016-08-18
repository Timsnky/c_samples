#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
ifstream inputFile;
ofstream outputFile;

double carResults [30][5];

string carDetails [3];
int units = 1;
int readFile = 1;
int totalData;
string data;
double averageVelocity;
double averageAcceleration;
double maxVelocity;
double maxAcceleration;

void readFiles();
void outputArray();
void splitString(string fileLine, int lineNumber);
void calculateVelocities();
double velocity(int i);
void conversion(int i);
double acceleration(int i);
double average(int column);
double maximum(int column);
void outputToFile(string path);

int main()
{
    int repeat = 0;
    string path;
    do{
        cout << "Please select the file you wish to Read:\n1. CAR1\n2. CAR2\n3. CAR3\n4. CAR4\n";
        cin >> readFile;
        cout << "Please specify the Standard Units:\n1. Feet per second\n2. Meters per second\n";
        cin >> units;

        readFiles();
        calculateVelocities();
        averageVelocity = average(3);
        averageAcceleration = average(4);
        maxVelocity = maximum(3);
        maxAcceleration = maximum(4);
        cout << "Please provide the name of the output file:\n";
        cin >> path;
        path += ".dat";
        cout << "Please find the output file on the root folder of the program\n";

        outputToFile(path);

        cout << "Would you like to select another file?\n1. Yes\n2. No\n";
        cin >> repeat;
        totalData = 0;
    }while(repeat == 1);
}

void readFiles(){
    string fileLine;
    int lineNumber = 0;
    if( readFile == 1){
        inputFile.open("CAR1.dat");
    }else if( readFile == 2){
        inputFile.open("CAR2.dat");
    }else if( readFile == 3){
        inputFile.open("CAR3.dat");
    }else{
        inputFile.open("CAR4.dat");
    }

    if( inputFile.is_open()){
        while(getline(inputFile, fileLine)){
            if(lineNumber < 3){
                carDetails[lineNumber] = fileLine;
            }else{
                splitString(fileLine, lineNumber - 3);
                totalData ++;
            }
            lineNumber ++;
        }
    }
    inputFile.close();
}

/*void split(const string& s, char c, vector<string>& v) {
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}*/
void splitString(string fileLine, int lineNumber){
    string::size_type i = 0;
    string::size_type j = fileLine.find(' ');
    vector<string> tokens;
    std::string::size_type sz;
    float x = 0;

    while (j != string::npos) {
      tokens.push_back(fileLine.substr(i, j-i));
      i = ++j;
      j = fileLine.find(' ', j);

      if (j == string::npos)
         tokens.push_back(fileLine.substr(i, fileLine.length()));
   }

    for (int i = 0; i < tokens.size(); ++i) {
        x = std::stof (tokens[i]);
        carResults[lineNumber][i] = x;
    }
}

/*void splitString(string fileLine, int lineNumber){
    string buf;
    float x = 0;
    stringstream ss(fileLine);
    vector<string> tokens;

    while (ss >> buf){
        tokens.push_back(buf);
    }
    for (int i = 0; i < tokens.size(); ++i) {
        std::istringstream iss(tokens[i]);
        iss >> x;
        carResults[lineNumber][i] = x;
    }
}*/

void outputArray(){
    for (int i = 0; i < totalData; i++) {
        cout << carResults[i][0] << '\t' << carResults[i][1]  << '\t' << carResults[i][2] << '\t' << carResults[i][3] << '\t' << carResults[i][4] << '\n';
    }
}

void calculateVelocities(){

    carResults[0][2] = 0;
    carResults[0][3] = 0;
    carResults[0][4] = 0;

    for( int i = 1; i < totalData; i++){
        if(carResults[i][0] > 0){
            carResults[i][2] = velocity(i);
            conversion(i);
            carResults[i][4] = acceleration(i);
        }
    }
}

double velocity(int i){
    return (carResults[i][1] - carResults[i - 1][1])/(carResults[i][0] - carResults[i - 1][0]);
}

void conversion(int i){
    if(units == 1){
        carResults[i][3] = carResults[i][2] * 0.681818;
    }else{
        carResults[i][3] = carResults[i][2] * 3.6;
    }
}

double acceleration(int i){
    return (carResults[i][2] - carResults[i - 1][2])/(carResults[i][0] - carResults[i - 1][0]);
}

double average(int column){
    double sum;

    for( int i = 0; i < totalData; i++){
        sum += carResults[i][column];
    }
    return sum/totalData;
}

double maximum(int column){
    double maxValue = carResults[0][column];

    for( int i = 1; i < totalData; i++){
        if( maxValue < carResults[i][column]){
            maxValue = carResults[i][column];
        }
    }
    return maxValue;
}

void outputToFile(string path){
    string vel;
    if( units == 1){
        vel = " mph";
    }else{
        vel = " km/h";
    }

    outputFile.open(path.c_str());
    outputFile << carDetails[0] << endl;
    outputFile << carDetails[1] << endl;
    outputFile << carDetails[2] << endl;
    outputFile << "Average velocity = " << averageVelocity << vel << endl;
    outputFile << "Average acceleration = " << averageAcceleration << " ft/s/s" << endl;
    outputFile << "Maximum velocity = " << maxVelocity << vel << endl;
    outputFile << "Maximum acceleration = " << maxAcceleration << " ft/s/s" << endl;

    for( int i = 0; i < totalData; i ++){
        outputFile << carResults[i][0] << ",";
        outputFile << carResults[i][1] << ",";
        outputFile << carResults[i][2] << ",";
        outputFile << carResults[i][3] << ",";
        outputFile << carResults[i][4] << endl;
    }
    outputFile.close();
}
