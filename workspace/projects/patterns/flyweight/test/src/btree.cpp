#include "btree.hpp"
#include "doctest_main.h"
#include <optional>

TEST_CASE("Btree")
{
    SUBCASE("init")
    {
        Btree<int> tree(0, 0);
        
        CHECK_EQ(0, tree.getTotalSpan());
        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(std::optional<int>(), tree.getValue(1));
        CHECK_EQ("[id: 1 is_leaf: true span: 0 value: 0 children: [] ]", tree.to_string());
    }

    SUBCASE("insert")
    {
        Btree<int> tree(0, 0);
        tree.insert(0, 5);

        INFO("getValue(5): " << tree.getValue(6).value());

        CHECK_EQ(5, tree.getTotalSpan());
        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(0, tree.getValue(4));
        CHECK_EQ(true, tree.getValue(5).has_value());
        CHECK_EQ(false, tree.getValue(6).has_value());
        CHECK_EQ("[id: 2 is_leaf: true span: 5 value: 0 children: [] ]", tree.to_string());
    }

    SUBCASE("increase insert")
    {
        Btree<int> tree(0, 0);
        tree.insert(0, 5);
        tree.insert(0, 10);

        CHECK_EQ(15, tree.getTotalSpan());
        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(0, tree.getValue(10));
    }

    SUBCASE("setValue")
    {
        Btree<int> tree(0, 0);
        tree.insert(0, 3);
        tree.setValue(2, 2, 1);

        CHECK_EQ(3, tree.getTotalSpan());
    }

    SUBCASE("splitSpans")
    {
        Btree<int> tree(0, 0);
        tree.insert(0, 5);
        tree.setValue(3, 1, 1);

        INFO("splitSpans: " << tree.to_string());

        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(0, tree.getValue(2));
        CHECK_EQ(1, tree.getValue(3));
        CHECK_EQ(0, tree.getValue(4));

        CHECK_EQ(5, tree.getTotalSpan());
        CHECK_EQ(3, tree.size());
    }

    SUBCASE("splitSegments")
    {
        Btree<int> tree(0, 0);
        tree.insert(0, 10);
        tree.setValue(3, 2, 1);

        INFO("splitSegments: " << tree.to_string());

        CHECK_EQ(3, tree.size());
        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(1, tree.getValue(3));
        CHECK_EQ(0, tree.getValue(9));
    }

    SUBCASE("SplitSpansToParent")
    {
        Btree<int> tree(0, 0);
        tree.insert(0, 10);
        tree.setValue(3, 2, 1);
        tree.setValue(5, 4, 2);

        INFO("tree: " << tree.to_string());

        CHECK_EQ(4, tree.size());
        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(2, tree.getValue(6));
        CHECK_EQ(1, tree.getValue(3));
        CHECK_EQ(0, tree.getValue(9));
    }

    SUBCASE("SetValueAtTail")
    {
        Btree<int> tree(10, 0);
        tree.setValue(9, 1, 1);

        INFO("tree: " << tree.to_string());
        INFO("tree size: " << tree.size());

        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(0, tree.getValue(8));
        CHECK_EQ(1, tree.getValue(9));
        CHECK_EQ(std::optional<int>(0), tree.getValue(10));
        CHECK_EQ(2, tree.size());

    }

    SUBCASE("setValueBeyondTail")
    {
        Btree<int> tree(10, 0);
        tree.setValue(10, 1, 1);

        INFO("tree: " << tree.to_string());
        INFO("tree size: " << tree.size());

        CHECK_EQ(0, tree.getValue(0));
        CHECK_EQ(0, tree.getValue(9));
        CHECK_EQ(std::optional<int>(0), tree.getValue(10));
    }
}
