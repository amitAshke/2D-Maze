#ifndef 2D_MAZE_SOLVER_H
#define 2D_MAZE_SOLVER_H

template <class Problem, class Solution>
class Solver {
public:
    virtual Solution solve (Problem problem) = 0 ;
};
#endif //2D_MAZE_SOLVER_H
