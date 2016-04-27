#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <stdlib.h>
#include "Base.h"
#include "Container.h"
#include "Sort.h"
using namespace std;

class Mult : public Base{
     public:
        Base* Left;
        Base* Right;
        Mult(Base* L, Base* R){
             Left = L;
             Right = R;
        }
        double evaluate(){
            return this->Left->evaluate() * this->Right->evaluate();
        }
 };
 
class Div : public Base{
     public:
        Base* Left;
        Base* Right;
        Div(Base* L, Base* R){
             Left = L;
             Right = R;
        }
        double evaluate(){
            return this->Left->evaluate() / this->Right->evaluate();
        }
 };

class Sub : public Base{
     public:
        Base* Left;
        Base* Right;
        Sub(Base* L, Base* R){
             Left = L;
             Right = R;
        }
        double evaluate(){
            return this->Left->evaluate() - this->Right->evaluate();
        }
 };

class Add : public Base{
     public:
        Base* Left;
        Base* Right;
        Add(Base* L, Base* R){
             Left = L;
             Right = R;
        }
        double evaluate(){
            return this->Left->evaluate() + this->Right->evaluate();
        }
 };
 
class Sqr : public Base{
     public:
        Base* Left;
        Sqr(Base* L){
             Left = L;
        }
        double evaluate(){
            return this->Left->evaluate() * this->Left->evaluate();
        }
 };
 
 class Op : public Base{
     public:
        double value;
        Op(double val){
            value = val;
        }
        double evaluate(){
            return this->value;
        }
 };

class VectorContainer: public Container{
    public:
        vector<Base*> contents;
        void add_element(Base* element){
            this->contents.push_back(element);
        }
        void print(){
            for(int i = 0; i < this->contents.size(); ++i){
                cout << this->contents.at(i)->evaluate() << " ";
            }
            cout << endl;
        }
        void sort(){
            if(sort_function == NULL){
                cout << "Throw Exception" << endl;
                exit (0);
            }
            else{
                sort_function->sort(this);
            }
        }
        void swap(int i, int j){
            Base* temp = this->contents.at(i);
            this->contents.at(i) = this->contents.at(j);
            this->contents.at(j) = temp;
        }
        Base* at(int i){
            return this->contents.at(i);
        }
        int size(){
            return this->contents.size();
        }
};

class ListContainer: public Container{
    public:
        list<Base*> contents;
        void add_element(Base* element){
            this->contents.push_back(element);
        }
        void print(){
            for(list<Base*>::iterator itr = this->contents.begin(); itr != this->contents.end(); ++itr){ 
                cout << (*itr)->evaluate() << ' ';
            }
            cout << endl;
        }
        void sort(){
            if(sort_function == NULL){
                cout << "Throw Exception" << endl;
                exit (0);
            }
            else{
                sort_function->sort(this);
            }
        }
        void swap(int i, int j){
            list<Base*>::iterator itri = this->contents.begin();
            list<Base*>::iterator itrj = this->contents.begin();
            advance(itri, i);
            advance(itrj, j);
            Base * temp = *itri;
            *itri = *itrj;
            *itrj = temp;
            
        }
        Base* at(int i){
            list<Base*>::iterator itr = this->contents.begin();
            advance(itr, i);
            return *itr;
        }
        int size(){
            return contents.size();
        }
};


class BubbleSort : public Sort {
    void sort(Container* container){
        bool flag = true;   //was a switch made?
        while(flag){        //if so, continue switching things
            flag = false;
            for(int i = 0; i < container->size() - 1; ++i){
                if(container->at(i)->evaluate() > container->at(i + 1)->evaluate()){
                    container->swap(i, i + 1);
                    flag = true;
                }
            }
        }
    }
};

class SelectionSort : public Sort {
    //finds the smallest value and moves it to far left and continues to end
    void sort(Container* container){
        for(int i = 0; i < container->size(); ++i){
            int min = i;
            for(int j = i + 1; j < container->size(); ++j){
                if(container->at(j)->evaluate() < container->at(min)->evaluate()){
                    min = j;
                }
            }
            container->swap(i, min);
        }
    }
};

int main(){
    Op* op7=new Op(7);
    Op* op4=new Op(4);
    Op* op3=new Op(3);
    Op* op2=new Op(2);
    Mult* A=new Mult(op7,op4);
    Add* B=new Add(op3,A);
    Sub* C=new Sub(B,op2);
    Sqr* D=new Sqr(C);
    
    ListContainer* container = new ListContainer;
    container->add_element(A);
    container->add_element(B);
    container->add_element(C);
    container->add_element(D);
    
    
    
    cout << "Container before sort" << endl;
    container->print();
    cout << "Container after sort" << endl;
    container->set_sort_function(new SelectionSort());
    container->sort();
    container->print();
    return 0;
}