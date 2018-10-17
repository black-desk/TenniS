//
// Created by seeta on 2018/6/29.
//

#include "global/operator_factory.h"

namespace ts {
    using Name = std::pair<DeviceType, std::string>;
    static std::map<Name, OperatorCreator> &MapNameCreator() {
        static std::map<Name, OperatorCreator> map_name_creator;
        return map_name_creator;
    };

    OperatorCreator QueryOperatorCreator(const DeviceType &device_type, const std::string &operator_name) TS_NOEXCEPT {
        auto &map_name_creator = MapNameCreator();
        Name device_operator_name = std::make_pair(device_type, operator_name);
        auto name_creator = map_name_creator.find(device_operator_name);
        if (name_creator != map_name_creator.end()) {
            return name_creator->second;
        }
        return OperatorCreator(nullptr);
    }

    void
    RegisterOperatorCreator(const DeviceType &device_type, const std::string &operator_name, const OperatorCreator &operator_creator) TS_NOEXCEPT {
        auto &map_name_creator = MapNameCreator();
        Name device_operator_name = std::make_pair(device_type, operator_name);
        map_name_creator.insert(std::make_pair(device_operator_name, operator_creator));
    }

    void ClearRegisteredOperatorCreator() {
        auto &map_name_creator = MapNameCreator();
        map_name_creator.clear();
    }
}
