#include "Container.hpp"


void sort_pair(std::pair<int *, int *> *tab, int nbr_container)
{
    int save_one;
    for (int i = 0; i != nbr_container; ++i)
    {
        if (tab[i].second == NULL)
            break;
        if (*tab[i].first < *tab[i].second)
        {
            save_one = *tab[i].first;
            *tab[i].first = *tab[i].second;
            *tab[i].second = save_one;
        }
    }
}

void step_one(char **arg, int iterator, std::pair<int *, int *> &tab)
{
    int *b;
    int *a = new int(atoi(arg[iterator++]));
    if (arg[iterator] != 0)
        b = new int(atoi(arg[iterator++]));
    else
        b = NULL;
    tab = std::make_pair(a, b);
}

void tabInit(std::pair<int *, int *> *tab, int nbr_container)
{
    int i;
    for (i = 0; i != nbr_container; i++)
        tab[i] = std::pair<int *, int *>(NULL, NULL);
}

int jacobsthal(int n)
{
    if (n == 0 || n == 1)
        return 2;
    return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void changePair(std::pair<int *, int *> *new_tab, int one, int two)
{
    std::pair<int *, int *> temp = new_tab[one];
    new_tab[one] = new_tab[two];
    new_tab[two] = temp;
}

void reverseRange(std::pair<int *, int *> *new_tab, int start, int end)
{
    if (end < start || end == start)
        return;
    std::reverse(new_tab + start, new_tab + end + 1);
}

void deepCopyTab(const std::pair<int *, int *> src[], std::pair<int *, int *> dest[], int nbr_container)
{
    for (int i = 0; i < nbr_container; i++)
    {
        if (dest[i].first != NULL)
        {
            delete dest[i].first;
            dest[i].first = NULL;
        }
        if (dest[i].second != NULL)
        {
            delete dest[i].second;
            dest[i].second = NULL;
        }
        if (src[i].first != NULL)
        {
            dest[i].first = new int(*src[i].first);
        }
        else
        {
            dest[i].first = NULL;
        }

        if (src[i].second != NULL)
        {
            dest[i].second = new int(*src[i].second);
        }
        else
        {
            dest[i].second = NULL;
        }
    }
}


void freetab(std::pair<int *, int *> *tab, int nbr_container)
{
    for (int i = 0; i < nbr_container; i++)
    {
        delete tab[i].first;
        if (tab[i].second != NULL)
            delete tab[i].second;
    }
}
int ft_searchContainer( int nbr)
{
    int b = 00;
    b = nbr / 2;
    if(nbr % 2 != 0)
        nbr++;
    return(b);
}


void insertTabVector(std::pair<int *, int *> *tab, std::pair<int *, int *> *new_tab, int nbr_container, std::vector<int> &out)
{
    int i;
    int j;
    (void)j;
    int index_newTab = 0;
    for (i = 0; i < nbr_container; ++i)
    {
        int *b = tab[i].first;
        int *j = tab[i].second;
        if (i % 2 == 0)
        {
            new_tab[index_newTab].first = b;
            if (j == NULL)
                break;
        }
        else
        {
            new_tab[index_newTab].second = b;
            index_newTab++;
            if (j == NULL)
                break;
        }
        if (j != NULL)
        {
            out.push_back(*j);
        }
    }
    return;
}

void printVector(const std::vector<int> &vec)
{
    std::cout << "\nAfter: ";
    std::vector<int>::const_iterator it;
    for (it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void insertFinalityVector(std::pair<int *, int *> *tab, std::vector<int> &finality)
{
    int *b = tab[0].first;
    if(tab[0].second != NULL)
    {
        int *a = tab[0].second;
        if(*a< *b)
        {
            finality.push_back(*a);
            finality.push_back(*b);
        }
        else
        {
            finality.push_back(*b);
            finality.push_back(*a);
        }
    }
    else
    {
        finality.push_back(*b);
    }
}

void jacobIndexUtilsVector(std::pair<int *, int *> *new_tab, int nbr_container, std::vector<int> &finality)
{
    (void)finality;
    int i = 0;
    int index_jacob = 0;
    int j = 0;
    int save = 0;
    while (jacobsthal(j))
    {
        int result1;
        int result2;
        int index_container = nbr_container;
        i = jacobsthal(j) - 1;
        if (i + save >= nbr_container)
            i = nbr_container - save - 1;
        result1 = save + index_jacob;
        result2 = save + i;
        if (result2 >= nbr_container)
            break;
        reverseRange(new_tab, result1, result2);
        if (save >= index_container)
            break;
        save =jacobsthal(j) + save;
        j++;
    }
}
void printPairArray(std::pair<int *, int *> *tab, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Pair " << i << " : ";
        if (tab[i].first)
            std::cout << "first = " << *(tab[i].first);
        else
            std::cout << "first = NULL";

        std::cout << " | ";

        if (tab[i].second)
            std::cout << "second = " << *(tab[i].second);
        else
            std::cout << "second = NULL";

        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void searchpairVector(std::vector<int> &finality, std::pair<int *, int *> *new_tab, int nbr_container, int nbr)
{
    int i = 0;
    (void)nbr;


    jacobIndexUtilsVector(new_tab, nbr_container, finality);
    
    if (nbr_container == 1)
    {
        std::vector<int> :: iterator low = finality.end();
        int *b = new_tab[i].second;
        finality.insert(low, *b);
        return;
    }

    for (i = 0; i != nbr_container; i++)
    {
        int *b;
        std::vector<int> ::iterator it;
        int *j = new_tab[i].first;
        if (new_tab[i].second != NULL)
        {
            b = new_tab[i].second;
            it = std::find(finality.begin(), finality.end(), *j);
            if (it != finality.end())
            {
                std::vector<int> :: iterator low;
                low = std::lower_bound(finality.begin(), it, *b);
                if (low == it || *low > *b)
                {
                    finality.insert(low, *b);
                }
                else
                {
                    finality.insert(low + 1, *b);
                }
            }
            else
            {

                finality.push_back(*b);
                printVector(finality);
            }
        }
        else
        {
            it = std::find(finality.begin(), finality.end(), *j);
            continue;
        } 
    }
}

void recursif_tabVector(int nbr_container, std::pair<int *, int *> *tab, std::vector<int> &finality, int nbr)
{
    
    int new_nbr_container;
    std::vector<int> out;

    std::pair<int *, int *> recursive_tab[nbr_container];
    deepCopyTab(tab, recursive_tab, nbr_container);

    new_nbr_container = (nbr_container / 2);
    if (nbr_container % 2 != 0)
        new_nbr_container++;
    std::pair<int *, int *> new_tab[new_nbr_container];
    tabInit(new_tab, new_nbr_container);
    insertTabVector(tab, new_tab, nbr_container, out);
    if (new_nbr_container == 1)
    {
        sort_pair(new_tab, new_nbr_container);
        insertFinalityVector(new_tab, finality);
    }
    else
    {
        sort_pair(new_tab, new_nbr_container);
        recursif_tabVector(new_nbr_container, new_tab, finality, nbr);
    }
    searchpairVector(finality, recursive_tab, nbr_container, nbr);
    freetab(recursive_tab, nbr_container);
}

void initVector(char **arg, int ac, std::vector<int> &finality)
{
    int i = 0;
    int j = 0;
    int iterator;
    int nbr_container;
    int save;

    iterator = 1;
    nbr_container = ((ac - 1) / 2);
    if ((ac - 1) % 2 != 0)
        nbr_container++;
    std::pair<int *, int *> tab[nbr_container];
    tabInit(tab, nbr_container);
    for (i = 0; i != nbr_container; i++)
    {
        step_one(arg, iterator, tab[i]);
        j++;
        iterator = iterator + 2;
    }
    sort_pair(tab, nbr_container);
    save = nbr_container;
    std::pair<int *, int *> savetab[nbr_container];
    deepCopyTab(tab, savetab, nbr_container);
    recursif_tabVector(nbr_container, tab, finality,  save);
    printVector(finality);
    freetab(savetab, nbr_container);
    freetab(tab, save);
}

void insertFinalityDeque(std::pair<int *, int *> *tab, std::deque <int> &finality)
{
    int *b = tab[0].first;
    if(tab[0].second != NULL)
    {
        int *a = tab[0].second;
        if(*a< *b)
        {
            finality.push_back(*a);
            finality.push_back(*b);
        }
        else
        {
            finality.push_back(*b);
            finality.push_back(*a);
        }
    }
    else
    {
        finality.push_back(*b);
    }
}



void jacobIndexUtilsDeque(std::pair<int *, int *> *new_tab, int nbr_container, std::deque<int> &finality)
{
    (void)finality;
    int i = 0;
    int index_jacob = 0;
    int j = 0;
    int save = 0;
    while (jacobsthal(j))
    {
        int result1;
        int result2;
        int index_container = nbr_container;
        i = jacobsthal(j) - 1;
        if (i + save >= nbr_container)
            i = nbr_container - save - 1;
        result1 = save + index_jacob;
        result2 = save + i;
        if (result2 >= nbr_container)
            break;
        reverseRange(new_tab, result1, result2);
        if (save >= index_container)
            break;
        save =jacobsthal(j) + save;
        j++;
    }
}
void searchpairDeque(std::deque<int> &finality, std::pair<int *, int *> *new_tab, int nbr_container, int nbr)
{
    int i = 0;
    (void)nbr;


    jacobIndexUtilsDeque(new_tab, nbr_container, finality);
    
    if (nbr_container == 1)
    {
        std::deque<int> :: iterator low = finality.end();
        int *b = new_tab[i].second;
        finality.insert(low, *b);
        return;
    }

    for (i = 0; i != nbr_container; i++)
    {
        int *b;
        std::deque<int> ::iterator it;
        int *j = new_tab[i].first;
        if (new_tab[i].second != NULL)
        {
            b = new_tab[i].second;
            it = std::find(finality.begin(), finality.end(), *j);
            if (it != finality.end())
            {
                std::deque<int> :: iterator low;
                low = std::lower_bound(finality.begin(), it, *b);
                if (low == it || *low > *b)
                {
                    finality.insert(low, *b);
                }
                else
                {
                    finality.insert(low + 1, *b);
                }
            }
            else
            {

                finality.push_back(*b);
            }
        }
        else
        {
            it = std::find(finality.begin(), finality.end(), *j);
            continue;
        } 
    }
}


void insertTabDeque(std::pair<int *, int *> *tab, std::pair<int *, int *> *new_tab, int nbr_container, std::deque<int> &out)
{
    int i;
    int j;
    (void)j;
    int index_newTab = 0;
    for (i = 0; i < nbr_container; ++i)
    {
        int *b = tab[i].first;
        int *j = tab[i].second;
        if (i % 2 == 0)
        {
            new_tab[index_newTab].first = b;
            if (j == NULL)
                break;
        }
        else
        {
            new_tab[index_newTab].second = b;
            index_newTab++;
            if (j == NULL)
                break;
        }
        if (j != NULL)
        {
            out.push_back(*j);
        }
    }
    return;
}

void recursif_tabDeque(int nbr_container, std::pair<int *, int *> *tab, std::deque<int> &finality, int nbr)
{
    
    int new_nbr_container;
    std::deque<int> out;

    std::pair<int *, int *> recursive_tab[nbr_container];
    deepCopyTab(tab, recursive_tab, nbr_container);

    new_nbr_container = (nbr_container / 2);
    if (nbr_container % 2 != 0)
        new_nbr_container++;
    std::pair<int *, int *> new_tab[new_nbr_container];
    tabInit(new_tab, new_nbr_container);
    insertTabDeque(tab, new_tab, nbr_container, out);
    if (new_nbr_container == 1)
    {
        sort_pair(new_tab, new_nbr_container);
        insertFinalityDeque(new_tab, finality);
    }
    else
    {
        sort_pair(new_tab, new_nbr_container);
        recursif_tabDeque(new_nbr_container, new_tab, finality, nbr);
    }
    searchpairDeque(finality, recursive_tab, nbr_container, nbr);
    freetab(recursive_tab, nbr_container);
}

void initDeque(char **arg, int ac, std::deque<int> &finality)
{
    int i = 0;
    int j = 0;
    int iterator;
    int nbr_container;
    int save;

    iterator = 1;
    nbr_container = ((ac - 1) / 2);
    if ((ac - 1) % 2 != 0)
        nbr_container++;
    std::pair<int *, int *> tab[nbr_container];
    tabInit(tab, nbr_container);
    for (i = 0; i != nbr_container; i++)
    {
        step_one(arg, iterator, tab[i]);
        j++;
        iterator = iterator + 2;
    }
    sort_pair(tab, nbr_container);
    save = nbr_container;
    std::pair<int *, int *> savetab[nbr_container];
    deepCopyTab(tab, savetab, nbr_container);
    recursif_tabDeque(nbr_container, tab, finality,  save);
    freetab(savetab, nbr_container);
    freetab(tab, save);
}

Container const& Container::operator=(Container const& obj)
{
    if(this != &obj)
        *this = obj;
    return(*this);
}

Container::Container(Container const& rhs)
{
    if(this != &rhs)
        *this = rhs;
}


Container::~Container()
{
}
Container::Container(int ac, char **arg, std::vector <int> vector)
{
    initVector(arg, ac, vector);
}   

Container::Container(int ac, char **arg, std::deque <int> deque)
{
    initDeque(arg, ac, deque);
}   