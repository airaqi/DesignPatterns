#include "application.hpp"


Application::Application() {}
Application::~Application() {}


void Application::addDocument(Document* doc)
{
    _documents.append(doc);
}


void Application::removeDocument(Document* doc)
{
    _documents.remove(doc);
}
