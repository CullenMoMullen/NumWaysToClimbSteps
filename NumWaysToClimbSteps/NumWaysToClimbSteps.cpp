// NumWaysToClimbSteps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

using namespace std;


uint64_t numWays(int numStairs, set<int>& intervals);


ostream& operator<<(ostream& out, set<int> li) {
    set<int>::size_type i = 0;
    for (set<int>::iterator itr = li.begin(); itr != li.end(); itr++)
    {
        out << *itr;
        if (i++ < li.size() - 1) { out << ", "; }
    }
    return out;
}

int main()
{
    int n;
    cout << "How many steps: "; cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int y;
    cout << endl << "How many step intervals: ";
    cin >> y;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    set<int> intervals;

    int i;
    while (y--) {
        cin >> i;
        if (intervals.find(i) != intervals.end()) {
            y++;
            cout << "Value (" << i << ") already included in set: { " << intervals << " }!" << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        intervals.insert(i);
    }
    cout << endl << "You may take the following number of steps per move: { " << intervals << " }" << endl;
    cout << numWays(n, intervals);
}


uint64_t numWays(int numStairs, set<int>& intervals) {
    if (numStairs == 0) return 1;
    uint64_t num = 0;
    for (auto a : intervals) {
        if (numStairs - a >= 0) {
            num += numWays(numStairs - a, intervals);
        }
    }
    return num;

}
