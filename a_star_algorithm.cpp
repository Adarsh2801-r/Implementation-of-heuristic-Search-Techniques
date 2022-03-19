#include <bits/stdc++.h>
using namespace std;
void a_star_algorithm(int src,int dest,int adjMat[14][14],int distMat[14][14],bool visited[14],int heuristic[14])
{
    //A* search algorithm implementation 
    bool reachDest = false;
    int start = src;
    int parent[14],level[14];
    level[src]=0;
    vector <int> final_queue;
    //declarations of open and closed lists
    list <pair <int,int> > open;
    list <pair <int,int> > closed;
    pair < int , int > p1;
    p1 = make_pair(distMat[src][src]+heuristic[src],src);
    open.push_back(p1);
    int sum = 0 ;
    
    while(!reachDest && open.empty() == false)
    {
        /*sort the lists based on first value of pair (smaller first value comes first) 
         followed by second value of pair (larger second value comes first)*/
        open.sort([](auto const& a, auto const& b) {
            if(a.first == b.first)
            {
                return a.second > b.second ;
            }
            else
            {
                return a.first < b.first;
            }
       });
        pair < int , int > p2;
        p2 = open.front();
        open.pop_front();
        start = p2.second;
        for(auto it=closed.begin();it!=closed.end();it++)    //Backtracking the path
          {
              if(level[it->second]>=level[start])
              {
                     pair<int,int>p3;
                     p3 = make_pair(it->first,it->second);
                     open.push_back(p3);
                     it=closed.erase(it);
                     
              }
          }
        closed.push_back(p2);
        sum=p2.first-heuristic[p2.second];
        visited[start] = true ;
        if (start == dest)
        {
            reachDest = true;
            break;
        }
        for(int i=0;i<14;i++)
        {

               if(distMat[start][i]>0)
               {
                   if(visited[i]==false){     //if the child node is encountered for the first time 
                   pair < int , int > p4;
                   p4 = make_pair((distMat[start][i]+sum+heuristic[i]),i);
                   parent[i]=start;
                   level[i]=level[parent[i]]+1;
                   open.push_back(p4);
                   
                   visited[i]=true;
                   }
                   else{
                       for(auto it=open.begin();it!=open.end();it++)    /*if child node is already present in open list , 
                                                                         assign the shorter path to reach to the child node*/
                       {
                           if(it->second == i)
                           {
                               if(it->first >= distMat[start][i]+sum+heuristic[i])
                               {
                                   it->first = distMat[start][i]+sum+heuristic[i];
                                   parent[i]=start;
                                   level[i]=level[parent[i]]+1;
                               }
                           }
                       }
                       bool foundOpen = 0;
                       for(auto it=closed.begin();it!=closed.end();it++)  /*if child node is already pesent in closed list , remove the child from closed , 
                                                                            assign the shorter path to reach to the child node and pushing it in open list*/
                       {
                           if(it->second == i)
                           {
                               if(it->first >= distMat[start][i]+sum+heuristic[i])
                               {
                                   
                                   it->first = distMat[start][i]+sum+heuristic[i];
                                   pair<int,int>p3;
                                   p3 = make_pair(it->first,it->second);
                                   open.push_back(p3);
                                  
                                   it=closed.erase(it);
                                   foundOpen = 1;
                               }
                           }
                       }
                       if(foundOpen) /* if childnode present in closed list is reached byshorter path then reassigning the cost value 
                                        and changing the path to the shorter new path  to the node traversed in closed list*/ 
                       {
                            for(auto it=closed.begin();it!=closed.end();it++)
                         {
                           if(level[it->second] > 0)
                           {
                               pair<int,int>p5;
                               p5 = make_pair(it->first,it->second);
                               open.push_back(p5);
                               it=closed.erase(it);
                           }
                        }
                         parent[i]=start;
                         level[i]=level[parent[i]]+1;
                        
                       }


                       
                   }

                }

            
        }
        
    
    }
    if(!reachDest)
    {
        cout << "No optimal path exists" << endl;
    }
    else
    { 
        // displaying the path with the cost at each node in the optimal path 
        cout<<"Optimal path taken by Mars Rover to reach Jezero crater : "<<endl;
        for (auto currentPair : closed)
       {
    
         pair<int, int> currentpair = currentPair;
         cout << "Chkpt-"<< currentPair.second <<" "<<"Cost at the Chkpt : " <<currentPair.first ; 
         if(currentPair.second != 13)
         {
            cout<<" ==> ";
         }
         else
         {
            cout<<endl;
            cout<<" Total cost of the optimal path traversed by Mars Rover from source to the Jezero crater is : "<<currentPair.first;
         }
       }
    }
    
}
int main()
{
    /*adjMat is 14X14 matrix . adjMat[i][j] == 1 if i and j are sharing a common edge 
    and adjMat[i][j] == 0 means they are not sharing a common edge*/
    int adjMat[14][14]
        = { { 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
            { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
            { 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
            { 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1 },
            { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0 },
            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1 }
             };
    // 0th node for src and 13th node for dest
    // rest other nodes are checkpoints
    /* disMat is 14X14 matrix . 
    distMat[i][j] > 0 if i and j are sharing a common edge and distMat[i][j] gives the distance between them  and 
    adjMat[i][j] == -1 means they are not sharing a common edge
    and adjMat[i][i] == 0 for all i>=0 and i<=13*/
    int distMat[14][14]
        = { { 0, 120, -1, -1, -1, -1, -1, 77, -1, 142, -1, -1, -1, -1 },
            { 120, 0, 113, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
            { -1, 113, 0, 72, -1, -1, -1, -1, -1, -1, -1, -1, -1,  -1 },
            { -1, -1, 72, 0, 77, -1, -1, -1, -1, -1, -1, -1, -1, -1  },
            { 0, -1, -1, 77, 0, 122, -1, -1, -1, -1, -1, -1, -1, -1 },
            { -1, -1, -1, -1, 122, 0, 126, -1, -1, -1, -1, -1, -1, -1 },
            { -1, -1, -1, -1, -1, 126, 0, -1, -1, -1, -1, 140, 148, -1},
            { 77, -1, -1, -1, -1, -1, -1, 0, 71, -1, -1, -1, -1, -1   },
            { -1, -1, -1, -1, -1, -1, -1, 71, 0, 122, -1, -1, -1, -1  },
            { 142, -1, -1, -1, -1, -1, -1, -1, 122, 0, 111, -1, 82, -1},
            { -1, -1, -1, -1, -1, -1, -1, -1, -1, 111, 0, -1, -1, 213 },
            { -1, -1, -1, -1, -1, -1, 140, -1, -1, -1, -1, 0, 99, 105 },
            { -1, -1, -1, -1, -1, -1, 148, -1, -1, 82, -1, 99, 0, -1  },
            { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 213, 105, -1, 0 }
             };
    bool visited[14] = { false };
    int shortestPath[14][14];
    int src=0,dest=13;
    //Heuristic values of different nodes/checkpoints
    int heuristic[14] = {550 , 550 , 450 , 510 , 325 , 415 , 235 , 455 , 400 , 325 , 240 , 170 , 205 , 0} ;  
    a_star_algorithm(src,dest,adjMat,distMat,visited,heuristic); //A* algorithm implementation for finding optimal path for Mars Rover to reach Jezero crater
    return 0;
}         
    