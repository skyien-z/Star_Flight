Overview:

    146 nodes: ask user to enter amount of fuel for each trip––can make UI later
    Each node computes distance from given node to other 145 nodes––make edge if fuel allows it
    Fuel should be asked in a range
    
    Ask user to enter in a star for the end distance

    UI will control fuel and end distance along with printing stuff or displaying it
    BFS needs find the end node; BFS will throw an error if fuel is not enough to get to star

    UI will make sure to call graph

Week 1:

    4/17/21 
        Completed:
            1. Filtered out data using python
            2. Created Makefile and read in data (created a main file to test)

        To do for this week:
            Add a vector of star* of neighbors in the star class (Kylie)
            A* Implementation (Charles)
            BFS (Sriram and Keesan)

    4/19/21
    Overview/Completed:
        To do this meeting: 
            1. Create testing Makefile that works

        Completed since the last meeting:
            - Loading in data to star objects
            - A* traversal

        To do for the next meeting:
            1. Writing tests for Star and StarInitializer Classes (Kylie)
            2. A* Implementation test (Charles)
            3. BFS and BFS Tests (Sriram and Keesan)
        
        To do next meeting:
            1. Decide on a UI design

Week 2:

    4/26/21
        To do this meeting: 
            1. Figure out our third algorithm and which visualization will use, if any.

            Conclusions:
                We've decided to represent 3D space using the 2D PNG files given by
                making the z coordinate correspond to the size and color of the stars because 
                the 3D graphing libraries that we've found don't work on EWS. If this doesn't 
                work, we will try to implement a MST.

        Completed since the last meeting:
            1. Finish A* tests (Charles)
            2. Finish StarInitializer tests (Kylie)
            3. Wrote the BFS algorithm

        To do for the next meeting:
            1. Writing BFS units tests (Sriram and Keesan)
            2. Implement graphing of stars with PNG files (Charles and Kylie)
        
        To do next meeting (a weekend day because of scheduling conflicts):
            1. Determine our next steps (if we are going to plot lines or not)
            2. Implement main function

            Future Goals:
                3. Write ReadMe.md
                4. Comment each class and function

Week 3:

    5/2/21
        To do this meeting: 
            1. Work together to implement main
            2. Delegate the documentation tasks for next week

        Completed since the last meeting:
            1. Wrote Visualizer class and added StarInitializer and Star comments (Charles and Kylie)
            2. Wrote the BFS algorithm unit tests and added BFS comments (Keesan and Sriram)

        To do for the next meeting:
            1. Polish up Visualizer implementation and design (Charles and Kylie)
            2. Start up the write-up (ReadMe.md and 2 page explanation) (Sriram and Keesan)
            3. Write up comments for AStar (Charles)
            4. Write comments for Visualizer and implement Rule of 3 in StarInitializer and Visualizer classes (Kylie)

            Future Goals:
                1. Comment each class and function/Code review stuff
                2. Organize Presentation and take video

Week 4:

    5/8/21
        To do this meeting:
            1. Create and finish presentation slides
            2. Decide video organization

        Completed since the last meeting:
            1. Finish up Visualizer implementation and design (Charles and Kylie)
            2. Start up the write-up (ReadMe.md and 2 page explanation) (Sriram and Keesan)
            3. Write up comments for A* (Charles)
            4. Write comments for Visualizer and implement Rule of 3 in StarInitializer and Visualizer classes (Kylie)
        
        To do for next week:
            1. Record videos individually by Monday evening and compile them together (Everybody––Sriram will compile)
                a. Videos will be voiceovers of the presentation slides and a live demo of main
            2. Polish up ReadMe.md and results.md
