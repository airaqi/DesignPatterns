#include "btree.hpp"
#include "btree_node.hpp"
#include "glyph_character.hpp"
#include "glyph_context.hpp"
#include "glyph_document.hpp"
#include "glyph_factory.hpp"
#include "window_console.hpp"
#include <cstdlib>
#include <iostream>
#include <random>

void node_test();
int btree_test();
int flyweightDocument();

int main(int argc, char* argv[])
{
    std::cout << "Hello, Prototype!\n";

    int ret = 0;

    // node_test();
    // ret = btree_test();
    ret = flyweightDocument();

    return ret;
}

int flyweightDocument()
{
    std::cout << "\n=== Flyweight Document Demo ===\n";

    GlyphFactory factory = GlyphFactory::get();

    std::string
        sample1 = "Hello, there!\nHave Fun!",
        sample2 = "This is a text to show glyphs flyweight characters and fonts ... \n\tFollowing the Flyweight Pattern.",
        documentText = sample2;

    std::cout << "Processing raw document input string stream ...\n";

    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0, max = 6;
    std::uniform_int_distribution<int> diste(min, max);

    Font::Ptr
        times12 = factory.getFont("Times New Roman", 12, Font::Color(static_cast<Font::Color::Value>(diste(gen))));

    GlyphContext ctxt(times12);
    GlyphDocument::Ptr doc = factory.getDocument();
    ConsoleWindow window;

    std::cout << "\n=== Context before ===\n";
    std::cout << ctxt.to_string() << "\n";

    GlyphCharacter::Ptr CR = factory.getCharacter('\n');

    std::cout << "\n=== Character Draw ===\n";

    for (int i = 0; i < documentText.length(); i++) {
        int minSz = 8, maxSz = 20, minCol = 0, maxCol = 6;
        int size = std::rand() % (maxSz - minSz + 1) + minSz;
        Font::Ptr randColor = factory.getFont("Times New Roman", size, Font::Color(static_cast<Font::Color::Value>(diste(gen))));
        char target = documentText.at(i);
        GlyphCharacter::Ptr c = factory.getCharacter(target);
        doc->insert(c, ctxt);

        if (c->equal(*CR)) {
            c->prev(ctxt);
            doc->setFont(randColor, 1, ctxt);
        }

        ctxt.prev();
        c->draw(window, ctxt);
        // std::cout << " ==> " << ctxt.to_string() << "\n";
    }

    std::cout << "\n\n=== Context After ===\n";
    std::cout << ctxt.to_string() << "\n";

    std::cout << "\n=== Draw Document ===\n";
    doc->draw(window, ctxt);

    std::cout << "\n\n=== Document structure ===\n";
    std::cout << doc->to_string("  ") << "\n";

    std::cout << "\n\n=== Flyweight Characters ===\n";
    std::cout << factory.printCharPool() << "\n";

    std::cout << "\n\n=== Flyweight Fonts ===\n";
    std::cout << factory.printFontPool() << "\n";

    return 0;
}

int btree_test()
{
    std::cout << "\n=== Btree Test ===\n";

    Btree<int> tree(0, 0);

    std::cout << "init: " << tree << "\n";

    tree.insert(0, 10);
    std::cout << "insert: " << tree << "\n";

    tree.setValue(3, 2, 1);
    std::cout << "setValue: \n"
              << tree.to_string("  ") << "\n";

    tree.setValue(5, 2, 2);
    std::cout << "setValue: \n"
              << tree.to_string("  ") << "\n";

    int query = 6;
    std::cout << "getValue(" << query << "): " << tree.getValue(query).value() << "\n";

    return 0;
}

void node_test()
{
    std::cout << "\n=== Node Test ===\n";
    Node<int>::Ptr root = Node<int>::create(0, 0);
    std::cout << "init: " << *root << "\n";

    root->insert(0, 10);
    std::cout << "insert: " << *root << "\n";

    root->setValue(3, 2, 1);
    std::cout << "setValue: \n"
              << root->to_string("  ") << "\n";

    root->setValue(5, 2, 2);
    std::cout << "setValue: \n"
              << root->to_string("  ") << "\n";

    std::cout << "getValue(6): " << root->getValue(6).value() << "\n";
}
