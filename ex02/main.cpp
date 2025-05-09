#include <iostream>
#include <string>
#include <string.h>
#include <list>
#include "Container.hpp"
#include "Validator.hpp"
#include <vector>
#include <deque>
#include <time.h>
#include <iomanip>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
double getCurrentTimeMicros() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

int main(int ac, char **arg)
{
    double startTime, endTime, endTime1;
    startTime = getCurrentTimeMicros();
    std::string test;
    try
    {
        Validator::validArg(ac, arg);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return(2);
    }

    std::cout << "Before";   
    for(int i  =1;  i != ac ;++i)
    {
        std::string temp = arg[i];
        temp = temp.substr(1);  
        if(arg[i][0]=='+' && strlen(arg[i])>0)
        {
            temp = temp.substr(0); 
            std::cout <<" "<< temp;
            continue;
        }
        std::cout <<" "<< arg[i];
    }

    std::vector<int>vec;
    if(ac != 2)
    {
        Container v(ac, arg, vec);
    }else
    {
        std::cout << "\nAfter: " << arg[1] <<std::endl;
    }
    endTime = getCurrentTimeMicros();
    endTime = (endTime - startTime)  ;
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of "<< ac-1 <<" elements with std::[vector] :" << endTime<< " us"<< std::endl;

    std::deque<int> deq;
    if(ac != 2)
        Container d (ac, arg, deq);
    endTime1 = getCurrentTimeMicros();
    endTime1 = (endTime1 - startTime)  ;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of "<< ac-1 <<" elements with std::[deque] :" << endTime1 - endTime << " us"<< std::endl;

}