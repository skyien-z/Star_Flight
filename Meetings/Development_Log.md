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