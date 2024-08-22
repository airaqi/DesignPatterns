#include "application.hpp"
#include "application_menu.hpp"
#include "application_menu_item.hpp"
#include "command_macro.hpp"
#include "command_open.hpp"
#include "command_paste.hpp"
#include "command_receiver.hpp"
#include "command_simple.hpp"
#include "document.hpp"
#include <cstring>

int main(int argc, char *argv[])
{
    Application app;
    Document doc1("test");
    //Document doc2("test2");

    CommandOpen open_test(&app);
    open_test.execute();

    Document* doc2 = app.getDocument(0);

    CommandPaste paste1(&doc1);
    CommandPaste paste2(doc2);
    CommandReceiver receiver;
    CommandSimple<CommandReceiver> simplecmd(&receiver, &CommandReceiver::action);
    
    CommandMacro cmds;

    cmds.add(&simplecmd);
    cmds.add(&paste1);
    cmds.add(&paste2);

    //cmds.execute();

    Menu menu("File");
    MenuItem openItem("Open", &open_test);
    MenuItem receiverItem("Receiver", &cmds);
    menu.add(&openItem);
    menu.add(&receiverItem);

    app.menu(&menu);

    app.menu()->display();

    openItem.clicked();
    receiverItem.clicked();


    return 0;
}
