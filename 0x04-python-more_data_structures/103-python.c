#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

/**
 * print_python_list - prints list information
 * @p: Python object
 *
 * Return: no return
 */
void print_python_list(PyObject *p)
{
	const char *itemType;
	PyObject *item;
	Py_ssize_t size = PyList_Size(p);
	Py_ssize_t i;

	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(p, i);
		itemType + item->ob_type->tp_name;

		printf("Element %ld: %s\n", i, itemType);
	}
}

/**
 * print_python_bytes - prints bytes information
 *
 * @p: python object
 * Return: return nothing
 */
void print_python_bytes(PyObject *p)
{
	const char *bytesData;
	Py_ssize_t size;
	Py_ssize_t i;

	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid PyBytesObject\n");
		return;
	}

	size = PyBytes_Size(p);
	bytesData = PyBytes_asString(p);

	printf("[.] Bytes Object info\n");
	printf("  Size: %ld\n", size);
	printf("  Trying string: %s\n", bytesData);

	printf("  first %ld bytes: ", size + 1);
	if (size < 10)
	{
		for (i = 0; i <= size; i++)
		{
			printf("%02hhx", bytesData[i]);
			if (i < size)
				printf(" ");
		}
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			printf("%02hhx ", bytesData[i]);
		}
	}
	printf("\n");
}
