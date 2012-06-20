/**
 * libextc metamacros testcase
 * ExtendedC
 *
 * by Justin Spahr-Summers
 *
 * Released 18. Jun 2012 into the public domain.
 */

#include "metamacros.h"
#include "metamacros_test.h"

#define test_stringify(INDEX, VALUE) \
    # INDEX metamacro_stringify(VALUE)

#define test_stringify_cxt(INDEX, CONTEXT, VALUE) \
    # INDEX CONTEXT metamacro_stringify(VALUE)

void metamacros_test (void) {
    assert(metamacro_argcount(x) == 1);
    assert(metamacro_argcount(x, x) == 2);
    assert(metamacro_argcount(x, x, x) == 3);
    assert(metamacro_argcount(x, x, x, x) == 4);
    assert(metamacro_argcount(x, x, x, x, x) == 5);
    assert(metamacro_argcount(x, x, x, x, x, x) == 6);
    assert(metamacro_argcount(x, x, x, x, x, x, x) == 7);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x) == 8);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x) == 9);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x) == 10);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x) == 11);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x) == 12);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x) == 13);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 14);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 15);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 16);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 17);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 18);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 19);
    assert(metamacro_argcount(x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x) == 20);

    assert(0 == strcmp(metamacro_foreach(test_stringify, 0), "00"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1), "0011"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2), "001122"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3), "00112233"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4), "0011223344"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5), "001122334455"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5, 6), "00112233445566"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5, 6, 7), "0011223344556677"));
    assert(0 == strcmp(metamacro_foreach(test_stringify, 0, 1, 2, 3, 4, 5, 6, 7, 8), "001122334455667788"));

    assert(0 == strcmp(metamacro_foreach_cxt(test_stringify_cxt, ".", "foo", 0), "0foo0"));
    assert(0 == strcmp(metamacro_foreach_cxt(test_stringify_cxt, ".", "foo", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19),
        "0foo0.1foo1.2foo2.3foo3.4foo4.5foo5.6foo6.7foo7.8foo8.9foo9.10foo10.11foo11.12foo12.13foo13.14foo14.15foo15.16foo16.17foo17.18foo18.19foo19"));

    assert(metamacro_first(5, 1) == 5);
    assert(metamacro_first(1, 5) == 1);
    assert(0 == strcmp(metamacro_first("foo", "bar"), "foo"));
}
