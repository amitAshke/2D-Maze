#ifndef 2D_MAZE_MYMATRIX_H
#define 2D_MAZE_MYMATRIX_H

#include "Searchable.h"
#include "unordered_set"
#include "Converter.h"
#include <list>
#include <vector>

using namespace std;
class MyMatrix : public Searchable<pair<int,int>>{
    vector<vector<int>> matrix;
    vector<string> original;
    vector<State<pair<int, int>>*> garbagePointers;
    int length;
    int width;
    pair<int, int> initState;
    pair<int, int> goalState;
    public:
    MyMatrix(vector<string> input);

    State<pair<int, int>>* getInitialState() override;

    bool isGoalState(const State<pair<int, int>> &st) override;

    State<pair<int, int>> *getGoalState() override;

    vector<State<pair<int,int>>*> getAllpossibleStates( State<pair<int, int>> *s) override;

    vector<string> getOriginalVector() override;

    virtual ~MyMatrix();

private:
    vector<string>splitIt(string str, string token);

};
#endif //2D_MAZE_MYMATRIX_H
