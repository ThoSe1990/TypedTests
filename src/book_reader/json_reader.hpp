#ifndef JSON_READER_HPP
#define JSON_READER_HPP

#include "book_reader/book_reader.hpp"

#define BOOST_BIND_GLOBAL_PLACEHOLDERS

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>


#include <iostream> 

class json_book_reader : public book_reader {
private:
    boost::property_tree::ptree pt;
public: 
    json_book_reader() = delete;
    json_book_reader(const json_book_reader&) = default;
    json_book_reader(json_book_reader&&) = default;
    json_book_reader& operator=(const json_book_reader&) = default;
    json_book_reader& operator=(json_book_reader&&) = default;

    json_book_reader(const std::string& file) {
        boost::property_tree::read_json(file, pt);
    }

    void add_books() override {
        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("books")) {

            auto id = v.second.get_child("id").get_value<std::size_t>();

            books[id] = Book{
                v.second.get_child("author").get_value<std::string>(),
                v.second.get_child("title").get_value<std::string>(),
                v.second.get_child("published").get_value<int>()
            };      
        }
    }

};



#endif 