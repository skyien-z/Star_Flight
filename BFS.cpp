#include "BFS.h"
#include <queue>
#include <iostream>

std::vector<Star*> BFS::StarTraversal(Star* start) { // standard BFS algorithm using a queue
    std::unordered_set<int> visitedList; // unordered set to see if a star (ID) has already been visited
    std::queue<Star*> queue;
    std::vector<Star*> toReturn; // vector of Star pointers

    queue.push(start); // add the beginning Star to queue

    while (!queue.empty()) {
        Star* curr = queue.front(); // curr is the Star to be processed
        queue.pop(); // dequeue front of the queue
        toReturn.push_back(curr); // add current Star to return list
        std::vector<std::pair<Star*, double> > neighbors = curr->GetNeighboringStarsList(); // obtain list of neighboring Stars
        visitedList.insert(curr->GetStarId()); // mark the current Star as visited
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if (visitedList.find(neighbors[i].first->GetStarId()) == visitedList.end()) { // checks if each neighbor has not been visited
                queue.push(neighbors[i].first); // enqeues neighbor star
                visitedList.insert(neighbors[i].first->GetStarId()); // marks the neighbor as visited
            }
        }
    }
    return toReturn;
}


std::vector<Star*> BFS::GraphTraversal(const std::vector<Star*> nodeList) {// call bfs small on every vertex
    std::vector<Star*> starList = nodeList; // copy of nodeList being passed
    std::unordered_set<int> visitedList; // keep track of visited Stars by ID

    std::vector<Star*> toReturn; // return vector 
    for (unsigned i = 0; i < starList.size(); i++) {
        if (visitedList.find(starList[i]->GetStarId()) != visitedList.end()) { // checks if a Star has been visited
            continue;
        }
        std::vector<Star*> current_traversal = StarTraversal(starList[i]); // call StarTraversal on each Star
        for (unsigned j = 0; j < current_traversal.size(); j++) { // goes through the return vector of StarTraversal
            visitedList.insert(current_traversal[j]->GetStarId()); // marks each Star in the traversal as visited
        }
        toReturn.insert(toReturn.end(),current_traversal.begin(),current_traversal.end()); // merge the traversal vector into return vector
    }
    return toReturn;
}


bool BFS::canTravel(Star* start, Star* end) { // check if there is a path between two stars
    std::vector<Star*> traversal = StarTraversal(start); // calls StarTraversal on beginning code
    for (unsigned i = 0; i < traversal.size(); i++) {
        if (end->GetStarId() == traversal[i]->GetStarId()) { // checks if end Star is in the traversal 
            return true; // if so, there is a path
        }
    }
    return false;
}
