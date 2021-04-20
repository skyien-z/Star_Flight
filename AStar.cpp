#include "AStar.h"
#include <unordered_map>
#include <queue>
#include <algorithm>

using std::pair;
using std::priority_queue;
using std::queue;
using std::unordered_map;
using std::vector;

double Distance(Star *current, Star *end)
{
    return sqrt((current->GetX() - end->GetX()) * (current->GetX() - end->GetX()) +
                (current->GetY() - end->GetY()) * (current->GetY() - end->GetY()) +
                (current->GetZ() - end->GetZ()) * (current->GetX() - end->GetZ()));
}

vector<Star *> AStar::findShortestPathAStar(Star *begin, Star *end)
{
    unordered_map<Star *, Star *> parent;
    vector<Star *> finalPath;
    priority_queue<pair<double, Star *>, vector<pair<double, Star *>>, std::greater<pair<double, Star *>>> nextNodes;

    finalPath.push_back(begin);
    nextNodes.emplace(0.0, begin);

    while (!nextNodes.empty())
    {
        Star *currentStar = nextNodes.top().second;
        nextNodes.pop();
        if (currentStar == end)
        {
            break;
        }
        for (auto neighbor : currentStar->GetNeighboringStarsList())
        {
            if (!parent.count(neighbor.first))
            {
                parent[neighbor.first] = currentStar;
                double neighborCost = neighbor.second + Distance(neighbor.first, end);
                nextNodes.emplace(neighborCost, neighbor.first);
            }
        }
    }

    Star *temp = end;
    while (temp != begin)
    {
        finalPath.push_back(temp);
        temp = parent[temp];
    }

    finalPath.push_back(temp);
    std::reverse(finalPath.begin(), finalPath.end());

    return finalPath;
}
