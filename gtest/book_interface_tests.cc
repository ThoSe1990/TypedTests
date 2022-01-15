

#include <gtest/gtest.h>

#include "book_test_variables.hpp"
#include "book_reader/book_reader.hpp"
#include "book_reader/xml_reader.hpp"
#include "book_reader/json_reader.hpp"

class book_reader_interface_tests : public testing::TestWithParam<book_reader> {
protected:
    void SetUp() override {    
        this->books = GetParam();
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
            std::make_unique<xml_reader>(book_tests::xml_file),
            std::make_unique<json_reader>(book_tests::json_file)
        )
);

TEST_P(book_reader_interface_tests, verify_books) {

    const auto books_container = this->books->get_books();

    for (const auto& expected : book_tests::expected_books) {
        
        const auto found = books_container.find(expected.first);

        std::cout << "expected book: " << expected.second.author << '\n';
        std::cout << "found book: " << found->second.author << "\n\n";

        EXPECT_EQ(expected.first, found->first);
        EXPECT_EQ(expected.second, found->second);       
    }
}
