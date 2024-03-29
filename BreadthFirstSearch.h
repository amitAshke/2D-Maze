#ifndef 2D_MAZE_BREADTHFIRSTSEARCH_H
#define 2D_MAZE_BREADTHFIRSTSEARCH_H

#include <vector>
#include <string>

#include "Searcher.h"
#include "Searchable.h"
#include "State.h"

template<class S, class T>
class BreadthFirstSearch : public Searcher<S, T> {
    int nodesEvaluated = 0;
public:
    void adjustStateVectors(vector<State<T> *> &visited, vector<State<T> *> &neighbors) {
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < neighbors.size(); j++) {
                if (visited[i]->equal(neighbors[j])) {
                    if (visited[i]->getCost() > neighbors[j]->getCost()) {
                        visited.erase(visited.begin() + i);
                    } else {
                        neighbors.erase(neighbors.begin() + j);
                    }
                }
            }
        }
    }

    string makeDirections(State<T> *currentState) {
        string directions = "";
        if (currentState == nullptr) {
            return "No path available";
        }
        while (currentState->getCameForm() != nullptr) {
            directions = currentState->getDirection() + "," + directions;
            currentState = currentState->getCameForm();
        }
        return directions.substr(0, directions.length() - 1);
    }

    S search(Searchable<T> *searchable) override {
        vector<State<T> *> closedStates;
        vector<State<T> *> neighbors;
        vector<State<T> *> stateQueue;
        State<T> *shortest = nullptr;
        double minCost;
        bool minFound = false;
        stateQueue.push_back(searchable->getInitialState());
        nodesEvaluated = 0;
        while (!stateQueue.empty()) {
            nodesEvaluated++;
            State<T> *currentState = stateQueue[0];
            stateQueue.erase(stateQueue.begin());
            if (currentState->equal(searchable->getGoalState())) {
                if (!minFound) {
                    minFound = true;
                    minCost = currentState->getCost();
                    shortest = new State<T>(*currentState);
                } else if (currentState->getCost() < minCost) {
                    minCost = currentState->getCost();
                    shortest = new State<T>(*currentState);
                }
            } else {
                State<T> *copy = new State<T>(*currentState);
                neighbors = searchable->getAllpossibleStates(copy);
                adjustStateVectors(closedStates, neighbors);
                adjustStateVectors(stateQueue, neighbors);
                for (int i = 0; i < neighbors.size(); i++) {
                    stateQueue.push_back(neighbors[i]);
                }
            }
            closedStates.push_back(currentState);
        }
        return makeDirections(shortest);

    }

    int getNumberOfNodesEvaluate() override {
        return nodesEvaluated;
    }
};

#endif //2D_MAZE_BREADTHFIRSTSEARCH_H
