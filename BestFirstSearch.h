#ifndef 2D_MAZE_BESTFIRSTSEARCH_H
#define 2D_MAZE_BESTFIRSTSEARCH_H

#include <list>

#include "algorithm"
#include "CompForMult.h"
#include "InCommonSearcher.h"

using namespace std;

template<class S, class T>
class BestFirstSearch : public InCommonSearcher<S, T> {
public:
    S search(Searchable<T> *searchable) override {
        this->openList.clear();
        this->closed.clear();
        this->evaluatedNodes =0;
        this->addToOpenList(searchable->getInitialState());
        while (this->getOpenListSize() > 0) {
            State<T> *n = this->popOpenList();
            this->closed.push_back(n);
            if (n->equal(searchable->getGoalState())) {
                return this->backTrace(n, searchable);
            }
            auto *father = new State<T>(*n);
            vector<State<T> *> successors = searchable->getAllpossibleStates(father);
            for (auto iter = successors.begin(); iter != successors.end(); iter++) {
                if (!closeContains(*iter, this->closed) && !this->contains(*iter)) {
                    State<T> *s = *iter;
                    this->addToOpenList(s);
                } else if (!closeContains(*iter, this->closed)) {
                    this->optionPriority(*iter);
                }
            }
        }
    }


    virtual bool closeContains(State<T> *stateIt, vector<State<T>*> close) {
        for (auto it = close.begin(); it != close.end(); it++) {
            State<T> *s = *it;
            if (s->equal(stateIt)) {
                return true;
            }
        }
        return false;
    }
};

#endif //2D_MAZE_BESTFIRSTSEARCH_H
