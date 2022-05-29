#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "./ordered_vector.cpp"

SCENARIO("OrderedVector receives new items and keep it ordered") {

    GIVEN("An empty vector") {
        OrderedVector v;

        REQUIRE( v.size() == 0 );

        WHEN("insert an item") {
            v.insert(1);

            THEN("it's ordered trivially") {
                REQUIRE( v.size() == 1 );
                REQUIRE( v.read(0) == 1 );
                REQUIRE( v.search(1) == 0 );
            }

        }
    }

    GIVEN("A vector with one element") {
        int initialValue = 10;
        int items[1] = {initialValue};
        OrderedVector v (1, items);

        WHEN("insert a smaller item") {
            int newValue = 8;
            v.insert(newValue);

            THEN("it is preppended") {
                REQUIRE( v.size() == 2 );
                REQUIRE( v.read(0) == newValue );
                REQUIRE( v.read(1) == initialValue );
            }
        }

        WHEN("insert a bigger item") {
            int newValue = 12;
            v.insert(newValue);

            THEN("it is appended") {
                REQUIRE( v.size() == 2 );
                REQUIRE( v.read(0) == initialValue );
                REQUIRE( v.read(1) == newValue );
            }
        }

    }

    GIVEN("A vector with two elements already sorted") {
        int biggerInitialValue = 10;
        int smallerInitialValue = 5;
        int items[2] = {smallerInitialValue, biggerInitialValue};
        OrderedVector v (2, items);

        WHEN("insert a smaller than all them") {
            int newValue = 2;
            v.insert(newValue);

            THEN("it is preppended") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == newValue );
                REQUIRE( v.read(1) == smallerInitialValue );
                REQUIRE( v.read(2) == biggerInitialValue );
            }
        }

        WHEN("insert a bigger than all them") {
            int newValue = 12;
            v.insert(newValue);

            THEN("it is appended") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == smallerInitialValue );
                REQUIRE( v.read(1) == biggerInitialValue );
                REQUIRE( v.read(2) == newValue );
            }
        }

        WHEN("insert an item smaller than one and bigger than other one") {
            int newValue = 7;
            v.insert(newValue);

            THEN("it is insert in the middle") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == smallerInitialValue );
                REQUIRE( v.read(1) == newValue );
                REQUIRE( v.read(2) == biggerInitialValue );
            }
        }
    }

    GIVEN("A vector with two elements not sorted") {
        int biggerInitialValue = 10;
        int smallerInitialValue = 5;
        int items[2] = {biggerInitialValue, smallerInitialValue};
        OrderedVector v (2, items);

        WHEN("insert a smaller than all them") {
            int newValue = 2;
            v.insert(newValue);

            THEN("it is preppended") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == newValue );
                REQUIRE( v.read(1) == smallerInitialValue );
                REQUIRE( v.read(2) == biggerInitialValue );
            }
        }

        WHEN("insert a bigger than all them") {
            int newValue = 12;
            v.insert(newValue);

            THEN("it is appended") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == smallerInitialValue );
                REQUIRE( v.read(1) == biggerInitialValue );
                REQUIRE( v.read(2) == newValue );
            }
        }

        WHEN("insert an item smaller than one and bigger than other one") {
            int newValue = 7;
            v.insert(newValue);

            THEN("it is insert in the middle") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == smallerInitialValue );
                REQUIRE( v.read(1) == newValue );
                REQUIRE( v.read(2) == biggerInitialValue );
            }
        }
    }

    GIVEN("A vector with two identic elements") {
        int initialValue = 10;
        int items[2] = {initialValue, initialValue};
        OrderedVector v (2, items);

        WHEN("insert a smaller value") {
            int newValue = 2;
            v.insert(newValue);

            THEN("it is preppended") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == newValue );
                REQUIRE( v.read(1) == initialValue );
                REQUIRE( v.read(2) == initialValue );
            }
        }

        WHEN("insert a bigger value") {
            int newValue = 12;
            v.insert(newValue);

            THEN("it is appended") {
                REQUIRE( v.size() == 3 );
                REQUIRE( v.read(0) == initialValue );
                REQUIRE( v.read(1) == initialValue );
                REQUIRE( v.read(2) == newValue );
            }
        }
    }
}
