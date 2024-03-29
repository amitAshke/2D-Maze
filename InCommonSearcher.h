#ifndef 2D_MAZE_INCOMMONSEARCHER_H
#define 2D_MAZE_INCOMMONSEARCHER_H

#include <set>
#include "CompForMult.h"
#include "Searcher.h"
#include "State.h"

using namespace std;
template <class S, class TforState>
class InCommonSearcher : public Searcher<S, TforState>{
protected:
    std::multiset<State<TforState>*,CompForMult<TforState>> openList;
    int evaluatedNodes;
    vector<State<TforState>*> closed;
public:
    InCommonSearcher() : evaluatedNodes(0) {};

   virtual S search(Searchable<TforState> *searchable) =0;

protected:
    State<TforState>*popOpenList(){
        evaluatedNodes++;
        auto iter = openList.begin();
        State<TforState>* getIt = *iter;
        openList.erase(iter);
        return getIt;
    }
    S backTrace(State<TforState> *s, Searchable<TforState> *searchable) {
        vector<string> path;
        string toReturn;
        State<TforState> *startState = searchable->getInitialState();
        State<TforState> *current = s;
        while (!(current->equal(startState))) {
            path.push_back(current->getDirection());
            current = current->getCameForm();
        }
        reverse(path.begin(), path.end());
        for (auto i : path) {
            toReturn.append(i);
            toReturn.append(",");
        }
        string st = toReturn.substr(0, toReturn.size() - 1);
        return st;

    }
    void optionPriority(State<TforState> *currState) {
        for (auto it = openList.begin(); it != openList.end(); it++) {
            State<TforState> *s = *it;
            if (s->equal(currState)) {
                if (currState->getCost() < s->getCost()) {
                    this->openList.erase(it);
                    State<TforState> *came = currState->getCameForm();
                    s->setCameForm(came);
                    this->addToOpenList(currState);
                }
                return;
            }
        }
        this->addToOpenList(currState);
    }
    int getOpenListSize(){
        return (int)openList.size();
    }
    int getNumberOfNodesEvaluate() override {
        return evaluatedNodes;
    }
    void addToOpenList(State<TforState>* stadd){
        openList.insert(stadd);
    }
    bool contains(State<TforState> *stateIt){
        for (auto it = openList.begin(); it != openList.end(); it++) {
            State<TforState> *s = *it;
            if (s->equal(stateIt)) {
                return true;
            }
        }
        return false;    }


};
#endif //2D_MAZE_INCOMMONSEARCHER_H
