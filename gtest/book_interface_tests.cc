

#include <gtest/gtest.h>

#include "book_test_variables.hpp"

#include "book_reader/book_reader_factory.hpp"

class book_reader_interface_tests : public testing::TestWithParam<std::string> {
protected:
    void SetUp() override {    
        const auto current_file = GetParam();
        this->books = book_reader_factory::create(current_file);
        this->books->add_books();
    }
    void TearDown() override {
        this->books.reset();
    }

public:
    std::unique_ptr<book_reader> books;
};

INSTANTIATE_TEST_SUITE_P(
        book_reader_interface_tests,
        book_reader_interface_tests,
        ::testing::Values(
            book_tests::xml_file,
            book_tests::json_file
        )
);

TEST_P(book_reader_interface_tests, read_buzz_michelangelo) {
    auto buzz_from_configuration = this->books->get_book(book_tests::buzz.id);
    EXPECT_TRUE(buzz_from_configuration == book_tests::buzz.book);
}

TEST_P(book_reader_interface_tests, read_moxie_crimefighter) {
    auto moxie_from_configuration = this->books->get_book(book_tests::moxie.id);
    EXPECT_TRUE(moxie_from_configuration == book_tests::moxie.book);
}