# closestPair
finds the closest pair of points out of one million points

This program returns the distance between the closest pair of many points quickly.  In this case, the program reads in a file(provided) of one million points each represented by two doubles, an x and a y value.  Each of the doubles are positive and lie between zero and one.  The method used in this program is much more efficient than comparing every point to every other point and updating the smallest distance because that would take quite a while.
Instead, it sweeps across the 2D plane along the x-axis comparing the most recently discovered point to the ones before it who also have x and y values within the shortest distance found so far.  If a shorter distance is found, then the one that is stored is updated and the sweep continues until all points have been covered.
