#include "AStar.h"
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <string>

using std::pair;
using std::priority_queue;
using std::queue;
using std::string;
using std::unordered_map;
using std::vector;

double Distance(Star *current, Star *end)
{
    return sqrt((current->GetX() - end->GetX()) * (current->GetX() - end->GetX()) +
                (current->GetY() - end->GetY()) * (current->GetY() - end->GetY()) +
                (current->GetZ() - end->GetZ()) * (current->GetX() - end->GetZ()));
}

vector<string> AStar::findShortestPathAStar(Star *begin, Star *end)
{
    unordered_map<string, string> parent;
    vector<string> finalPath;
    priority_queue<pair<double, Star *>, vector<pair<double, Star *>>, std::greater<pair<double, Star *>>> nextNodes;

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
            if (!parent.count(neighbor.first->GetStarName()))
            {
                parent[neighbor.first->GetStarName()] = currentStar->GetStarName();
                double neighborCost = neighbor.second + Distance(neighbor.first, end);
                nextNodes.emplace(neighborCost, neighbor.first);
            }
        }
    }

    string temp = end->GetStarName();
    while (temp != begin->GetStarName())
    {
        finalPath.push_back(temp);
        temp = parent[temp];
    }
    finalPath.push_back(temp);
    std::reverse(finalPath.begin(), finalPath.end());

    return finalPath;
}
