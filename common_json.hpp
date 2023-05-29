#pragma once

#include <iostream>

#include "nlohmann/json.hpp"

#define JSON_TRY_START  try {
#define JSON_TRY_END    }\
        catch(nlohmann::detail::exception& e){ std::cout << e.what() << std::endl; } \
        catch(std::exception& e){ std::cout << e.what() << std::endl; } \
        catch(...){ std::cout << "unknow exception!" << std::endl; }

#define COMMON_JSON_API  inline

using Json = nlohmann::json;

namespace common
{
    namespace json
    {
        COMMON_JSON_API bool parse(const std::string& str, Json& value)
        {
            JSON_TRY_START
                value = Json::parse(str);
                return true;
            JSON_TRY_END
            return false;
        }

        COMMON_JSON_API std::string dump(const Json& value)
        {
            return value.dump();
        }

        COMMON_JSON_API std::string dump_fmt(const Json& value, int space)
        {
            return value.dump(space);
        }

        COMMON_JSON_API bool to_bool(const Json& value)
        {
            bool r = false;
            if(value.is_boolean())
                r = value.get<bool>();
            else if(value.is_string())
                r = std::atoi(value.get<std::string>().c_str()) ? true : false;
            else if(value.is_number())
                r = value.get<uint32_t>() ? true : false;
            return r;
        }

        COMMON_JSON_API int32_t to_int32(const Json& value)
        {
            int32_t r = 0;
            if(value.is_boolean())
                r = value.get<bool>() ? 1 : 0;
            else if(value.is_string())
                r = std::atoi(value.get<std::string>().c_str());
            else if(value.is_number())
                r = value.get<int32_t>();
            return r;
        }

        COMMON_JSON_API uint32_t to_uint32(const Json& value)
        {
            uint32_t r = 0;
            if(value.is_boolean())
                r = value.get<bool>() ? 1 : 0;
            else if(value.is_string())
                r = std::atoi(value.get<std::string>().c_str());
            else if(value.is_number())
                r = value.get<uint32_t>();
            return r;
        }
        
        COMMON_JSON_API float to_float(const Json& value)
        {
            float r = 0;
            if(value.is_boolean())
                r = value.get<bool>() ? 1 : 0;
            else if(value.is_string())
                r = std::atof(value.get<std::string>().c_str());
            else if(value.is_number())
                r = value.get<float>();
            return r;
        }

        COMMON_JSON_API std::string to_string(const Json& value)
        {
            std::string r = "";
            if(value.is_string())
                r = value.get<std::string>();
            return r;
        }

    }
}


