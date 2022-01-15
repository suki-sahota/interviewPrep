/**
 * Author: Suki Sahota
 */
#include <string>
#include <vector>

using namespace std;

class TheSimilarPathInAGraph {
public:
    vector<int> mostSimilar(int n, vector<vector<int>> &roads,
                            vector<string> &names,
                            vector<string> &targetPath)
    {
        const int T = targetPath.size();

        // Graph based on bi-directional roads
        vector<vector<int>> graph(n, vector<int>());

        // OPT is Dynamic Programming array for edit distances
          // OPT[i][j] gives the minimum edit distance for ith
          // city in targetPath if we use city names[j]
        vector<vector<int>> OPT(T, vector<int>(n, 1));

        // Builds graph
        for (vector<int> road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        // Fills in OPT array using Dynamic Programming
        findEditDistances(n, names, targetPath, T, graph, OPT);

        // Returns most similar path in graph
        return smallestEditDistance(n, T, graph, OPT);
    }

private:
    /* Finds minimum edit distance for each possible path,
     * starting at the last city, and working backwards to
     * the beginning.
     */
    void findEditDistances(int n, vector<string> &names,
                           vector<string> &targetPath, int T,
                           vector<vector<int>> &graph, vector<vector<int>> &OPT)
    {
        for (int t = T - 1; t >= 0; --t) {
            string tarCity = targetPath[t];
            for (int c = 0; c < n; ++c) {
                string curCity = names[c];

                if (tarCity.compare(curCity) == 0) {
                    // Edit distance here is 0 because it is a perfect match
                    OPT[t][c] = 0;
                }

                // Do not have next city to compare
                if (t == T - 1) { continue; }

                int minEditDist = INT_MAX;
                for (int neighbor : graph[c]) {
                    // Uses pre-computed edit distances from DP array
                    minEditDist = min(minEditDist, OPT[t + 1][neighbor]);
                }
                OPT[t][c] += minEditDist; // Memoize step
            }
        }
    }

    /* Uses the Dynamic Programming array, OPT, to build the most
     * similar path that has the smallest edit distance possible.
     */
    vector<int> smallestEditDistance(int n, int T, vector<vector<int>> &graph,
                                     vector<vector<int>> &OPT)
    {
        vector<int> res(T);

        // Finds starting location with smallest overall edit distance
        res[0] = distance(OPT[0].begin(), min_element(OPT[0].begin(), OPT[0].end()));

        for (int t = 1; t < T; ++t) {
            int min_dist = INT_MAX;
            for (int neighbor : graph[res[t - 1]]) {
                if (OPT[t][neighbor] < min_dist) {
                    min_dist = OPT[t][neighbor];
                    res[t] = neighbor;
                }
            }
        }

        return res;
    }
};
