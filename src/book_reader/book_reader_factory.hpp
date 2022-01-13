#ifndef BOOK_READER_FACTORY_HPP
#define BOOK_READER_FACTORY_HPP

#include <filesystem>
#include <memory>

#include "book_reader/book_reader.hpp"

#include "book_reader/xml_reader.hpp"
#include "book_reader/json_reader.hpp"

class book_reader_factory {
public:
    
    [[nodiscard]] static std::unique_ptr<book_reader> create(const std::string& configuration_file) {
        
        const auto extension = std::filesystem::path(configuration_file).extension();

        if (extension.compare(".xml") == 0) {
            return std::make_unique<xml_book_reader>(configuration_file);
        } else if (extension.compare(".json") == 0) {
            return std::make_unique<json_book_reader>(configuration_file);
        }

        throw std::runtime_error("invalid configuration file given");
    }
};


#endif