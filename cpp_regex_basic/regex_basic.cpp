/**
 * Regex matching wrappers here
 */

#include <regex>

bool match(std::string data, std::string ex) {
    std::regex e(ex);

    return std::regex_match(data, e);
}
