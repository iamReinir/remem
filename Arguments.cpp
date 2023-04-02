#include"Arguments.h"
namespace Arguments {

	Type type_of(int argc, char* argv[])
	{
		if (argc == 1) return Type::none;
		std::string arg1(argv[1]);
		if (arg1 == "add") return Type::add_schedule;
		if (arg1 == "note") return Type::add_note;
		if (arg1 == "done") return Type::done;
		if (arg1 == "diary") return Type::add_diary;
		if (arg1 == "setting") return Type::setting;
		if (arg1 == "show")
		{
			if (argc < 3)
				return Type::none;
			std::string arg2(argv[2]);
			if (arg2 == "schedule")
				return Type::show_schedule;
			if (arg2 == "note")
				return Type::show_note;
			if (arg2 == "diary")
				return Type::show_diary;
		}
		return Type::invalid;
	}

	void open_config_file()
	{
		std::filesystem::create_directory(default_save_path);
	}

}