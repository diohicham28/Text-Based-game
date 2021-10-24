#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED
#include<stdexcept>

/**
 * Exception for an attempt to divide by zero
  */
class div_by_zero_error : public std::runtime_error {
 public:
  /**
   * @param errMessage An error message.
   */
  div_by_zero_error(const char* errMessage) :
    std :: runtime_error(errMessage) {
  }
};

/**
 * If the world attempts to find an item that is not there,
 * an exception is thrown.
  */
class item_not_found_error : public std::runtime_error {
 public:
  /**
   * @param errMessage An error message.
   */
  item_not_found_error(const char* errMessage) :
    std :: runtime_error(errMessage) {
  }
};

/**
 * Exception for out-of-bounds access for the map
  */
class item_not_found_error : public std::runtime_error {
 public:
  /**
   * @param errMessage An error message.
   */
  item_not_found_error(const char* errMessage) :
    std :: runtime_error(errMessage) {
  }
};


#endif // EXEPTIONS_H_INCLUDED
