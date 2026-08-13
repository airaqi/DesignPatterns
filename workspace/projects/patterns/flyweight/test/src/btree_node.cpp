#include "btree_node.hpp"
#include "doctest_main.h"

TEST_CASE("BtreeNode") 
{
    SUBCASE("Init")
    {
        Node<int>::Ptr root = Node<int>::create(0, 0);
        CHECK_EQ(0, root->getValue(0));
    }

    SUBCASE("insert")
    {
        Node<int>::Ptr root = Node<int>::create(0, 0);
        root->insert(0, 10);

        CHECK_EQ(10, root->getSpan());
    }

    SUBCASE("setValue")
    {
        Node<int>::Ptr root = Node<int>::create(0, 0);
        INFO("root node: " << root->to_string());

        root->insert(0, 10);
        INFO("root node: " << root->to_string());

        root->setValue(3, 2, 2);

        INFO("root node: " << root->to_string());

        CHECK_EQ(0, root->getValue(0));
        CHECK_EQ(2, root->getValue(3));
    }

    SUBCASE("toString")
    {
        auto root = Node<int>::create(0, 0);
        
    }
}
