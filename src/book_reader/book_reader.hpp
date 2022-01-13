#ifndef BOOK_READER_HPP
#define BOOK_READER_HPP

#include <string>

struct Book {
    std::string author;
    std::string title;
    int published;

    bool operator==(const Book& rhs) {
        return  this->author.compare(rhs.author) == 0 &&
                this->title.compare(rhs.title) == 0 &&
                this->published == rhs.published;
    }
};


#include<unordered_map>

class book_reader {
protected:
    std::unordered_map<std::size_t, Book> books;

public: 
    book_reader() = default;
    book_reader(const book_reader&) = default;
    book_reader(book_reader&&) = default;
    book_reader& operator=(const book_reader&) = default;
    book_reader& operator=(book_reader&&) = default;
    virtual ~book_reader() = default;

    virtual void add_books() = 0;

    [[nodiscard]] Book get_book(const std::size_t id) const {
        return books.at(id);
    } 

    [[nodiscard]] auto get_books_map() {
        return books;
    }
};



#endif 