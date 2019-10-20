#include "catch.hpp"
#include "IntSet.hpp"

    //test for type and size in int array with size 3
    TEST_CASE("IntSet int, test type and size"){
        IntSet<int, 3> i;
        for(int j = 0; j < 15; j++){
            i.add(j);
        }
        REQUIRE(i.contains(3) == false);
    }

    //test for type and size in float array with size 15
    TEST_CASE("IntSet float, add function"){
        IntSet<float, 15> i;
        for(float j = 0; j < 15; j++){
            i.add(j);
        }
        REQUIRE(i.contains(14) == true);
    }