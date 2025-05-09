#pragma once
#include <iostream>
#include <string>
#include <regex.h>
#include <exception>
#include <climits> 
class Validator: public std::exception
{
    public:
        static void validArg(int ac , char **arg)
        {
            if(ac==1)
                throw std::runtime_error("Number argument invalid");
            regex_t format;
            int i = 1;

            if(regcomp(&format,"^[+]?[0-9]+$" , REG_EXTENDED) != 0)
                throw std::runtime_error("Regex not ok");
            while(arg[i])
            {
                if(regexec(&format, arg[i], 0, NULL, 0) == 0)
                {
                    int nbr = atoi(arg[i]);
                    if(nbr > INT_MAX || nbr < 0)
                        throw std::runtime_error("Number sup int max");

                }
                else
                {
                    regfree(&format);
                    throw std::runtime_error("Format invalid");
                    return;
                }
                i++;
           }
           regfree(&format);
        }
};