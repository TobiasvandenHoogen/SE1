#ifndef INTSET_HPP
#define INTSET_HPP

#include <array>
#include <iostream>
#include <algorithm>

template <typename T,unsigned int N>

class IntSet{
protected:
    std::array<T, N> Set;   //the template array
    size_t size = 0;        //index attribute

public:

    //inserts the given value if it doesn't already contains in the set
    void add(T n){
        if((size < N) && (!contains(n))){   
            Set[size] = n;
            size++;
        }
    }

    //removes given value if it contains in the set 
    void remove(T n){
        if(contains(n)){
            std::remove(Set.begin(), Set.end(), n);
            size--;
        }   
    }

    //checks if given value is in set 
    bool contains(T n){
        for(size_t i = 0; i < size; i++){
            if(Set[i] == n){
                return true;
            }
        }
        return false;
    }

    //returns the maxvalue of a set 
    T MaxElement(){
        T maxvalue = Set[0];
        for(size_t i = 1; i < size; i++){
            if(Set[i] > maxvalue){
                maxvalue = Set[i];
            }
        }
        return maxvalue;
    }


    template <typename S,unsigned int M>
    friend std::ostream& operator<<(std::ostream & os, const IntSet<S, M> & set);


};

    //operator ostream overloading to print the set 
    template <typename S,unsigned int M>
    std::ostream& operator<<(std::ostream & os, const IntSet<S, M> & set){
        for(S i = 0; i < set.size; i++){
            os << set.Set[i] << '\n';
        }
        return os;
    }

#endif 