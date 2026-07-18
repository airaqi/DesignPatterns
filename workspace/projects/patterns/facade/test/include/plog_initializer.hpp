#ifndef __PLOG_INITIALIZER_H__
#define __PLOG_INITIALIZER_H__ value

#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>
#include "plog/Appenders/ColorConsoleAppender.h"
#include "plog/Logger.h"

struct PlogTestIniitializer 
{
  PlogTestIniitializer() {
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    if (plog::get() == nullptr)
      plog::init(plog::debug, &consoleAppender);

  }
};

static PlogTestIniitializer global_logger;

#endif /* ifndef __PLOG_INITIALIZER_H__ */
