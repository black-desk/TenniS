//
// Created by kier on 2018/12/3.
//

#ifndef TENSORSTACK_MODULE_HEADER_H
#define TENSORSTACK_MODULE_HEADER_H

#include <array>
#include <cstdint>

#include "serialization.h"

#define TS_MODULE_CODE_V1 0x19910929

namespace ts
{
  class TS_DEBUG_API Header : public Serializable {
    public:
      using data_type = std::array<char, 120>;

      uint32_t  fake = 0;
      uint32_t  code = 0;
      data_type data = data_type({
        0,
      });

      size_t serialize(StreamWriter &stream) const final;

      size_t externalize(StreamReader &stream) final;
  };
}  // namespace ts

#endif  // TENSORSTACK_MODULE_HEADER_H
