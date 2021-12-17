//
// Created by kier on 2018/11/5.
//

#include "utils/log.h"

#include <atomic>

#include "utils/static.h"

namespace ts
{
  static std::atomic<LogLevel> InnerGlobalLogLevel;

  LogLevel GlobalLogLevel(LogLevel level) {
    LogLevel pre_level  = InnerGlobalLogLevel;
    InnerGlobalLogLevel = level;
    return pre_level;
  }

  LogLevel GlobalLogLevel() { return InnerGlobalLogLevel; }
}  // namespace ts

TS_STATIC_ACTION(
  (ts::LogLevel(*)(ts::LogLevel))ts::GlobalLogLevel, ts::LOG_INFO)
