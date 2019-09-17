#ifndef 2D_MAZE_MATRIXCONVERTER_H
#define 2D_MAZE_MATRIXCONVERTER_H

#include <vector>
#include "Converter.h"
#include "MyMatrix.h"
#include "Searchable.h"

using namespace std;
class MatrixConverter : public Converter <Searchable<pair<int, int>>* ,string>{
    vector<Searchable<pair<int, int>>*>garbagePointers;
public:
    MatrixConverter();

    Searchable<pair<int, int>>* conVecStringToProblem(vector<string> pro) override;

    string conVecProblemToString(Searchable<pair<int, int>>* problem) override;

    string conSolvToString(string solve) override;

    string conStringToSol(string solve) override;

    virtual ~MatrixConverter();

private:
//split by specific token
    vector<string> splitIt(string str, string token) ;

};
#endif //2D_MAZE_MATRIXCONVERTER_H
