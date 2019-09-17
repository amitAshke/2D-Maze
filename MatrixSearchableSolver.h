#ifndef 2D_MAZE_SEARCHABLESOLVER_H
#define 2D_MAZE_SEARCHABLESOLVER_H

#include "AStar.h"
#include "Solver.h"

template <class Problem, class Solution>
class MatrixSearchableSolver : public Solver<Problem,Solution> {
    Astar<Solution,pair<int,int>>* astar = new Astar<Solution,pair<int,int>>();
public:
    Solution solve(Problem problem) {
        return astar->search(problem);
    }
};

#endif //2D_MAZE_SEARCHABLESOLVER_H
