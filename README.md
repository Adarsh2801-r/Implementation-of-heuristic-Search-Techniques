# Implementation-of-heuristic-Search-Techniques

## Steepest-Ascent Hill Climbing
The steepest-Ascent algorithm is a variation of the simple hill-climbing algorithm. This algorithm examines all the neighbouring nodes of the current state and selects one neighbour node which is closest to the goal state.

**Problem description:** 
A dart board is filled with 12 sectors. Each sector can perform 4 operations, rotate clockwise, rotate
anticlockwise, shift down (till center). Given an initial state (Fig. A), design and implement an efficient
heuristic approach to reach the goal state (Fig B).
<p align="center">
  <img src="https://user-images.githubusercontent.com/66625110/158943403-48ed91cd-abbd-45f6-a05e-cc87160a81f8.png">
</p>

**State-space :** </br>
The dart is represented as 2-D array and each sector tile in dart board is represented using a 4-tuple = {x,y,lvl,quadrant} </br>
where x = row_number , y = column_number, lvl = depth of concentric circles from center , quadrant = qudrant in which sector is present .

**Heuristic evaluation function used :** </br>
We wish to reach the goal state efficiently , i.e with as minimum moves as possible. The heuristic function gives the minimum number of moves / distance between 2 sector tiles. The displacement of sector tile involves two parts : changing the level by one unit(using jump operation) and changing the quadrant by one unit(using rotate operation). The heuristic function under-estimates the cost to reach goal state and hence is guaranteed to give an optimal solution.

**Results:** </br>
Sequence of states obtained : </br>
![image](https://user-images.githubusercontent.com/66625110/158945026-5086f404-f2c8-43a5-b6de-66925b50d2b9.png)   ![image](https://user-images.githubusercontent.com/66625110/158945070-a215c4f5-3f70-4f3f-a62d-9314b624dcc5.png) ![image](https://user-images.githubusercontent.com/66625110/158945180-b65c2611-7462-410d-9e94-66cb795f347b.png) ![image](https://user-images.githubusercontent.com/66625110/158945286-7ce4466b-7846-4d38-9f40-903e4fbe1464.png)
![image](https://user-images.githubusercontent.com/66625110/158945336-4cebbf23-307e-4360-be9d-2e2c41d6b868.png)
![image](https://user-images.githubusercontent.com/66625110/158945352-8ec24531-7e02-4dee-a53e-ac5e45984d67.png)
![image](https://user-images.githubusercontent.com/66625110/158945353-ca625b5a-8fc9-45fa-a28c-012a6f28c29a.png)

**Observations:**</br>
We see that after few states, the cost of subsequent states is remaining constant. This is called a PLATAEU REGION. A plateau is the flat area of the search space in which all the neighbor states of the current state contains the same value, because of this algorithm does not find any best direction to move. </br>
Possible solution: The solution for the plateau is to take big steps or very little steps while searching, to solve the problem. Randomly select a state which is far away from the current state so it is possible that the algorithm could find non-plateau region.


## A* algorithm

A* Search algorithm is one of the best and popular technique used in path-finding and graph traversals. Informally speaking, A* Search algorithms, unlike other traversal techniques, it has “brains”. What it means is that it is really a smart algorithm which separates it from the other conventional algorithms. This fact is cleared in detail in below sections. 
And it is also worth mentioning that many games and web-based maps use this algorithm to find the shortest path very efficiently (approximation). 

**Problem description:** 
In 2021, a Mars rover, Perseverance, landed on the moon carrying along with it the first of its kind
helicopter named Ingenuity. The goal of the rover was to travel to the center of a crater named Jezero
with the help of Ingenuity. Since no help from Earth is available, Perseverance is solely dependent on
Ingenuity’s inputs. Ingenuity flies across a couple of meters and gives an aerial topography as an input to
Perseverance (FIG A) and based on these inputs the rover takes its next step. Design a communication
channel between Ingenuity and Perseverance where the copter sends the expanded states from the
initial position of the rover, the rover sends back the decision it takes on the expanded states and so on.
<p align="center">
  <img src="https://user-images.githubusercontent.com/66625110/158946135-9cfd3654-d613-4d24-b805-0b33442c10dd.png">
</p>


