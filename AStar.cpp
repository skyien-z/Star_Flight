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
    unordered_map<Star *, double> starDistance;
    vector<Star *> finalPath;
    priority_queue<pair<double, Star *>, vector<pair<double, Star *>>, std::greater<pair<double, Star *>>> nextNodes;

    finalPath.push_back(begin);
    nextNodes.emplace(0.0, begin);
    starDistance[begin] = 0.0;

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
            if (!parent.count(neighbor))
            {
                starDistance[neighbor] = starDistance[currentStar] + Distance(currentStar, neighbor);
                parent[neighbor] = currentStar;
                double neighborCost = starDistance[neighbor] + Distance(neighbor, end);
                nextNodes.emplace(neighborCost, neighbor);
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
