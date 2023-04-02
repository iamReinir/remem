#pragma once
#include <string>
#include <filesystem>
namespace Arguments
{
    const std::string default_save_path{"../test"};
    enum class Type
    {
        show_schedule,
        show_note,
        show_diary,
        add_schedule,
        add_note,
        add_diary,
        done,
        setting,
        none,
        invalid
    };
    Type type_of(int argc, char* argv[]);
    void open_config_file();
}