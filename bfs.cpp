#include "bfs.h"
#include <queue>

std::vector<Star*> BFS::BFSsmall(Star* star) {
    std::unordered_set <int> visitedList;
    std::queue<Star*> queue;
    std::vector<Star*> toReturn;

    std::vector<std::pair<Star*, double> > neighbors;

    queue.push(star);
    visitedList.insert(star->GetStarId());
    toReturn.push_back(star);
    neighbors = star->GetNeighboringStarsList();

    while (!queue.empty()) {
        Star* curr = queue.front();
        toReturn.push_back(curr);
        visitedList.insert(curr->GetStarId());
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if (visitedList.find(neighbors[i].first->GetStarId()) == visitedList.end()) {
                continue;
            }
            queue.push(neighbors[i].first);
        }

    }

    return toReturn;

    

    




}


// BFS::BFStraversal(const std::vector<Star>& star_list_) {// call bfs small on every vertex

// }


// BFS::canTravel(Star* start, Star* end) {



// }
