#ifndef CONTAINER_H
#define CONTAINER_H
//#include "Sort.h"
class Sort;
class Container{
    protected:
        Sort* sort_function;
    public:
    /*Constructors*/
    Container () : sort_function(NULL){};
    Container (Sort* function) : sort_function(function){};
    
    /*NonVirtualFunctions*/
    void set_sort_function(Sort* function){
        sort_function = function;
    }//setthetypeof sortingalgorithm
    
    /*PureVirtualFunctions*/
    //pushthetoppointerofthetreeintocontainer
    virtual void add_element(Base* element)=0;
    //iteratethroughtreesandoutputvalues
    virtual void print()=0;
    //callsonthepreviouslysetsortingalgorithm.Checksifsort_functionisnotnull,throwexceptionifotherwise
    virtual void sort()=0;
    /*Essentiallytheonlyfunctionsneededtosort*/
    //switchtreelocations
    virtual void swap(int i, int j)=0;
    //gettopptroftreeatindexi
    virtual Base* at(int i)=0;
    //returncontainersize
    virtual int size()=0;
};
#endif