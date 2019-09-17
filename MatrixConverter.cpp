#include "MatrixConverter.h"

Searchable<pair<int, int>>* MatrixConverter::conVecStringToProblem(vector<string> pro) {
    MyMatrix *matrix = new MyMatrix(pro);
    this->garbagePointers.push_back(matrix);
    return matrix;
}

string MatrixConverter::conSolvToString(string solve) {
    return solve;
}

string MatrixConverter::conVecProblemToString(Searchable<pair<int, int>>* problem) {
    vector<string> temp = problem->getOriginalVector();
    string toReturn;
    for (auto i : temp) {
        toReturn.append(i);
        toReturn.append("|");
    }
    string st = toReturn.substr(0, toReturn.size() - 1);
    return st;
}

string MatrixConverter::conStringToSol(string solve) {
    return solve;
}
//split by specific token
vector<string>MatrixConverter:: splitIt(string str, string token) {
    vector<string> result;
    while (str.size()) {
        int index = str.find(token);
        if (index != string::npos) {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)result.push_back(str);
        } else {
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

MatrixConverter::~MatrixConverter() {
    for(auto run :this->garbagePointers){
        if(run != nullptr){
            delete run;
        }
    }
}

MatrixConverter::MatrixConverter() = default;
