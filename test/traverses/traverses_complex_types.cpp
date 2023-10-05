#define CATCH_CONFIG_MAIN
#include "../../lib/catch.hpp"

#include "../../src/binary_tree/BinaryTree.hpp"
#include "../../src/person/Person.hpp"

#include <string>

TEST_CASE()
{
    BinaryTree<Person> myPersonsTree = BinaryTree<Person>(Person("John", "Doe", 20));

    myPersonsTree.addNode(Person("Jane", "Doe", 19));
    myPersonsTree.addNode(Person("John", "Doe", 21));
    myPersonsTree.addNode(Person("Jane", "Doe", 18));

    SECTION("Pre-order")
    {

        INFO("Testing preOrder() method");

        list<Person> myPersonsListExpected = {
            Person("John", "Doe", 20),
            Person("Jane", "Doe", 19),
            Person("Jane", "Doe", 18),
            Person("John", "Doe", 21)};

        list<Person> myPersonsList = myPersonsTree.preOrder();

        REQUIRE(myPersonsList == myPersonsListExpected);
    }
    SECTION("In-order")
    {
        INFO("Testing inOrder() method");

        list<Person> myPersonsListExpected = {
            Person("Jane", "Doe", 18),
            Person("Jane", "Doe", 19),
            Person("John", "Doe", 20),
            Person("John", "Doe", 21)};

        list<Person> myPersonsList = myPersonsTree.inOrder();

        REQUIRE(myPersonsList == myPersonsListExpected);
    }
    SECTION("Post-order")
    {
        INFO("Testing postOrder() method");

        list<Person> myPersonsListExpected = {
            Person("Jane", "Doe", 18),
            Person("Jane", "Doe", 19),
            Person("John", "Doe", 21),
            Person("John", "Doe", 20)};

        list<Person> myPersonsList = myPersonsTree.postOrder();

        REQUIRE(myPersonsList == myPersonsListExpected);
    }
}