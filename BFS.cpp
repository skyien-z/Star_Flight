#include "BFS.h"
#include <queue>
#include <iostream>

std::vector<Star*> BFS::StarTraversal(Star* start) {
    std::unordered_set<int> visitedList;
    std::queue<Star*> queue;
    std::vector<Star*> toReturn;

    std::vector<std::pair<Star*, double> > neighbors;

    queue.push(start);
    visitedList.insert(start->GetStarId());
    toReturn.push_back(start);
    neighbors = start->GetNeighboringStarsList();

    while (!queue.empty()) {
        Star* curr = queue.front();
        queue.pop();
        toReturn.push_back(curr);
        neighbors = curr->GetNeighboringStarsList();
        visitedList.insert(curr->GetStarId());
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if (visitedList.find(neighbors[i].first->GetStarId()) != visitedList.end()) {
                continue;
            }
            queue.push(neighbors[i].first);
        }
    }
    return toReturn;
}


std::vector<Star*> BFS::GraphTraversal(const std::vector<Star>& nodeList) {// call bfs small on every vertex
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
        for (unsigned i = 0; i < current_traversal.size(); i++) {
            visitedList.insert(current_traversal[i]->GetStarId());
        }
        toReturn.insert(toReturn.end(),starList.begin(),starList.end());
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
