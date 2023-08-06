// Copyright [2023] Daniel Olen
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <boost/date_time/posix_time/posix_time.hpp>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log_file>" << std::endl;
        return 1;
    }

    std::ifstream log_file(argv[1]);
    if (!log_file) {
        std::cerr << "Error opening log file: " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream output_file(std::string(argv[1]) + ".rpt");
    if (!output_file) {
        std::cerr << "Error creating output file: "
         << argv[1] << ".rpt" << std::endl;
        return 1;
    }

    std::string line;
    std::regex timestamp_pattern(R"((\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}))");
    std::regex boot_start_pattern(R"(\((log\.c\.166)\) server started)");
    std::regex boot_complete_pattern(R"(oejs\.AbstractConnector:Started SelectChannelConnector@\d+\.\d+\.\d+\.\d+:\d+)");

    boost::posix_time::ptime boot_start_time, boot_complete_time;
    bool boot_started = false;
    int line_number = 0;

    output_file << "=== Device boot ===" << std::endl;

    while (std::getline(log_file, line)) {
        line_number++;

        std::smatch match;
        if (std::regex_search(line, match, timestamp_pattern)
         && match.size() > 1) {
            std::string timestamp_str = match[1];
            boost::posix_time::ptime current_time =
             boost::posix_time::time_from_string(timestamp_str);

            if (std::regex_search(line, match, boot_start_pattern)) {
                if (boot_started) {
                    output_file << line_number << " (" << argv[1] << "): " <<
                     boot_start_time << " Boot Start" << std::endl;
                }
                boot_start_time = current_time;
                boot_started = true;
            } else if (std::regex_search(line, match, boot_complete_pattern)) {
                if (boot_started) {
                    boot_complete_time = current_time;
                    boost::posix_time::time_duration elapsed =
                     boot_complete_time - boot_start_time;
                    output_file << line_number << " (" << argv[1] << "): " <<
                     boot_start_time << " Boot Start" << std::endl;
                    output_file << line_number << " (" << argv[1] << "): " <<
                     boot_complete_time << " Boot Completed" << std::endl;
                    output_file << "Boot Time: " <<
                     elapsed.total_milliseconds() << "ms" << std::endl;
                    boot_started = false;
                }
            }
        }
    }

    if (boot_started) {
        output_file << line_number << " (" << argv[1] << "): " <<
         boot_start_time << " Boot Start" << std::endl;
    }

    log_file.close();
    output_file.close();
    return 0;
}
