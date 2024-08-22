#include "application.hpp"
#include "document.hpp"
#include "list_iterator.h"


Application::Application() {}
Application::~Application() 
{
    ListIterator<Document*> i(&_documents);
    for (i.first(); !i.is_done(); i.next())
        delete i.currentItem();
}


void Application::addDocument(Document* doc)
{
    _documents.append(new Document(*doc));
}


void Application::removeDocument(Document* doc)
{
    _documents.remove(doc);
}


Document* Application::getDocument(int index) const
{
    return _documents.get(index);
}

void Application::menu(BaseMenu* menu)
{
    _menu = menu;
}

BaseMenu* Application::menu()
{
    return _menu;
}
