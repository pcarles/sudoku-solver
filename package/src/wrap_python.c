#include <Python.h>
#include "header.h"

static	PyObject* py_check(PyObject* self, PyObject* args)
{
	char *numbers;
	if(!PyArg_ParseTuple(args, "s", &numbers))
		return NULL;

	if(ft_check_str(numbers))
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

static	PyObject* py_solve(PyObject* self, PyObject* args)
{
	char *numbers;
	int **grid, i, j;
	PyObject *res = PyList_New(9);

	if(!PyArg_ParseTuple(args, "s", &numbers))
		return NULL;

	grid = ft_init_grid(9);
	ft_set_grid(grid, numbers);

	if(!ft_check_grid(grid))
		Py_RETURN_FALSE;

	ft_solve(grid, 0);

	for(i = 0; i < 9; i++)
	{
		PyObject *line = PyList_New(9);
		for(j = 0; j < 9; j++)
		{
			PyList_SET_ITEM(line, j, Py_BuildValue("i", grid[i][j]));
		}
		PyList_SET_ITEM(res, i, line);
	}
	ft_free_grid(grid, 9);
	return res;
}

static	PyMethodDef SolverMethods[] = {
	{"ft_solve", py_solve, METH_VARARGS, "Solve"},
	{"ft_check", py_check, METH_VARARGS, "Check"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef solvermodule = {
	PyModuleDef_HEAD_INIT,
	"solvermodule",
	NULL,
	-1,
	SolverMethods
};

PyMODINIT_FUNC PyInit_solvermodule(void)
{
	return PyModule_Create(&solvermodule);
}
