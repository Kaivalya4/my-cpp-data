/**
Consider leetcode Problem - Shortest Path visiting all nodes . We don't know that from which vertex we will start
so that we will get shortest path . So we Consider all the nodes as sources

MULTISOURCE BFS - You push all the cells/nodes/vertices which are the so called "Source" / Starting Vertices in a queue.
IN THESE TYPES OF PROBLEMS YOU GEBERALLY HAVE TO FIND THE SHORTEST DISTANCE/COST OF REACHING ALL THE VERTICES.

After pushing all the source vertices into the queue(priority queue/set) and performing the usual bfs/Djikstra
you get your desired answer.

This works in the usual time limit if the total number of nodes and edges are not more than say ~2e5

A better way to view -
    Consider a,b,c as three sources. Make a demo node and connect that to all these three. Just push x to the queue

    x ->a , x->b , x->c . Now bfs => you will get the answer that from where the path is shortest.

    Answer will contain extra +1 due to x => so do -1 and we have the answer.
*/

#include<iostream>

using namespace std;

int main()
{
    cout << "Thank YOu" ;
    return 0;
}
