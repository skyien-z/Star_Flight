#include "BFS.h"
#include <queue>
#include <iostream>

std::vector<Star*> BFS::StarTraversal(Star* start) {
    std::unordered_set<int> visitedList;
    std::queue<Star*> queue;
    std::vector<Star*> toReturn;

    queue.push(start);

    while (!queue.empty()) {
        Star* curr = queue.front();
        queue.pop();
        toReturn.push_back(curr);
        std::vector<std::pair<Star*, double> > neighbors = curr->GetNeighboringStarsList();
        visitedList.insert(curr->GetStarId());
        //std::cout << "STAR: " << curr->GetStarName() << std::endl;
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if (visitedList.find(neighbors[i].first->GetStarId()) == visitedList.end()) {
                //std::cout << neighbors[i].first->GetStarId() << std::endl;
                queue.push(neighbors[i].first);
                visitedList.insert(neighbors[i].first->GetStarId());
            }
        }
    }
    return toReturn;
}


std::vector<Star*> BFS::GraphTraversal(const std::vector<Star> nodeList) {// call bfs small on every vertex
    std::vector<Star*> starList;
    std::vector<Star> copyList = nodeList;
    std::unordered_set<int> visitedList;
    for (unsigned i = 0; i < copyList.size(); i++) {
        starList.push_back(&copyList[i]);
    }
    std::vector<Star*> toReturn;
    for (unsigned i = 0; i < starList.size(); i++) {
        if (visitedList.find(starList[i]->GetStarId()) != visitedList.end()) {
            continue;
        }
        std::vector<Star*> current_traversal = StarTraversal(starList[i]);
        for (unsigned j = 0; j < current_traversal.size(); j++) {
            visitedList.insert(current_traversal[j]->GetStarId());
        }
        toReturn.insert(toReturn.end(),current_traversal.begin(),current_traversal.end());
    }
    return toReturn;
}


bool BFS::canTravel(Star* start, Star* end) {
    std::vector<Star*> traversal = StarTraversal(start);
    for (unsigned i = 0; i < traversal.size(); i++) {
        if (end->GetStarId() == traversal[i]->GetStarId()) {
            return true;
        }
    }
    return false;
}
