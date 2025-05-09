
#include "Container.hpp"
#include "Validator.hpp"
#include <vector>
#include <string>
#include <stdlib.h>

void Container::ImplementVector(char* arg)
{
    int i = 0;
    while(arg[i])
    {
        while(arg[i] == ' ')
            i++;
        if(arg[i]=='\0')
            break;
        if(arg[i] >='0' && arg[i] <='9')
        {
            this->algebra.push((arg[i]-'0'));
        }
        else if (arg[i] == '+' || arg[i] == '*' || arg[i] == '/' || arg[i] == '-')
        {
            if(this->algebra.size() < 2)
            {
                break;
            }
            int save = algebra.top();
            this->algebra.pop();
            int save2 =algebra.top();
            this->algebra.pop();
            if (arg[i] == '+')
            {
                this->algebra.push(save2 + save);
            }
            else if (arg[i] == '-')
            {
                this->algebra.push(save2 - save);
            }
            else if (arg[i] == '*')
            {
                this->algebra.push(save2 * save);
            }
             else if (arg[i] == '/')
             {
                if(save == 0 || save2 == 0)
                    this->algebra.push(0);
                else
                    this->algebra.push(save2 / save);   
             }
        }
        else
        {
            std::cerr<<"Erreur"<< std::endl;
            return;
        }
        i++;
    }
    if(this->algebra.size() != 1)
    {
        std::cerr<<"Erreur"<< std::endl;
        return;
    }

        std::cout << algebra.top()<<std::endl;
}

Container::Container(int ac, char **arg)
{
    try{
        Validator::validArg(ac , arg);
        ImplementVector(arg[1]);

    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

Container::~Container()
{
}