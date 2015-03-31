#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            puts("A");
            return 0;
        case 2:
            puts("C");
            return 0;
        case 3:
            puts("C");
            return 0;
        case 4:
            puts("C");
            return 0;
        case 5:
            puts("B");
            return 0;
        case 6:
            puts("C");
            return 0;
        case 7:
            puts("A");
            return 0;
        case 8:
            puts("B");
            return 0;
        case 9:
            puts("C");
            return 0;
        case 10:
            puts("A");
            return 0;
    }
    return 0;
}
/*
B. Quiz
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

This is not a typical problem for programming competitions. It can't be used in a serious contests, the right place for this problem is a trial contest. To one side it will be a little fun for you, and on the other hand — it is a good task to test an environment. Bring to your attention a quiz.

Please, do not use Internet to find answers.

It consists of ten questions. There are ten tests in the complete testset, one per each question. A test consists of a single integer number between 1 and 10 — a question number. Also it is guaranteed that the test index is the same as a question number in it. So the first test contains 1, the second test contains 2 and so on. The pretests are the first six tests.

Write a program printing the correct answer on each test.

What is a measure of an electric current? A: ampere, B: volt, С: watt

What is the Earth's highest mountain? A: Mount Elbrus, B: Mount Kilimanjaro, С: Mount Everest

What countries met in the FIFA World Cup Finals 2002? A: France and Argentina, B: France and Germany, С: Germany and Brazil

What kind of sports is NOT part of athletics? A: shot put, B: pole vault, С: diving

Freon — is a ... A: rocket propellant, B: refrigerant, С: gas to fill the gas discharge tubes

What is the biggest planet in the Solar System? A: Uranus, B: Pluto, С: Jupiter

Which U.S. president is on the one dollar bill? A: George Washington, B: Benjamin Franklin, С: Abraham Lincoln

How many legs a spider has? A: 6, B: 8, С: 10

Who wrote "Gulliver's Travels"? A: Daniel Defoe, B: Jules Verne, С: Jonathan Swift

What is the law which describes how the pressure of a gas tends to decrease as the volume of a gas increases? A: Boyle-Mariotte, B: Gay-Lussac, С: Mendeleev-Clapeyron

Input

The input contains the only integer number n (1 ≤ n ≤ 10). It is guaranteed that the question index is equal to n.
Output

Print "A", "B" or "C".
Sample test(s)
Input

1

Output

A
*/
