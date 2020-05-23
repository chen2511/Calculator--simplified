#ifndef FLOATNUMBER_H
#define FLOATNUMBER_H

#endif // FLOATNUMBER_H
#include <iostream>
using namespace std;

struct node{
    int flag;
    union{
        double a; //flag==0
        char op;    //flag==1
    }num;
};
