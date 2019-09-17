#ifndef 2D_MAZE_SEARCHER_H
#define 2D_MAZE_SEARCHER_H

#include "Searchable.h"

template<class S, class T>
class Searcher {
public:
    virtual S search(Searchable<T>* searchable) = 0;

    virtual int getNumberOfNodesEvaluate() = 0;

    virtual ~Searcher() = default;
};

#endif //2D_MAZE_SEARCHER_H
