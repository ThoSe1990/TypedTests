

#include <gtest/gtest.h>

#include "book_test_variables.hpp"
#include "book_reader/book_reader_factory.hpp"

class book_reader_interface_tests : public testing::TestWithParam<std::string> {
protected:
    void SetUp() override {    
        const auto current_file = GetParam();
        this->books = book_reader_factory::create(current_file);
        this->books->add_books();

        std::cout << "running test with: " << current_file << "\n\n";
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