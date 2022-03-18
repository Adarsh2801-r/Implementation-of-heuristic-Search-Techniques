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
![image](https://user-images.githubusercontent.com/66625110/158945026-5086f404-f2c8-43a5-b6de-66925b50d2b9.png)   ![image](https://user-images.githubusercontent.com/66625110/158945070-a215c4f5-3f70-4f3f-a62d-9314b624dcc5.png) ![image](https://user-images.githubusercontent.com/66625110/158945180-b65c2611-7462-410d-9e94-66cb795f347b.png)





## A* algorithm
