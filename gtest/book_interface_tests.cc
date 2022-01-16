

#include <gtest/gtest.h>

#include "book_test_variables.hpp"

#include "book_reader/xml_reader.hpp"
#include "book_reader/json_reader.hpp"



template <class T>
std::unique_ptr<book_reader> create_book_reader();

template <>
std::unique_ptr<book_reader> create_book_reader<xml_book_reader>() {
  return std::make_unique<xml_book_reader>(book_tests::xml_file);
}
template <>
std::unique_ptr<book_reader> create_book_reader<json_book_reader>() {
  return std::make_unique<json_book_reader>(book_tests::json_file);
}


template <class T>
class book_reader_tests : public testing::Test {
protected:
    book_reader_tests() : books(create_book_reader<T>()) {}

    void SetUp() override {
        books->add_books();
    }

    void TearDown() override {
        books.reset();
    }

    std::unique_ptr<book_reader> books;
};

using testing::Types;

typedef Types<xml_book_reader, json_book_reader> Implementations;

TYPED_TEST_SUITE(book_reader_tests, Implementations);




TYPED_TEST(book_reader_tests, find_all_books) {
    const auto books_container = this->books->get_books();

    for (const auto& expected : book_tests::expected_books) {
        
        const auto found = books_container.find(expected.first);

        std::cout << "expected book: " << expected.second.author << '\n';
        std::cout << "found book: " << found->second.author << "\n\n";

        EXPECT_EQ(expected.first, found->first);
        EXPECT_EQ(expected.second, found->second);       
    }
}
