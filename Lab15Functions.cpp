#include <iostream>
double factorial(int);
/*******************************************************************
* getInfo *
* Gets and validates lottery info from the user and places it in   *
* reference parameters referencing variables in the main function. *
*******************************************************************/

void getInfo(int & pickFrom, int & numPicks){
    using namespace std;
    if(pickFrom<1 || pickFrom>12){
        cout << "How many balls (1-12) are in the pool to pick from? ";
        cin >> pickFrom;
        if (pickFrom<1 || pickFrom>12){
            cout<<"Input Error!"<<endl;
            getInfo(pickFrom, numPicks);
        }
    }
    if(numPicks<1 || numPicks>7){
        cout<<"How many balls (1-7) will be drawn? ";
        cin>>numPicks;
        if (numPicks<1 || numPicks>7){
            cout<<"Input Error!"<<endl;
            getInfo(pickFrom, numPicks);
        }
    }

}

/******************************************************************
* computeWays                                                     *
* Computes and returns the number of different possible sets      *
* of k numbers that can be chosen from a set of n numbers.        *
* The formula for this is     k!(n- k)!                           *
*                             --------                            *
*                                 n!                              *
*******************************************************************/
// Note that the computation is done in a way that does not require
// multiplying two factorials together. This is done to prevent any
// intermediate result becoming so large that it causes overflow.
double computeWays(int n, int k){
int h = n - k;
    double answer = factorial(k)*factorial(h)/factorial(n);
    return answer;
}

// This function computes factorials recursively. It is called by computeWays.
double factorial(int n){
if(n==0){
    return 1;
} return n*factorial(n-1);
}