


#include "book_reader/book_reader_factory.hpp"

int main () 
{

    auto xml = book_reader_factory::create("/media/sf_sf_ubuntu/DontMarryFrameworks/gtest/examples/example.xml");
    xml->add_books();

    auto b1 = xml->get_book(123456);

    std::cout << b1.author << "\n";
    std::cout << b1.title << "\n";
    std::cout << b1.published << "\n";

    auto json = book_reader_factory::create("/media/sf_sf_ubuntu/DontMarryFrameworks/gtest/examples/example.json");
    json->add_books();

    auto b2 = json->get_book(456789);

    std::cout << b2.author << "\n";
    std::cout << b2.title << "\n";
    std::cout << b2.published << "\n";

    return 0;
}