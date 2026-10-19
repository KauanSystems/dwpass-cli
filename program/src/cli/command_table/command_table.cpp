# include <iostream>
# include <string_view>
# include <algorithm>
# include <array>
# include <vector>
# include <string>
#include <filesystem>

#include "command_table.h"
#include "program.h"

#include "command.h"
#include "logic.h"

namespace Command_table {

    void Usage() {
            std::cerr
            << "\nUsage: "
            << NAME
            << " <command>\n\n"
            << "For Command Help Table Use: "
            << NAME
            << " --help or -h.\n\n";
    } // Usage();

    using command_func = int(*)(int argc, char* argv[]);

    struct CommandMapping {
        std::string_view name;
        command_func function;
    };

    namespace {
        std::filesystem::path file = WORD;
        std::filesystem::path file_patch;
        int num;
        std::vector<std::string> resultados;
        
        bool VerifyFile(const std::filesystem::path& export_dir, const std::filesystem::path& file_pat) {
			bool file_exists =
				std::filesystem::exists(FILE_NAME) ||
				(!export_dir.empty() && std::filesystem::exists(file_pat));

			if (!file_exists) {
				return true;
			}

			std::string response;

			std::cout
				<< "\n[Warning]"
				<< "\nThe File "
				<< FILE_NAME
				<< " already exists. Do you want to delete it? (Y/n): ";

			std::getline(std::cin, response);

			if (response.empty()) {
				response = "y";
			}

			std::transform(
				response.begin(),
				response.end(),
				response.begin(),
				[](unsigned char c) {
				    return static_cast<char>(std::tolower(c));
				}
			);

			if (response == "y" || response == "yes") {
				std::cout
				    << "\n[Last Chance]\n"
				    << "This action is IRREVERSIBLE."
				    << " Do you wish to continue? (Y/n): ";

				std::getline(std::cin, response);

				if (response.empty()) {
				    response = "y";
				}

				std::transform(
				    response.begin(),
				    response.end(),
				    response.begin(),
				    [](unsigned char c) {
				        return static_cast<char>(std::tolower(c));
				    }
				);

				if (response == "y" || response == "yes") {
				    if (std::filesystem::exists(FILE_NAME)) {
				        std::filesystem::remove(FILE_NAME);
				    }

				    if (!export_dir.empty() && std::filesystem::exists(file_pat)) {
				        std::filesystem::remove(file_pat);
				    }
				    return true;
				}
				else {
				    std::cout << "\nOperation cancelled.\n\n";
				    return false;
				}
			}
			else {
				std::cout << "\nOperation cancelled.\n\n";
				return false;
			}
		} // VerifyFile().

        int DoError(int argc, char* argv[]){
            std::cerr << "\nError: Has Been Generated.\n\n";
            return 1;
        } // DoError().

        int DoHelp(int argc, char* argv[]) {
            Command::Help_Table();
            return 0;
        } // DoHelp().

        int DoVersion(int argc, char* argv[]) {
            Command::Version();
            return 0;
        } // DoVersion().

		int DoGen(int argc, char* argv[]) {
			bool generate = false;
			bool export_file = false;
			int max_iter = 5;
			std::filesystem::path file_m;

			for (int i = 1; i < argc; ++i) {
				std::string arg = argv[i];

				if (arg == "-g" || arg == "generate") {
				    generate = true;
				}
				else if (arg == "-e" || arg == "export") {
				    export_file = true;
				}
				else {
				    try {
				        size_t pos = 0;
				        int value = std::stoi(arg, &pos);

				        if (pos == arg.size()) {
				            max_iter = value;
				        }
				        else {
				            file_m = arg;
				        }
				    }
				    catch (...) {
				        file_m = arg;
				    }
				}
			}

			if (!generate) {
				return 0;
			}

			if (max_iter <= 0) {
				std::cerr << "\n[Error] Number of iterations must be greater than 0.\n\n";
				return 1;
			}
			
			if (max_iter <= 4) {
				std::cerr << "\n[Error] The number of iterations must not be less than 5.\n\n";
				return 1;
			}

			std::filesystem::path dir(file_m);

			std::filesystem::path file_pat =
				dir.empty()
				    ? std::filesystem::path(FILE_NAME)
				    : dir / FILE_NAME;

			if (export_file) {
				if (!VerifyFile(file_m, file_pat)) {
				    return 0;
				}
			}

			std::cout << "\n\n";
			for (int i = 1; i <= max_iter; ++i) {
				auto num = Logic::Generate_data();

				auto resultados = Logic::Compare(file, num);

				for (const std::string& res : resultados) {
				    std::cout
				        << num
				        << " -> "
				        << res
				        << "\n";
				}

				if (export_file) {
				    for (const std::string& res : resultados) {
				        Command::Export(res, file_m.string());
				    }
				}
			} std::cout << "\n\n";

			return 0;
		} // DoGen().

        int DoLogo(int argc, char* argv[]) {
            Command::Logo();
            return 0;
        } // DoLogo().

        int DoImport(int argc, char* argv[]) {
			bool word_mode = false;
			bool export_file = false;
			int max_iter = 5;
			std::filesystem::path file_path;
			std::filesystem::path export_dir;

			for (int i = 1; i < argc; ++i) {
				std::string arg = argv[i];

				if (arg == "-w" || arg == "word") {
				    word_mode = true;
				    if (i + 1 < argc && argv[i + 1][0] != '-') {
				        file_path = argv[i + 1];
				        i++;
				    }
				}
				else if (arg == "-e" || arg == "export") {
				    export_file = true;
				    if (i + 1 < argc && argv[i + 1][0] != '-') {
				        std::filesystem::path export_path = argv[i + 1];
				        if (std::filesystem::exists(export_path)) {
				            export_dir = export_path;
				        } else {
				            std::cout << "The export path does not exist.\n";
				            return 0;
				        }
				        i++;
				    }
				}
				else {
				    try {
				        size_t pos = 0;
				        int value = std::stoi(arg, &pos);

				        if (pos == arg.size()) {
				            max_iter = value;
				        }
				        else {
				            if (file_path.empty()) {
				                file_path = arg;
				            }
				        }
				    }
				    catch (...) {
				        if (file_path.empty()) {
				            file_path = arg;
				        }
				    }
				}
			}

			if (!word_mode) {
				Usage();
				return 0;
			}

			if (max_iter <= 0) {
				std::cerr << "\n[Error] Number of iterations must be greater than 0.\n\n";
				return 1;
			}
			
			if (max_iter <= 4) {
				std::cerr << "\n[Error] The number of iterations must not be less than 5.\n\n";
				return 1;
			}

			if (file_path.empty() || !std::filesystem::exists(file_path)) {
				std::cout << "The File not exists.\n";
				return 0;
			}
			
			// Condition.
			std::ifstream file(file_path);
			if (!file.is_open()) {
				std::cerr << "\n[Error] Unable to open the file.\n\n";
				return 0;
			}

			int line_count = 0;
			std::string line;
			while (std::getline(file, line)) {
				++line_count;
			}

			file.close();

			if (line_count != 7776) {
				std::cerr << "\n[Error] The file must contain exactly 7776 lines.\n\n";
				return 0;
			}
			// End.

			std::filesystem::path dir(export_dir);
			std::filesystem::path file_pat =
				dir.empty()
				    ? std::filesystem::path(FILE_NAME)
				    : dir / FILE_NAME;

			if (!VerifyFile(export_dir, file_pat)) {
				return 0;
			}
			
			std::cout << "\n\n";
			int num;
			std::vector<std::string> resultados;

			for (int i = 1; i <= max_iter; ++i) {
				num = Logic::Generate_data();
				resultados = Logic::Compare(file_path.string(), num);

				for (const std::string& res : resultados) {
				    std::cout << num
				              << " -> "
				              << res
				              << "\n";
				}

				if (export_file) {
				    for (const std::string& res : resultados) {
				        Command::Export(res, export_dir.string());
				    }
				}
			}
			std::cout << "\n\n";

			return 0;
		} // DoImport().

        int DoInput(int argc, char* argv[]) {
			bool input_mode = false;
			bool export_file = false;
			int max_iter = 5;
			std::filesystem::path export_dir;
			std::filesystem::path file_path;

			for (int i = 1; i < argc; ++i) {
				std::string arg = argv[i];

				if (arg == "-i" || arg == "input") {
				    input_mode = true;
				    if (i + 1 < argc && argv[i + 1][0] != '-') {
				        try {
				            size_t pos = 0;
				            int value = std::stoi(argv[i + 1], &pos);
				            if (pos == std::string(argv[i + 1]).size()) {
				                max_iter = value;
				                i++;
				            }
				        }
				        catch (...) {}
				    }
				}
				else if (arg == "-e" || arg == "export") {
				    export_file = true;
				    if (i + 1 < argc && argv[i + 1][0] != '-') {
				        std::filesystem::path export_path = argv[i + 1];
				        if (std::filesystem::exists(export_path)) {
				            export_dir = export_path;
				        } else {
				            std::cout << "The export path does not exist.\n";
				            return 0;
				        }
				        i++;
				    }
				}
				else if (arg == "-w" || arg == "word") {
				    if (i + 1 < argc && argv[i + 1][0] != '-') {
				        file_path = argv[i + 1];
				        i++;
				    }
				}
				else {
				    try {
				        size_t pos = 0;
				        int value = std::stoi(arg, &pos);
				        if (pos == arg.size()) {
				            max_iter = value;
				        }
				        else {
				            if (file_path.empty()) {
				                file_path = arg;
				            }
				        }
				    }
				    catch (...) {
				        if (file_path.empty()) {
				            file_path = arg;
				        }
				    }
				}
			}

			if (!input_mode) {
				return 0;
			}

			if (max_iter <= 0) {
				std::cerr << "\n[Error] Number of iterations must be greater than 0.\n\n";
				return 1;
			}
			
			if (max_iter <= 4) {
				std::cerr << "\n[Error] The number of iterations must not be less than 5.\n\n";
				return 1;
			}

			if (file_path.empty()) {
				file_path = FILE_NAME;
			}

			if (!std::filesystem::exists(file_path)) {
				std::cout << "The File not exists.\n";
				return 0;
			}
			
			// Condition.
			std::ifstream file(file_path);
			if (!file.is_open()) {
				std::cerr << "\n[Error] Unable to open the file.\n\n";
				return 0;
			}

			int line_count = 0;
			std::string line;
			while (std::getline(file, line)) {
				++line_count;
			}

			file.close();

			if (line_count != 7776) {
				std::cerr << "\n[Error] The file must contain exactly 7776 lines.\n\n";
				return 0;
			}
			// End.

			std::filesystem::path file_pat =
				export_dir.empty()
				    ? std::filesystem::path(FILE_NAME)
				    : export_dir / FILE_NAME;

			if (export_file) {
				if (!VerifyFile(export_dir, file_pat)) {
				    return 0;
				}
			}

			std::vector<int> dice_code(max_iter);

			std::cout << "\n\n";
			for (int i = 0; i < max_iter; i++) {
				bool valid_input = false;
				
				while (!valid_input) {
					std::cout << "Enter With The Dice Number [" << (i + 1) << "]: ";
					
					if (!(std::cin >> dice_code[i])) {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "Error: Invalid input! Please enter a valid number.\n";
						continue;
					}

					if (dice_code[i] < 10000 || dice_code[i] > 99999) {
						std::cout << "Error: The number must contain 5 digits!\n";
						
						std::string response;
						std::cout << "Do you want to insert it again (y/n)? ";
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::getline(std::cin, response);

						std::transform(
							response.begin(),
							response.end(),
							response.begin(),
							[](unsigned char c) {
								return static_cast<char>(std::tolower(c));
							}
						);              

						if (response.empty() || response == "y" || response == "yes") {
						} else if (response == "n" || response == "no") {
							std::cout << "\nOperation cancelled for this field.\n\n";
							return 0;
						}
					} else {
						valid_input = true;
					}
				}
			} std::cout << "\n\n";

			for (int i = 0; i < max_iter; i++) {
				auto resultados = Logic::Compare(file_path.string(), dice_code[i]);

				for (const std::string& res : resultados) {
				    std::cout << dice_code[i]
				              << " -> "
				              << res
				              << "\n";
				}

				if (export_file) {
				    for (const std::string& res : resultados) {
				        Command::Export(res, export_dir.string());
				    }
				}
			} std::cout << "\n\n";

			return 0;
		} // DoInput().

        int DoSystem(int argc, char* argv[]) {
            Command::System();
            return 0;
        } // DoSystem().

    } // Namespace.

    constexpr auto Command_Table = std::to_array<CommandMapping> ({
        {"--help", &DoHelp},
        {"--logo", &DoLogo},
        {"--system", &DoSystem},
        {"--version", &DoVersion},
        {"-e", &DoError},
        {"-g", &DoGen},
        {"-h", &DoHelp},
        {"-i", &DoInput},
        {"-l", &DoLogo},
        {"-s", &DoSystem},
        {"-v", &DoVersion},
        {"-w", &DoImport},
        {"export", &DoError},
        {"generate", &DoGen},
        {"import", &DoImport},
        {"input", &DoInput},
        {"word", &DoImport},
    }); // Command_Table.

} // Namespace Command_table.

int Run(int argc, char* argv[]) {

    if (argc < 2) {
        Command_table::Usage();
        return 1;
    }

    std::string_view CommandStr{ argv[1] };

    auto IT = std::lower_bound(Command_table::Command_Table.begin(), Command_table::Command_Table.end(), CommandStr,
        [](const Command_table::CommandMapping& Cmd, std::string_view Target) {
            return Cmd.name < Target;
        });

    if (IT != Command_table::Command_Table.end() && IT->name == CommandStr) {
        return IT->function(argc, argv);
    }

    std::cout << "\nUnknown command: " << CommandStr << "\n\n";
    return 1;
} // Run();
