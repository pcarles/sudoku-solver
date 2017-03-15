#include <Python.h>
#include "header.h"

static	PyObject* py_solve(PyObject* self, PyObject* args)
{
	const char *numbers;
	if(!PyArg_ParseTuple(args, "s", &numbers))
		return NULL;

	int **grid;
	grid = ft_init_grid(9);
	ft_pyset_grid(grid, numbers);
	PyObject *res = PyList_New(9);
	for(int i = 0; i < 9; i++)
	{
		PyObject *ligne = PyList_New(9);
		for(int j = 0; j < 9; j++)
		{
			PyList_SET_ITEM(ligne, j, Py_BuildValue("i", grid[i][j]));
		}
		PyList_SET_ITEM(res, i, ligne);
	}
	ft_free_grid(grid, 9);
	return res;
}

static	PyMethodDef SolverMethods[] = {
	{"ft_solve", py_solve, METH_VARARGS, "Solve"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef solvermodule = {
	PyModuleDef_HEAD_INIT,
	"wrap_python",
	NULL,
	-1,
	SolverMethods
};

PyMODINIT_FUNC PyInit_solvermodule(void)
{
	return PyModule_Create(&solvermodule);
}

