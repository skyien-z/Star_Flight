1. Leading Question
Given that there are fuel recharge stations at each star and your spaceship has limited fuel, what is the shortest path from Earth to any star? 

2. Dataset Acquistion and Processing
We will use the [HYG star database](https://github.com/astronexus/HYG-Database) dataset. We will focus on the coordinate part of this dataset, specifically, the XYZ coordinates of the stars from Earth. We will assign the weight of each edge by calculating the XYZ distance from star A to star B. We will also determine if this calculated distance is less than or equal to the distance our fuel takes us. If it is less than or equal, then the edge will be created, else it won't be created. For our graph structure, each individual node will represent a star and there will be edges connected from each star if the distance is less than or equal to the distance our fuel takes us. We recognize that this data is large, and potentially error-ridden; thus, we will drop any records that don't contain all of the fields and/or any malformed records.

3. Graph Algorithms
For our graph algorithm, we will use the A* shortest-path algorithm. We expect the start to be Earth and the end point to be an inputted star by the user. For our traversal algorithm, we will traverse our dataset to look for the inputted star by the user and set that as the end location of our A* algortihm. For our final algorithm, we will use a graphical interface to graph out our final path in 3-dimensional generated from the A* shortest-path algorithm. 

4. Timeline
April 7 - sync to complete project proposal and team contract
   
April 9 - submit project proposal and team contract

April 14 - set up initial repository and Makefile

April 19 - clean out the data from the dataset

April 21 - convert array format into graph format 

April 26 - write A* and verify with tests

April 28 - write BFS and verify with tests

May 5 - write graph projection onto graphical interface and verify with tests

May 7 - finish report

May 9 - sync to record final presentation

May 11 - finish editing presentation and submit