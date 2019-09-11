#ifndef RESULT_H
#define RESULT_H

#include <stdbool.h>

#define DEFINE_RESULT(Name, T, E) \
    typedef struct {              \
        bool success;             \
        union {                   \
            T value;              \
            E error;              \
        };                        \
    } Name;

// You might want to specialize this, e.g.:
// #define MYTYPE_OK(...) OK(MYTYPE, __VA_ARGS__)
#define OK(Name, ...) (Name){ .success = true, .value = __VA_ARGS__ }

// You might want to specialize this, e.g.:
// #define MYTYPE_ERR(err) ERR(MYTYPE, err)
#define ERR(Name, err) (Name){ .success = false, .error = err }

#define IS_OK(result) ((result).success)

#define IS_ERR(result) (!(result).success)

#define UNRWAP(result) ((result).value)

#define UNRWAP_ERR(result) ((result).error)

#endif  // RESULT_H
