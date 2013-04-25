/*
 * File: RandomSubsets.cpp
 * ----------------------
 * Section: SCPD, Aaron Broder <abroder@stanford.edu>
 * Copyright 2013 Eric Beach <ebeach@google.com>
 * Assignment 3 - Pt. 0B - Random Subsets
 *
 */

#include <iostream>
#include "set.h"
#include "random.h"
#include "console.h"
using namespace std;

/* Given a set of integers, returns a uniformly-random subset of that
 * set.
 */
Set<int> randomSubsetOf(Set<int>& s);
void printRandomSubset(Set<int>& toPrint);
const int NUM_ELEMS_TO_POPULATE = 5;

int main() {
    Set<int> mastrSet;
    mastrSet += 2, 4, 50, 23, 2390, 2, 390, 2, 29, 1, 9, 4, 593, 290;
    
    Set<int> randomSubset = randomSubsetOf(mastrSet);
    printRandomSubset(randomSubset);
    return 0;
}

Set<int> getRandomSubsetOf(Set<int>& masterSet, Set<int>& newSet) {
    if (newSet.size() >= NUM_ELEMS_TO_POPULATE) {
        // base case: new set is fully populated
        return newSet;
    } else if (masterSet.size() == 0) {
        // base case: master set is empty
        return newSet;
    } else {
        // recursive case
        int elem = masterSet.first();
        if (randomInteger(0, 9) >= 3) {
            newSet += elem;
        }
        masterSet -= elem;
        return getRandomSubsetOf(masterSet, newSet);
    }
}

Set<int> randomSubsetOf(Set<int>& s) {
    Set<int> newSet;
    return getRandomSubsetOf(s, newSet);
}

void printRandomSubset(Set<int>& toPrint) {
    if (toPrint.size() == 0) {
        // base case
        return;
    } else {
        // recursive case
        int elem = toPrint.first();
        cout << elem << endl;
        toPrint -= elem;
        printRandomSubset(toPrint);
    }
}
