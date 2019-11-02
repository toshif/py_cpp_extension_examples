// https://docs.python.org/3/extending/extending.html#

#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* c_helloworld(PyObject* self, PyObject* args) 
{
    printf("Hello World\n");
    return Py_None;
}
