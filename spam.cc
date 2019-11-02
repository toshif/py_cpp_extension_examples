// https://docs.python.org/3/extending/extending.html#

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <iostream>

using namespace std;

int a = 0;

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
  cout << "calling spam_system in c++ ..." << endl;
  a++;
  cout << "a=" << a << endl;

  const char *command;
  int sts;

  if (!PyArg_ParseTuple(args, "s", &command))
    return NULL;
  sts = system(command);
  return PyLong_FromLong(sts);
}

static PyMethodDef SpamMethods[] = {
    {"system", spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam", /* name of module */
    NULL,   /* module documentation, may be NULL */
    -1,     /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    SpamMethods};

PyMODINIT_FUNC
PyInit_spam(void)
{
  return PyModule_Create(&spammodule);
}
