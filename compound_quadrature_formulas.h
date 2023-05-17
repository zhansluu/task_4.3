#ifndef COMPOUND_QUADRATURE_FORMULAS_H_INCLUDED
#define COMPOUND_QUADRATURE_FORMULAS_H_INCLUDED

#include "functions.h"

double leftRectangles (size_t num, double w, double step, double a)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+w);
        case 1:
            return step*(polinom1degree(a)+w);
        case 2:
            return step*(polinom2degree(a)+w);
        case 3:
            return step*(polinom3degree(a)+w);
        case 4:
            return step*(func(a)+w);
        case 5:
            return step*(f(a)+w);
        }
    return 0;
}

double rightRectangles (size_t num, double w, double step, double n, double a)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+w);
        case 1:
            return step*(polinom1degree(a+n*step)+w);
        case 2:
            return step*(polinom2degree(a+n*step)+w);
        case 3:
            return step*(polinom3degree(a+n*step)+w);
        case 4:
            return step*(func(a+n*step)+w);
        case 5:
            return step*(f(a+n*step)+w);
        }
    return 0;
}

double middleRectangles(size_t num, double q, double step)
{
    return step*q;
}

double trapeze(size_t num, double w, double step, double n, double a)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+polinom0degree()+2*w)/2;
        case 1:
            return step*(polinom1degree(a)+polinom1degree(a+n*step)+2*w)/2;
        case 2:
            return step*(polinom2degree(a)+polinom2degree(a+n*step)+2*w)/2;
        case 3:
            return step*(polinom3degree(a)+polinom3degree(a+n*step)+2*w)/2;
        case 4:
            return step*(func(a)+func(a+n*step)+2*w)/2;
        case 5:
            return step*(f(a)+f(a+n*step)+2*w)/2;
        }
    return 0;
}

double simpson(size_t num, double w, double q, double step, double n, double a)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+polinom0degree()+2*w+4*q)/6;
        case 1:
            return step*(polinom1degree(a)+polinom1degree(a+n*step)+2*w+4*q)/6;
        case 2:
            return step*(polinom2degree(a)+polinom2degree(a+n*step)+2*w+4*q)/6;
        case 3:
            return step*(polinom3degree(a)+polinom3degree(a+n*step)+2*w+4*q)/6;
        case 4:
            return step*(func(a)+func(a+n*step)+2*w+4*q)/6;
        case 5:
            return step*(f(a)+f(a+n*step)+2*w+4*q)/6;
        }
    return 0;
}

#endif // COMPOUND_QUADRATURE_FORMULAS_H_INCLUDED
