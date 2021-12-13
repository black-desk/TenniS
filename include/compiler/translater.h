//
// Created by kier on 2018/11/1.
//

#ifndef TENSORSTACK_COMPILER_TRANSLATER_H
#define TENSORSTACK_COMPILER_TRANSLATER_H

#include <core/device.h>

#include "module/module.h"

namespace ts
{
  class TranslatorOption;
  /**
   * translate Graph to TGraph
   * translate Graph from other framework to TS support Graph
   */
  class TS_DEBUG_API Translator {
    public:
      using self = Translator;

      Translator(const Translator &) = delete;

      Translator &operator=(const Translator &) = delete;

      ~Translator();

      explicit Translator(const ComputingDevice &device);

      explicit Translator(
        const ComputingDevice &device, const std::string &params);

      Module::shared translate(const Module::shared &module) const;
    private:
      ComputingDevice                       m_device;
      std::vector<const TranslatorOption *> m_options;
      std::string                           m_params;
  };
}  // namespace ts

#endif  // TENSORSTACK_COMPILER_TRANSLATER_H
