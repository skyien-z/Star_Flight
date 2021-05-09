1. Goals

 In our project proposal, the leading question we attempted to answer was "given that there are fuel recharge stations at each star and your spaceship has limited fuel, 
 what is the shortest path from Earth to any star?" We slightly altered this to be more flexible, in that our program now takes in any two stars to find the shortest path
 between them instead of being limited to starting at Earth.
 Our project answers this question by using the A* shortest path algorithm and visualizing the results using three images which work as slices of 3D space. 
 
 2. Results Locations
 
 The dataset used can be found in the ```data.csv``` file and the output path is both printed to the console and saved as images in the ```png_files``` folder.
 
 3. Results Discussion
 
 Our program's methods are successful and this can be seen by inputting valid parameters and seeing the results. These results are essentially validated by the tests
 in the ```tests``` folder, which can be examined to see how they individually test each class/function. For each class, we created smaller datasets and made sure that each algorithm ran as expected on them, so we can reasonably conclude that the algorithm runs as expected on the full dataset. Below is a screenshot of the output when running the tests.
 
 INSERT CONSOLE SCREENSHOT
 
 Furthermore, we can see an example of how to use our program to find the shortest path from Sol to Menkar with 35 units of fuel:
 
 ![alt text](https://github-dev.cs.illinois.edu/cs225-sp21/kpate360-kyliez2-shi46-srirams5/blob/master/Meetings/demo_png_files/sol_menkar_35_demo.gif?raw=true)

 INSERT PNG FILES AND TERMINAL SCREENSHOTs BELOW

 BFS confirmed that there was a path to Menkar using 35 units of fuel. A* outputted the path, and the Visualizer displayed the data in PNG format. Thus, it is safe to conclude that our algorithms work as expected.

There's one thing to note: the visualizer will not display stars with their centers outside of the scope of the PNG, but some pixels may be cut off from the PNG if the center+radius exceeds the limits of the PNG file––the terminal will output whether or not pixels were cut out. This is not a cause for concern.
