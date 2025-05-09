#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <deque>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include "Validator.hpp"

class Container
{
    public:
        ~Container();
        void includeTab(int ac, char **arg);
        Container const& operator=(Container const& rhs);
        Container(Container const& obj);
       
        Container(int ac, char **arg, std::vector <int> vector);
        Container(int ac, char **arg, std::deque <int> deque);

};