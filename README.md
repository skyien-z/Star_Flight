# [PROJECT TITLE TBD]
> Keesan Patel (kpate360), Kylie Zhang (kyliez2), Charles Shi (shi46), Sriram Sridhar (srirams5)

This project uses the [HYG star database](https://github.com/astronexus/HYG-Database) dataset. The data is included in the repository, in the ```data.csv``` file, and consists of the 146 named stars from the original dataset. The main C++ files that read in the data and execute the algorithms are in the main directory. The results and input will be through the console (this input/output is written in the ```main.cpp``` file) and image results will be stored in the ```png_files``` folder.

![](header.png)

INSERT THUMBNAIL OF VIDEO/LINK TO VIDEO HERE

## Running the Program

After the code base is loaded into the EWS system, simply run
```
make
./main
```
This will begin the input/output stream that this program uses to run its algorithms. Finding the shortest path between stars will require the names of both stars. This input is case sensitive and will require restarting the program if the input is incorrect. The names can be found in the ```data.csv``` file.

## Tests

Included in the ```tests``` folder are test cases that test all parts of this program. These tests either use the full dataset, subsets of the full set, or synthetic datasets which are within the ```test_data``` folder to ensure that the program is working as intended.
To run these tests, run
```
make test
./test
```

## Results Write-Up

The discussion of our results is found in the [```results.md``` file](https://github-dev.cs.illinois.edu/cs225-sp21/kpate360-kyliez2-shi46-srirams5/blob/master/Meetings/results.md)
