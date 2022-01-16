#ifndef XML_READER_HPP
#define XML_READER_HPP

#include "book_reader/book_reader.hpp"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <iostream> 

class xml_book_reader : public book_reader {
private:
    boost::property_tree::ptree pt;
public: 
    xml_book_reader() = delete;
    xml_book_reader(const xml_book_reader&) = default;
    xml_book_reader(xml_book_reader&&) = default;
    xml_book_reader& operator=(const xml_book_reader&) = default;
    xml_book_reader& operator=(xml_book_reader&&) = default;

    xml_book_reader(const std::string& file) {
        boost::property_tree::read_xml(file, pt);
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