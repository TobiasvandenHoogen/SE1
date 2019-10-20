#include "catch.hpp"
#include "IntSet.hpp"

    //test for type and size in int array with size 5
    TEST_CASE("IntSet int, test type and size"){
        IntSet<int, 3> i;
        i.add(3);
        i.add(6);
        i.add(8);
        i.add(7);
        i.add(2);
        REQUIRE(i.MaxElement() == 8);
    }
