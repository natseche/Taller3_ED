#define CATCH_CONFIG_MAIN
#include "../../lib/catch.hpp"

#include "../../src/binary_tree/BinaryTree.hpp"

#include <string>

TEST_CASE("BinaryTree - Traverses - Primitive Types", "[traverses][primitive_types]")
{

    /* Trees */
    BinaryTree<int> myIntegersTree = BinaryTree<int>(5);
    BinaryTree<float> myFloatsTree = BinaryTree<float>(5.5);
    BinaryTree<char> myCharsTree = BinaryTree<char>('g');
    BinaryTree<string> myStringsTree = BinaryTree<string>("Hello");

    /* Adding integers */
    myIntegersTree.addNode(3);
    myIntegersTree.addNode(7);
    myIntegersTree.addNode(2);
    myIntegersTree.addNode(4);
    myIntegersTree.addNode(6);
    myIntegersTree.addNode(8);

    /* Adding floats */
    myFloatsTree.addNode(3.3);
    myFloatsTree.addNode(7.7);
    myFloatsTree.addNode(2.2);
    myFloatsTree.addNode(4.4);
    myFloatsTree.addNode(6.6);
    myFloatsTree.addNode(8.8);

    /* Adding chars */
    myCharsTree.addNode('b');
    myCharsTree.addNode('c');
    myCharsTree.addNode('d');
    myCharsTree.addNode('e');
    myCharsTree.addNode('f');
    myCharsTree.addNode('h');

    /* Adding strings */
    myStringsTree.addNode("World");
    myStringsTree.addNode("!");
    myStringsTree.addNode("How");
    myStringsTree.addNode("are");
    myStringsTree.addNode("you");
    myStringsTree.addNode("doing");

    SECTION("Pre-order")
    {
        INFO("Testing preOrder() method");

        /* Expected lists */
        list<int> myIntegersListExpected = {5, 3, 2, 4, 7, 6, 8};
        list<float> myFloatsListExpected = {5.5, 3.3, 2.2, 4.4, 7.7, 6.6, 8.8};
        list<char> myCharsListExpected = {'g', 'b', 'c', 'd', 'e', 'f', 'h'};
        list<string> myStringsListExpected = {"Hello", "!", "World", "How", "are", "you", "doing"};

        /* Getting lists from preOrder method*/
        list<int> myIntegersList = myIntegersTree.preOrder();
        list<float> myFloatsList = myFloatsTree.preOrder();
        list<char> myCharsList = myCharsTree.preOrder();
        list<string> myStringsList = myStringsTree.preOrder();

        REQUIRE(myIntegersList == myIntegersListExpected);
        REQUIRE(myFloatsList == myFloatsListExpected);
        REQUIRE(myCharsList == myCharsListExpected);
        REQUIRE(myStringsList == myStringsListExpected);
    }

    SECTION("In-order")
    {
        INFO("Testing inOrder() method");

        /* Expected lists */
        list<int> myIntegersListExpected = {2, 3, 4, 5, 6, 7, 8};
        list<float> myFloatsListExpected = {2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8};
        list<char> myCharsListExpected = {'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        list<string> myStringsListExpected = {"!", "Hello", "How", "World", "are", "doing", "you"};

        /* Getting lists from preOrder method*/
        list<int> myIntegersList = myIntegersTree.inOrder();
        list<float> myFloatsList = myFloatsTree.inOrder();
        list<char> myCharsList = myCharsTree.inOrder();
        list<string> myStringsList = myStringsTree.inOrder();

        REQUIRE(myIntegersList == myIntegersListExpected);
        REQUIRE(myFloatsList == myFloatsListExpected);
        REQUIRE(myCharsList == myCharsListExpected);
        REQUIRE(myStringsList == myStringsListExpected);
    }

    SECTION("Post-order")
    {
        INFO("Testing postOrder() method");

        /* Expected lists */
        list<int> myIntegersListExpected = {2, 4, 3, 6, 8, 7, 5};
        list<float> myFloatsListExpected = {2.2, 4.4, 3.3, 6.6, 8.8, 7.7, 5.5};
        list<char> myCharsListExpected = {'f', 'e', 'd', 'c', 'b', 'h', 'g'};
        list<string> myStringsListExpected = {"!", "How", "doing", "you", "are", "World", "Hello"};

        /* Getting lists from preOrder method*/
        list<int> myIntegersList = myIntegersTree.postOrder();
        list<float> myFloatsList = myFloatsTree.postOrder();
        list<char> myCharsList = myCharsTree.postOrder();
        list<string> myStringsList = myStringsTree.postOrder();

        REQUIRE(myIntegersList == myIntegersListExpected);
        REQUIRE(myFloatsList == myFloatsListExpected);
        REQUIRE(myCharsList == myCharsListExpected);
        REQUIRE(myStringsList == myStringsListExpected);
    }
}